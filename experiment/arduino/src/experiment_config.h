/* This is an automatically generated file.
Generated using ../Matlab/FlashExperiment.m */

#ifndef _EXPERIMENT_CONFIG_H
#define _EXPERIMENT_CONFIG_H

#include "LED.h"
#include <Arduino.h>

#define NUMB_WELL_LEDS 1
#define NUMB_WELLS 96

#define WAIT_FOR_SERIAL

const uint8_t amplitudes[NUMB_WELL_LEDS][96] PROGMEM = {
{
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
},
};

const uint16_t pulseNumbs[NUMB_WELL_LEDS][96] PROGMEM = {
{
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
},
};

const uint16_t pusleStartTimes[NUMB_WELL_LEDS][96] PROGMEM = {
{
    12,    11,    10,     9,     8,     7,     6,     5,     4,     3,     2,     1,    24,    23,    22,    21,    20,    19,    18,    17,    16,    15,    14,    13,    36,    35,    34,    33,    32,    31,    30,    29,    28,    27,    26,    25,    48,    47,    46,    45,    44,    43,    42,    41,    40,    39,    38,    37,    60,    59,    58,    57,    56,    55,    54,    53,    52,    51,    50,    49,    72,    71,    70,    69,    68,    67,    66,    65,    64,    63,    62,    61,    84,    83,    82,    81,    80,    79,    78,    77,    76,    75,    74,    73,    96,    95,    94,    93,    92,    91,    90,    89,    88,    87,    86,    85,
},
};

const uint16_t pulseHighTimes[NUMB_WELL_LEDS][96] PROGMEM = {
{
   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
},
};

const uint16_t pulseLowTimes[NUMB_WELL_LEDS][96] PROGMEM = {
{
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
},
};

const uint16_t subpulseHighTimes[NUMB_WELL_LEDS][96] PROGMEM = {
{
   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
},
};

const uint16_t subpulseLowTimes[NUMB_WELL_LEDS][96] PROGMEM = {
{
   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
},
};

#endif //_EXPERIMENT_CONFIG_H 
