/* Copyright 2024 Juarendra Ramadhani <jrjuarendra@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

//#include "config_common.h"
#define MATRIX_ROWS  4
#define MATRIX_COLS  4

#define WEAR_LEVELING_LOGICAL_SIZE 4096
#define WEAR_LEVELING_BACKING_SIZE 8192
#define DYNAMIC_KEYMAP_MACRO_COUNT 32
#define DYNAMIC_KEYMAP_LAYER_COUNT 7


#define MIDI_ADVANCED

// wiring of each half
#define MATRIX_ROW_PINS       { A6, A7, B0, B12 }
#define MATRIX_COL_PINS       { A2, A3, A4, A5 } // A virtual pin is needed for the encoder key matrix in via.

//#define MATRIX_ROW_PINS       { A6, A7, B0, C13 }
//#define MATRIX_COL_PINS       { A5, A1, A2, A3, A4, NO_PIN, NO_PIN} // A virtual pin is needed for the encoder key matrix in via.


#define DIODE_DIRECTION COL2ROW

#define TAP_CODE_DELAY  10
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define ENCODERS_PAD_A { B4 , A15}
#define ENCODERS_PAD_B { B3 , B1}
#define ENCODER_RESOLUTIONS       { 4 , 4}
/* disable these deprecated features by default */

/* ws2812 RGB LED */
#define WS2812_DI_PIN B14 //D3 - underglow C7 - backlight
#define RGBLED_NUM 10    // Number of L
