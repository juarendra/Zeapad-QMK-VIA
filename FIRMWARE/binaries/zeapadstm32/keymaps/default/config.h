
#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL+2

// Disabling some of these is a good way to save flash space.
#    define RGBLIGHT_EFFECT_ALTERNATING     // 108
#    define RGBLIGHT_EFFECT_RGB_TEST        // 158
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD    // 160
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT // 168
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // 192
#    define RGBLIGHT_EFFECT_BREATHING       // 348
#    define RGBLIGHT_EFFECT_KNIGHT          // 336
#    define RGBLIGHT_EFFECT_SNAKE           // 406
#    define RGBLIGHT_EFFECT_CHRISTMAS       // 508
/*
#define RGBLIGHT_EFFECT_TWINKLE         // 1156
*/
#endif