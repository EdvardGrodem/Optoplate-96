clearvars;clc; close all;
%% Set parameters
amp_thresh = 0.05; % Fraction of max intensity threshold for segmenting wells
min_peak_dist = 2; % Minimum number of samples between peaks
num_wells = 48; % Number of wells in each power meter measurements file
unit_scale = 1E6; % Scale intensity values (eg, to convert from W to �W)
units = '�W/cm^2'; % Only sets units labels on figures

%% Specify used input_values in order listed in table LED (if applicable)
input_values = [];
% input_values = repmat(20:20:240,4,1);
% input_values = reshape(input_values',48,1);
% output_intensity = 145.8; % Calculate input value needed to attain this output intensity

%% Load files to analyze
[filenames, path] = uigetfile('.csv','Select files','Multiselect','On');

if ~iscell(filenames)
    filenames = {filenames};
end

nFiles = numel(filenames);

%% Generate 96 well plate map
R = {'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H'};
C = num2cell(1:12);
C = cellfun(@(x) sprintf('%02d',x),C,'UniformOutput',false);
C = string(C);
[c, r] = ndgrid(1:numel(C),1:numel(R));

well_map = [R(r(:)).' C(c(:)).'];
well_map = join(well_map);
well_map = strrep(well_map,' ','');
well_map = reshape(well_map,12,8)';

well_map(1:2:end,:) = flip(well_map(1:2:end,:),2);
well_list = reshape(well_map',96,1);

%% Reconstruct LED intensities from power meter timeseries measurements
close all
measurements = {};
cmap = lines(num_wells);

for f = 1:nFiles
    
    file = filenames{f};
    
    % Search filename for LED, well set, and round info
    if contains(file,'LED')
        LED = regexp(file,'LED01|LED02|LED00','match');
        LED = regexp(LED,'\d*','match');
        LED = str2double(LED{:});
    else
        LED = 0;
    end
    
    well_set = regexp(file,'_WELLS\d*','match');
    well_set = string(regexp(well_set,'\d*','match'));
    well_set = str2double(well_set{:});
    
    if contains(file,'ROUND')
        cal_round = regexp(file,'ROUND\d*_','match');
        cal_round = string(regexp(cal_round,'\d*','match'));
        cal_round = str2double(cal_round{:});
    else
        cal_round = 0;
    end
    
    % Import measurements in file
    opts = detectImportOptions([path file]);
    opts = setvartype(opts, 'char');
    opts.Delimiter = {' ',',',';'};
    
    measurements_raw = readtable([path file],opts);
    nSamples = size(measurements_raw,1);
    
    % Assign measurements to temporary measurements table
    measurements_temp = table();
    measurements_temp.round(1:nSamples,1) = cal_round;
    measurements_temp.LED(1:nSamples,1) = LED;
    measurements_temp.well_set(1:nSamples,1) = well_set;
    measurements_temp.sample(:,1) = (1:nSamples)';
    measurements_temp.intensity_raw(:,1) =  str2double(measurements_raw{:,6});
    
    time = measurements_temp.sample';
    intensity = measurements_temp.intensity_raw;
    
    % Background subtract measurements
    intensity_BG = median(intensity(intensity<amp_thresh*max(intensity)));
    intensity = intensity - intensity_BG;
    
    % Threshold to exclude intensity data from outside wells
    intensity(intensity<amp_thresh*max(intensity)) = nan;
    
    % Create binary intensity signal for peak finding
    npad = 5;
    intensity_binary = zeros(length(intensity) + npad,1); % Zero pad end of binary signal (helps if final measurement is bright)
    intensity_binary(intensity>0) = 1;
    
    % Find and count peaks in masked signal to identify wells
    [pks, locs, width] = findpeaks(intensity_binary,'NPeaks',num_wells,'MinPeakDistance',min_peak_dist); % Find peaks from binary
    locs = locs + round(width/2); % Center peaks
    [val,idx] = min(abs(time-locs));
    well_idx = time(idx)';
    
    % Show warning if incorrect number of wells found
    if numel(pks)~=num_wells
        disp(['Warning: ' num2str(numel(pks)) ' peaks detected'])
    end
    
    intensity_binary = intensity_binary(1:end-npad);
    
    % Calculate intensities for each identified well (excludes outliers)
    for j = 1:num_wells
        intensity_temp = intensity(well_idx==j);
        outliers = intensity_temp(isoutlier(intensity_temp));
        intensity(ismember(intensity,outliers) & well_idx==j) = nan;
    end
    
    % Scale intensity values by unit_scale
    intensity = intensity.*unit_scale;
    
    % Add intensity and well index info to temporary measurements table
    measurements_temp.intensity = intensity;
    measurements_temp.well_idx = well_idx;
    
    % Assign well labels to temporary measurements table
    if well_set==1
        wells_used = well_list(2:2:end);
    elseif well_set==2
        wells_used = well_list(1:2:end);
    end
    
    idx2well = table();
    idx2well.well_idx(1:num_wells,1) = 1:num_wells;
    idx2well.well = wells_used;
    
    measurements_temp = join(measurements_temp,idx2well);
    measurements{f,1} = measurements_temp;
end

% Concatenate and sort all temporary measurements into big table
measurements = vertcat(measurements{:});
measurements = sortrows(measurements,{'LED','well'},{'Ascend','Ascend'});

%% Calculate intensity of each LED
LED = grpstats(measurements,{'well','LED'},{'nanmax'},'DataVars','intensity');
LED.Properties.RowNames={}; LED.GroupCount = [];
idx = contains(LED.Properties.VariableNames,'intensity');
LED.Properties.VariableNames(idx) = {'intensity'};

if cal_round==0 && ~isempty(input_values)
    
    LED.input_values = input_values;
    
elseif cal_round~=0 % Calculate calibration values
    
    % Interleave LED intensities following 96 well layout
    maxCal = 255;
    
    % Format intensities for optoPlate
    intensities(:,1) = LED.intensity(LED.LED==1);
    intensities(:,2) = LED.intensity(LED.LED==2);
    
    % Format intensities for display
    intensities_display(1:2:191) = intensities(:,1);
    intensities_display(2:2:192) = intensities(:,2);
    intensities_display = reshape(intensities_display,24,8)';
    intensities_display = intensities_display;
    
    % Scale intensities by calibration values from previous round (if applicable)
    if cal_round == 1
        intensities_round_1 = intensities;
        save([path 'intensities_round_1'],'intensities_round_1');
        cal_previous = ones([96, 2])*255;
        minIntensity = min(intensities(:));
        a = 1;
    else
        % Load previous values
        cal_previous = load([path 'cal_round_' num2str(cal_round - 1)]);
        cal_previous = cal_previous.cal;
        
        intensities_round_1 = load([path 'intensities_round_1']);
        intensities_round_1 = intensities_round_1.intensities_round_1;
        minIntensity = min(intensities_round_1(:));
        a = 0.6;
    end
    
    % Calculate calibration values
    cal = cal_previous/maxCal - a*(intensities - minIntensity)./intensities_round_1;
    cal = round(cal*maxCal);
    
    cal(cal>255) = 255;
    cal(cal<0) = 0;
    
    % Reformat calibration values for display
    cal_display(1:2:191) = cal(:,1);
    cal_display(2:2:192) = cal(:,2);
    cal_display = reshape(cal_display,24,8)';
    
    % Save calibration values
    save([path 'cal_round_' num2str(cal_round)],'cal');
end


%% Plot
if cal_round==0 && ~isempty(input_values)
    % Plot and fit output intensity vs input values (if applicable)
    clear g; close all; figure('Position',[100 100 1200 800])
    g = gramm('x',LED.input_values,'y',LED.intensity,'subset',~isnan(LED.intensity));
    g.stat_summary('type','std','geom',{'point','black_errorbar'});
    g.set_title('Intensity vs input value');
    g.set_names('x','Input value','y', ['Output intensity (' units ')'  newline 'mean � std']);
    g.set_text_options('font','arial','interpreter','tex')
    g.stat_fit('fun',@(m,x)m*x,'StartPoint',1)
    g.draw(); clc
    
    model = g.results.stat_fit.model;
    m = g.results.stat_fit.model.m;
    
    % Calculate input value needed to attain target output intensity
    syms y(x)
    y(x) = m*x;
    input = round(double(solve(y==output_intensity, x)));
    
    if input<0 || input>255
        disp(['Input = ' num2str(input) ' (out of bounds)'])
    else
        disp(['Input = ' num2str(input)])
    end
    
elseif cal_round==0 && isempty(input_values)
    % Plot LED intensities
    clear g; close all; figure('Position',[100 100 1200 800])
    %     ymax = 1.25*max(LED.intensity);
    ymax = 180
    g = gramm('x',cellstr(LED.well),'y',LED.intensity,...
        'color',cellstr(regexp(LED.well,'[a-zA-Z]*','match')),'subset',~isnan(LED.intensity));
    g.facet_grid(LED.LED,[]);
    g.geom_point();
    g.set_title('LED intensities');
    g.axe_property('XTickLabelRotation',60,'YLim',[0 ymax],'Xlim',[0 97]);
    %     g.set_text_options('font','arial','interpreter','tex');
    %     g.set_names('x','Well','y', ['Intensity (' units ')' newline 'mean � std'],'Row','LED','Color','Row');
    g.draw();
    %     savefig(gcf,[path 'intensities_round_' num2str(cal_round)]);
    
elseif cal_round~=0
    % Create heatmap labels
    clear g; close all; figure('Position',[100 100 1200 800])
    ymax = 1.25*max(LED.intensity);
    %     ymax = 100
    rowlist = 'A':'H';
    column_list = string(cellfun(@(x) sprintf('%02d',x),num2cell(1:12),'UniformOutput',false));
    xlabeldisp(1:2:23) = string(1:12);
    xlabeldisp(2:2:24) = repmat("",1,12);
    
    % Create heatmap of intensities following 96-well layout
    subplot(2,1,1);
    h = heatmap(intensities_display);
    h.YDisplayLabels = cellstr(rowlist(:));
    h.XDisplayLabels = xlabeldisp;
    h.Title = ['Mean LED intensity (' units ')'];
    
    % Create heatmap of calibration values following 96-well layout
    subplot(2,1,2);
    h = heatmap(cal_display);
    h.YDisplayLabels = cellstr(rowlist(:));
    h.XDisplayLabels = xlabeldisp;
    h.Title = ['Calibration values: round ' num2str(cal_round)];
    savefig(gcf,[path 'heatmap_round_' num2str(cal_round)]);
    
    % Plot LED intensities
    clear g; figure
    g = gramm('x',cellstr(LED.well),'y',LED.intensity,...
        'color',cellstr(regexp(LED.well,'[a-zA-Z]*','match')),'subset',~isnan(LED.intensity));
    g.facet_grid(LED.LED,[]);
    g.geom_point();
    g.set_title(['LED intensities: round ' num2str(cal_round)]);
    g.axe_property('XTickLabelRotation',60,'YLim',[0 ymax],'Xlim',[0 97]);
    g.set_text_options('font','arial','interpreter','tex');
    g.set_names('x','Well','y', ['Intensity (' units ')' newline 'mean � std'],'Row','LED','Color','Row');
    g.draw();
    savefig(gcf,[path 'intensities_round_' num2str(cal_round)]);
end

%% Show optoPlate statistics
optoPlate_stats = table();
optoPlate_stats.cal_round = num2str(cal_round);
optoPlate_stats.mean = mean(LED.intensity);
optoPlate_stats.std = std(LED.intensity);
optoPlate_stats.CV = 100*optoPlate_stats.std/optoPlate_stats.mean;
optoPlate_stats.max = max(LED.intensity);
optoPlate_stats.min = min(LED.intensity);

optoPlate_stats

%% Save measurements, calibration values, and statistics
if cal_round~=0
    measurements_out.round = cal_round;
    measurements_out.measurements = measurements;
    measurements_out.LED = LED;
    measurements_out.cal = cal;
    measurements_out.optoPlate = optoPlate_stats;
    
    save([path 'measurements_round_' num2str(cal_round)],'measurements_out');
end

%% Clean up
% clearvars -except input_values output_intensity measurements measurements_raw LED model