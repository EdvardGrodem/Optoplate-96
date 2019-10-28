#ifndef _EXPERIMENT_CONFIG_H
#define _EXPERIMENT_CONFIG_H

#define PHASE_NUMB 9
#include "LED.h"

uint8_t intensities[][PHASE_NUMB] = {
	{226,229,20,191,4,20,70,173,81,},
	{109,98,235,135,55,73,71,25,96,},
	{231,128,65,76,154,36,30,29,8,},
	{165,92,219,123,40,82,151,230,192,},
	{87,154,17,203,70,8,209,198,33,},
	{71,160,61,47,198,215,167,56,148,},
	{124,51,64,180,196,124,236,159,57,},
	{13,73,40,235,28,18,165,119,102,},
	{107,30,69,14,5,156,239,184,12,},
	{101,99,151,23,100,229,128,233,41,},
	{156,176,203,221,113,184,198,119,159,},
	{4,159,172,102,226,123,123,232,80,},
	{5,70,253,96,253,67,166,183,183,},
	{203,75,152,213,22,150,202,13,77,},
	{108,219,245,62,193,248,175,153,121,},
	{160,246,249,226,189,194,215,68,82,},
	{87,32,143,54,167,106,106,182,235,},
	{54,192,217,82,112,203,238,112,40,},
	{114,17,249,78,53,157,203,172,55,},
	{24,23,179,32,162,250,81,145,77,},
	{39,227,246,242,101,199,214,195,99,},
	{144,198,160,205,139,63,229,218,150,},
	{185,163,251,99,31,222,202,218,211,},
	{255,7,227,120,39,166,89,25,91,},
	{220,177,132,194,25,119,190,230,25,},
	{34,143,12,50,130,108,237,155,97,},
	{77,239,107,6,60,191,229,187,73,},
	{125,67,176,214,249,223,99,17,150,},
	{245,107,114,90,70,243,80,66,12,},
	{183,164,226,93,42,45,112,86,82,},
	{80,168,84,87,201,58,16,239,15,},
	{230,100,150,83,70,91,161,113,169,},
	{5,111,13,219,210,122,167,65,173,},
	{3,126,103,255,255,75,130,216,147,},
	{132,159,129,80,7,11,127,13,222,},
	{82,97,60,239,42,160,35,40,220,},
	{97,134,248,112,207,229,212,125,196,},
	{242,151,110,52,48,2,216,71,102,},
	{175,42,38,36,23,234,218,91,23,},
	{45,101,103,133,44,106,1,234,110,},
	{22,254,112,65,186,98,150,199,182,},
	{156,92,103,49,212,241,231,153,108,},
	{246,145,223,146,121,151,240,3,71,},
	{87,217,56,208,146,150,170,42,116,},
	{186,125,14,251,18,100,189,177,3,},
	{226,95,47,64,148,120,187,210,202,},
	{129,237,141,57,175,72,221,71,164,},
	{151,16,60,35,205,205,171,107,92,},
	{5,207,175,236,215,148,196,219,100,},
	{0,130,72,78,166,116,159,99,71,},
	{230,13,74,15,24,245,135,218,158,},
	{194,12,53,249,68,98,15,52,216,},
	{98,230,216,139,204,24,87,138,113,},
	{241,82,20,3,183,230,161,69,48,},
	{124,136,229,123,18,195,123,43,75,},
	{141,20,90,85,215,77,85,204,153,},
	{228,131,206,231,179,125,105,126,145,},
	{25,60,214,234,29,44,237,227,251,},
	{123,174,228,177,2,77,140,158,136,},
	{93,42,93,220,11,246,4,124,97,},
	{25,243,94,219,250,78,214,11,222,},
	{29,134,26,22,142,235,15,225,125,},
	{223,210,199,226,8,251,224,165,180,},
	{137,132,236,44,152,1,207,150,72,},
	{44,201,78,238,225,52,138,186,204,},
	{84,212,186,8,204,193,177,127,49,},
	{27,144,33,28,205,229,74,144,5,},
	{107,37,57,78,195,80,5,212,253,},
	{2,215,24,129,213,167,158,172,212,},
	{97,187,31,156,60,199,78,75,226,},
	{122,43,15,206,2,50,182,128,210,},
	{205,89,5,142,60,93,108,162,216,},
	{91,31,65,100,249,85,142,197,141,},
	{152,110,185,245,15,70,145,197,58,},
	{84,65,221,19,221,214,119,197,194,},
	{8,93,146,86,64,144,206,238,213,},
	{18,240,159,80,143,22,63,89,221,},
	{118,24,149,210,37,221,248,24,99,},
	{67,198,213,68,191,157,104,167,116,},
	{215,38,208,23,135,43,162,37,235,},
	{135,141,137,83,141,45,136,60,115,},
	{34,143,107,96,147,218,216,202,38,},
	{157,155,229,248,147,87,225,244,190,},
	{39,171,206,164,112,66,150,79,210,},
	{221,42,83,197,8,9,255,56,170,},
	{130,1,200,3,174,229,246,59,97,},
	{67,46,222,234,55,241,136,214,247,},
	{3,158,249,150,129,39,169,181,149,},
	{165,156,207,226,185,142,177,140,104,},
	{101,185,95,73,27,203,131,154,12,},
	{73,155,197,242,65,106,6,120,161,},
	{72,195,122,42,196,245,60,13,28,},
	{82,25,110,80,252,111,102,101,41,},
	{165,251,200,100,117,141,171,201,104,},
	{79,32,214,114,25,241,246,70,216,},
	{92,43,166,86,133,159,173,236,22,},
};

