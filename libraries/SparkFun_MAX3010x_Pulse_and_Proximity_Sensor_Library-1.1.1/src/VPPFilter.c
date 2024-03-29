#include "VPPFilter.h"

static int filter_taps[VPPFILTER_TAP_NUM] = {
    -171,
    -28,
    -30,
    -31,
    -32,
    -32,
    -33,
    -32,
    -31,
    -30,
    -28,
    -25,
    -22,
    -19,
    -15,
    -10,
    -6,
    -1,
    4,
    9,
    15,
    20,
    25,
    30,
    34,
    38,
    42,
    45,
    47,
    49,
    50,
    51,
    50,
    50,
    48,
    46,
    43,
    40,
    37,
    33,
    30,
    26,
    22,
    19,
    16,
    14,
    12,
    11,
    11,
    13,
    15,
    18,
    23,
    29,
    37,
    45,
    55,
    65,
    77,
    89,
    102,
    115,
    128,
    141,
    154,
    166,
    177,
    186,
    194,
    199,
    203,
    204,
    202,
    197,
    188,
    177,
    162,
    143,
    121,
    95,
    65,
    33,
    -3,
    -41,
    -82,
    -125,
    -170,
    -216,
    -263,
    -309,
    -355,
    -400,
    -444,
    -485,
    -523,
    -558,
    -589,
    -614,
    -635,
    -650,
    -659,
    -662,
    -658,
    -647,
    -630,
    -605,
    -573,
    -535,
    -489,
    -438,
    -381,
    -318,
    -251,
    -180,
    -105,
    -27,
    53,
    133,
    214,
    294,
    373,
    449,
    522,
    591,
    655,
    713,
    765,
    810,
    848,
    878,
    899,
    912,
    917,
    912,
    899,
    878,
    848,
    810,
    765,
    713,
    655,
    591,
    522,
    449,
    373,
    294,
    214,
    133,
    53,
    -27,
    -105,
    -180,
    -251,
    -318,
    -381,
    -438,
    -489,
    -535,
    -573,
    -605,
    -630,
    -647,
    -658,
    -662,
    -659,
    -650,
    -635,
    -614,
    -589,
    -558,
    -523,
    -485,
    -444,
    -400,
    -355,
    -309,
    -263,
    -216,
    -170,
    -125,
    -82,
    -41,
    -3,
    33,
    65,
    95,
    121,
    143,
    162,
    177,
    188,
    197,
    202,
    204,
    203,
    199,
    194,
    186,
    177,
    166,
    154,
    141,
    128,
    115,
    102,
    89,
    77,
    65,
    55,
    45,
    37,
    29,
    23,
    18,
    15,
    13,
    11,
    11,
    12,
    14,
    16,
    19,
    22,
    26,
    30,
    33,
    37,
    40,
    43,
    46,
    48,
    50,
    50,
    51,
    50,
    49,
    47,
    45,
    42,
    38,
    34,
    30,
    25,
    20,
    15,
    9,
    4,
    -1,
    -6,
    -10,
    -15,
    -19,
    -22,
    -25,
    -28,
    -30,
    -31,
    -32,
    -33,
    -32,
    -32,
    -31,
    -30,
    -28,
    -171};

void VPPFilter_init(VPPFilter *f)
{
    int i;
    for (i = 0; i < VPPFILTER_TAP_NUM; ++i)
        f->history[i] = 0;
    f->last_index = 0;
}

void VPPFilter_put(VPPFilter *f, int input)
{
    f->history[f->last_index++] = input;
    if (f->last_index == VPPFILTER_TAP_NUM)
        f->last_index = 0;
}

int VPPFilter_get(VPPFilter *f)
{
    long long acc = 0;
    int index = f->last_index, i;
    for (i = 0; i < VPPFILTER_TAP_NUM; ++i)
    {
        index = index != 0 ? index - 1 : VPPFILTER_TAP_NUM - 1;
        acc += (long long)f->history[index] * filter_taps[i];
    };
    return acc >> 16;
}