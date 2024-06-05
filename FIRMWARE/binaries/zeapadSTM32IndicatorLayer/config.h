#pragma once

//#include "config_common.h"
#define MATRIX_ROWS  4
#define MATRIX_COLS  4

// wiring of each half
#define MATRIX_ROW_PINS       { A6, A7, B0, B12 }
#define MATRIX_COL_PINS       { A2, A3, A4, A5 } // A virtual pin is needed for the encoder key matrix in via.

//#define MATRIX_ROW_PINS       { A6, A7, B0, C13 }
//#define MATRIX_COL_PINS       { A5, A1, A2, A3, A4, NO_PIN, NO_PIN} // A virtual pin is needed for the encoder key matrix in via.


#define DIODE_DIRECTION COL2ROW

#define TAP_CODE_DELAY  10
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define ENCODERS_PAD_A { B3 , B1}
#define ENCODERS_PAD_B { B4 , A15}
#define ENCODER_RESOLUTIONS       { 4 , 4}
/* disable these deprecated features by default */

/* ws2812 RGB LED */
#define WS2812_DI_PIN B14 //D3 - underglow C7 - backlight
#define RGBLED_NUM 10    // Number of L

