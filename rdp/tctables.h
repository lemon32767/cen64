#ifndef _TCTABLES_H
#define _TCTABLES_H
#include <stdint.h>

static const int32_t norm_point_table[64] = {
0x4000,
0x3f04,
0x3e10,
0x3d22,
0x3c3c,
0x3b5d,
0x3a83,
0x39b1,
0x38e4,
0x381c,
0x375a,
0x369d,
0x35e5,
0x3532,
0x3483,
0x33d9,
0x3333,
0x3291,
0x31f4,
0x3159,
0x30c3,
0x3030,
0x2fa1,
0x2f15,
0x2e8c,
0x2e06,
0x2d83,
0x2d03,
0x2c86,
0x2c0b,
0x2b93,
0x2b1e,
0x2aab,
0x2a3a,
0x29cc,
0x2960,
0x28f6,
0x288e,
0x2828,
0x27c4,
0x2762,
0x2702,
0x26a4,
0x2648,
0x25ed,
0x2594,
0x253d,
0x24e7,
0x2492,
0x243f,
0x23ee,
0x239e,
0x234f,
0x2302,
0x22b6,
0x226c,
0x2222,
0x21da,
0x2193,
0x214d,
0x2108,
0x20c5,
0x2082,
0x2041 
};

static const int32_t norm_slope_table[64] = {
0xf03,
0xf0b,
0xf11,
0xf19,
0xf20,
0xf25,
0xf2d,
0xf32,
0xf37,
0xf3d,
0xf42,
0xf47,
0xf4c,
0xf50,
0xf55,
0xf59,
0xf5d,
0xf62,
0xf64,
0xf69,
0xf6c,
0xf70,
0xf73,
0xf76,
0xf79,
0xf7c,
0xf7f,
0xf82,
0xf84,
0xf87,
0xf8a,
0xf8c,
0xf8e,
0xf91,
0xf93,
0xf95,
0xf97,
0xf99,
0xf9b,
0xf9d,
0xf9f,
0xfa1,
0xfa3,
0xfa4,
0xfa6,
0xfa8,
0xfa9,
0xfaa,
0xfac,
0xfae,
0xfaf,
0xfb0,
0xfb2,
0xfb3,
0xfb5,
0xfb5,
0xfb7,
0xfb8,
0xfb9,
0xfba,
0xfbc,
0xfbc,
0xfbe,
0xfbe
};

#endif