uint16_t durations[][PHASE_NUMB] = {
	{10,171,146,45,135,243,243,24,197,},
	{187,105,61,142,15,27,96,243,22,},
	{15,198,185,230,49,79,59,3,27,},
	{184,34,198,152,253,3,213,36,242,},
	{31,86,99,68,9,97,143,74,5,},
	{245,82,33,189,237,94,31,40,222,},
	{210,43,235,198,235,57,111,167,255,},
	{207,15,17,243,147,254,48,243,165,},
	{220,12,208,78,224,133,122,115,86,},
	{75,214,201,236,54,91,177,238,110,},
	{175,42,69,129,52,115,205,172,67,},
	{71,220,216,210,150,251,64,191,78,},
	{188,28,34,149,131,162,233,91,109,},
	{14,68,77,122,187,102,133,31,168,},
	{32,121,175,107,89,52,50,53,30,},
	{246,84,216,216,113,238,40,2,214,},
	{164,84,184,55,81,42,49,219,44,},
	{204,58,7,189,83,23,59,14,204,},
	{173,26,177,207,247,212,225,146,235,},
	{86,161,221,56,97,55,113,126,195,},
	{88,250,205,18,170,203,190,128,194,},
	{13,127,193,229,21,129,4,50,95,},
	{251,83,63,48,5,68,68,234,123,},
	{169,38,186,127,120,146,164,68,126,},
	{77,32,127,194,170,159,48,108,244,},
	{15,139,134,229,188,152,219,25,142,},
	{203,58,139,84,172,179,146,178,230,},
	{170,68,162,198,165,165,74,201,74,},
	{75,29,190,67,215,194,65,177,24,},
	{24,131,11,131,9,97,149,239,4,},
	{15,133,249,12,115,202,213,46,105,},
	{123,98,95,244,41,122,247,237,3,},
	{68,220,111,230,234,229,132,160,27,},
	{131,6,3,172,218,219,193,59,134,},
	{85,108,0,104,177,109,56,224,218,},
	{50,245,93,1,219,217,138,121,21,},
	{3,89,54,161,84,51,220,183,84,},
	{183,217,114,182,227,161,252,44,160,},
	{85,17,22,185,105,133,69,185,222,},
	{188,25,21,200,236,58,115,53,27,},
	{242,194,44,128,76,220,169,175,29,},
	{2,12,133,123,3,117,6,196,110,},
	{19,171,160,23,171,27,162,43,78,},
	{92,30,67,191,155,85,89,121,93,},
	{139,102,79,124,255,244,208,247,86,},
	{90,37,39,92,126,126,109,22,196,},
	{133,183,125,57,105,71,86,177,185,},
	{29,22,48,235,198,217,255,191,13,},
	{30,113,56,30,17,127,97,42,205,},
	{37,132,132,140,119,164,98,52,9,},
	{195,23,104,249,7,32,8,57,34,},
	{158,187,35,252,171,228,62,157,108,},
	{25,156,164,148,111,173,48,232,252,},
	{251,105,159,236,161,39,59,240,126,},
	{70,74,240,104,106,119,80,220,142,},
	{25,190,88,69,61,216,144,59,69,},
	{210,131,52,124,9,7,151,53,155,},
	{177,187,239,183,121,150,182,28,208,},
	{5,137,4,210,192,120,197,148,81,},
	{175,142,227,145,181,129,165,49,121,},
	{85,77,229,132,66,240,206,25,252,},
	{87,210,242,166,250,129,231,139,209,},
	{242,110,233,251,112,63,161,153,2,},
	{59,24,136,35,196,11,3,211,213,},
	{217,120,221,162,56,35,37,198,128,},
	{170,41,99,39,13,177,17,146,243,},
	{78,232,151,148,221,213,36,13,224,},
	{250,154,148,92,223,210,70,121,17,},
	{112,13,56,225,144,49,19,48,247,},
	{84,33,135,54,231,108,124,20,246,},
	{42,216,76,149,248,219,184,172,204,},
	{223,242,228,29,183,164,17,198,80,},
	{73,123,170,243,232,217,196,34,169,},
	{127,54,248,75,175,94,98,97,142,},
	{44,246,225,153,5,46,76,139,180,},
	{231,147,242,10,184,162,50,180,227,},
	{25,189,72,30,213,195,196,24,181,},
	{196,75,224,39,243,139,215,212,100,},
	{191,26,41,142,106,84,54,197,186,},
	{193,237,214,3,82,74,29,217,250,},
	{62,219,12,49,228,198,34,91,139,},
	{157,45,118,11,216,136,236,187,100,},
	{235,172,240,35,132,123,117,190,127,},
	{84,143,232,14,173,181,242,245,208,},
	{116,69,75,238,221,25,34,172,106,},
	{147,209,225,41,139,7,152,227,123,},
	{253,94,134,166,39,22,63,35,183,},
	{153,5,191,170,2,166,36,166,84,},
	{42,58,31,51,15,228,187,31,49,},
	{107,214,100,105,71,60,226,8,186,},
	{164,128,103,144,147,193,31,172,217,},
	{205,99,146,37,129,242,230,106,116,},
	{106,130,72,166,159,181,64,125,82,},
	{177,71,35,3,9,90,205,111,36,},
	{225,160,118,177,80,132,88,142,182,},
	{130,152,189,44,141,177,6,180,96,},
};
LED leds[] = {
	LED(intensities[1], durations[1]),
	LED(intensities[2], durations[2]),
	LED(intensities[3], durations[3]),
	LED(intensities[4], durations[4]),
	LED(intensities[5], durations[5]),
	LED(intensities[6], durations[6]),
	LED(intensities[7], durations[7]),
	LED(intensities[8], durations[8]),
	LED(intensities[9], durations[9]),
	LED(intensities[10], durations[10]),
	LED(intensities[11], durations[11]),
	LED(intensities[12], durations[12]),
	LED(intensities[13], durations[13]),
	LED(intensities[14], durations[14]),
	LED(intensities[15], durations[15]),
	LED(intensities[16], durations[16]),
	LED(intensities[17], durations[17]),
	LED(intensities[18], durations[18]),
	LED(intensities[19], durations[19]),
	LED(intensities[20], durations[20]),
	LED(intensities[21], durations[21]),
	LED(intensities[22], durations[22]),
	LED(intensities[23], durations[23]),
	LED(intensities[24], durations[24]),
	LED(intensities[25], durations[25]),
	LED(intensities[26], durations[26]),
	LED(intensities[27], durations[27]),
	LED(intensities[28], durations[28]),
	LED(intensities[29], durations[29]),
	LED(intensities[30], durations[30]),
	LED(intensities[31], durations[31]),
	LED(intensities[32], durations[32]),
	LED(intensities[33], durations[33]),
	LED(intensities[34], durations[34]),
	LED(intensities[35], durations[35]),
	LED(intensities[36], durations[36]),
	LED(intensities[37], durations[37]),
	LED(intensities[38], durations[38]),
	LED(intensities[39], durations[39]),
	LED(intensities[40], durations[40]),
	LED(intensities[41], durations[41]),
	LED(intensities[42], durations[42]),
	LED(intensities[43], durations[43]),
	LED(intensities[44], durations[44]),
	LED(intensities[45], durations[45]),
	LED(intensities[46], durations[46]),
	LED(intensities[47], durations[47]),
	LED(intensities[48], durations[48]),
	LED(intensities[49], durations[49]),
	LED(intensities[50], durations[50]),
	LED(intensities[51], durations[51]),
	LED(intensities[52], durations[52]),
	LED(intensities[53], durations[53]),
	LED(intensities[54], durations[54]),
	LED(intensities[55], durations[55]),
	LED(intensities[56], durations[56]),
	LED(intensities[57], durations[57]),
	LED(intensities[58], durations[58]),
	LED(intensities[59], durations[59]),
	LED(intensities[60], durations[60]),
	LED(intensities[61], durations[61]),
	LED(intensities[62], durations[62]),
	LED(intensities[63], durations[63]),
	LED(intensities[64], durations[64]),
	LED(intensities[65], durations[65]),
	LED(intensities[66], durations[66]),
	LED(intensities[67], durations[67]),
	LED(intensities[68], durations[68]),
	LED(intensities[69], durations[69]),
	LED(intensities[70], durations[70]),
	LED(intensities[71], durations[71]),
	LED(intensities[72], durations[72]),
	LED(intensities[73], durations[73]),
	LED(intensities[74], durations[74]),
	LED(intensities[75], durations[75]),
	LED(intensities[76], durations[76]),
	LED(intensities[77], durations[77]),
	LED(intensities[78], durations[78]),
	LED(intensities[79], durations[79]),
	LED(intensities[80], durations[80]),
	LED(intensities[81], durations[81]),
	LED(intensities[82], durations[82]),
	LED(intensities[83], durations[83]),
	LED(intensities[84], durations[84]),
	LED(intensities[85], durations[85]),
	LED(intensities[86], durations[86]),
	LED(intensities[87], durations[87]),
	LED(intensities[88], durations[88]),
	LED(intensities[89], durations[89]),
	LED(intensities[90], durations[90]),
	LED(intensities[91], durations[91]),
	LED(intensities[92], durations[92]),
	LED(intensities[93], durations[93]),
	LED(intensities[94], durations[94]),
	LED(intensities[95], durations[95]),
	LED(intensities[96], durations[96]),
};

#endif