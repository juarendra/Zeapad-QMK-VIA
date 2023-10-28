#pragma once

#define MATRIX_ROWS  4
#define MATRIX_COLS  5

// wiring of each half
#define MATRIX_ROW_PINS       { D1, C6, D4, D0 }
#define MATRIX_COL_PINS       { B5, B4, E6, D7, NO_PIN } // A virtual pin is needed for the encoder key matrix in via.

#define DIODE_DIRECTION COL2ROW

#define TAP_CODE_DELAY  10
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define ENCODERS_PAD_A { F4 , F6}
#define ENCODERS_PAD_B { F5 , F7}
#define ENCODER_RESOLUTIONS       { 4 , 4}
/* disable these deprecated features by default */

/* ws2812 RGB LED */
#define RGB_DI_PIN B1 //D3 - underglow C7 - backlight
#define RGBLED_NUM 10    // Number of L

