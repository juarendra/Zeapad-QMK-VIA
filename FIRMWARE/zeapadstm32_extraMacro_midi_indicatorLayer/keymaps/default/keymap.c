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

#include QMK_KEYBOARD_H
#include "midi.h"
//#include "encoder.c"

extern MidiDevice midi_device;


enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

#define LAYOUT_via( \
    k00, k01, k02, k03, \
    k10, k11, k12, k13,\
    k20, k21, k22, k23,\
    k30, k31, k32, k33\
) \
{ \
    { k00, k01, k02, k03}, \
    { k10, k11, k12, k13}, \
    { k20, k21, k22, k23}, \
    { k30, k31, k32, k33} \
}

enum midi_cc_keycodes_LTRM { MIDI_CC1 = QK_USER_0, MIDI_CC2, MIDI_CC3, MIDI_CC4, MIDI_CC5, MIDI_CC6, MIDI_CC7, MIDI_CC8, MIDI_CC9, MIDI_CC10, MIDI_CC11, MIDI_CC12, MIDI_CC13, MIDI_CC14, MIDI_CC15, MIDI_ENCH1_1, MIDI_ENCH1_2, MIDI_ENCH2_1, MIDI_ENCH2_2, MIDI_ENCH3_1, MIDI_ENCH3_2};
static uint8_t current_MIDI_ccNumber         = 1;
static uint8_t current_MIDI_ccNumber1        = 16;
static uint8_t current_MIDI_ccNumber2        = 31;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ┌───┬───┬───┬───┐
 * │ 7 │ 8 │ 9 │ BS│
 * ├───┼───┬───┼───┤
 * │ 4 │ 5 │ 6 │ESC│
 * ├───┼───┬───┼───┤
 * │ 1 │ 2 │ 3 │TAB│
 * ├───┼───┬───┼───┤
 * │FN │ 0 │ . │RET│
 * └───┴───┴───┴───┘
 */
[_BASE] = LAYOUT_via(
    KC_P7,    LCTL(LSFT(KC_E)),             KC_ENTER,                TO(1),    
    KC_P4,    LCTL(KC_C),                   LCTL(KC_V),              KC_ESC,      
    KC_P1,    LCTL(KC_A),                   KC_Z,                    KC_TAB,       
    KC_P1,    LCTL(KC_Z),                   LCTL(LSFT(KC_Z)),        KC_ENTER
),

/* FN
 * ┌───┬───┬───┬───┐
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * └───┴───┴───┴───┘
 */
[_FN1] = LAYOUT_via(
    KC_TRNS,   KC_TRNS,   KC_TRNS,    TO(2),
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, 
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
),

/* FN
 * ┌───┬───┬───┬───┐
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * └───┴───┴───┴───┘
 */
[_FN2] = LAYOUT_via(
    KC_TRNS,   KC_TRNS,   KC_TRNS,    TO(3),
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, 
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
),

/* FN
 * ┌───┬───┬───┬───┐
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * └───┴───┴───┴───┘
 */
[_FN3] = LAYOUT_via(
    MIDI_CC1,       MIDI_CC2,       MIDI_CC3,       TO(0),   
    MIDI_CC4,       MIDI_CC5,       MIDI_CC6,       MIDI_CC7,  
    MIDI_CC8,       MIDI_CC9,       MIDI_CC10,      MIDI_CC11, 
    MIDI_CC12,      MIDI_CC13,      MIDI_CC14,      MIDI_CC15
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MIDI_CC1:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 1;
                current_MIDI_ccNumber1        = 16;
                current_MIDI_ccNumber2        = 31;
            } else {
            }
            return false;
            break;
        case MIDI_CC2:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 2;
                current_MIDI_ccNumber1        = 17;
                current_MIDI_ccNumber2        = 32;
            } else {
            }
            return false;
            break;
        case MIDI_CC3:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 3;
                current_MIDI_ccNumber1        = 18;
                current_MIDI_ccNumber2        = 33;
            } else {
            }
            return false;
            break;
        case MIDI_CC4:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 4;
                current_MIDI_ccNumber1        = 19;
                current_MIDI_ccNumber2        = 34;
            } else {
            }
            return false;
            break;
        case MIDI_CC5:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 5;
                current_MIDI_ccNumber1        = 20;
                current_MIDI_ccNumber2        = 35;
            } else {
            }
            return false;
            break;
        case MIDI_CC6:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 6;
                current_MIDI_ccNumber1        = 21;
                current_MIDI_ccNumber2        = 36;
            } else {
            }
            return false;
            break;
        case MIDI_CC7:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 7;
                current_MIDI_ccNumber1        = 22;
                current_MIDI_ccNumber2        = 37;
            } else {
            }
            return false;
            break;
        case MIDI_CC8:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 8;
                current_MIDI_ccNumber1        = 23;
                current_MIDI_ccNumber2        = 38;
            } else {
            }
            return false;
            break;
        case MIDI_CC9:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 9;
                current_MIDI_ccNumber1        = 24;
                current_MIDI_ccNumber2        = 39;
            } else {
            }
            return false;
            break;
        case MIDI_CC10:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 10;
                current_MIDI_ccNumber1        = 25;
                current_MIDI_ccNumber2        = 40;
            } else {
            }
            return false;
            break;
        case MIDI_CC11:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 11;
                current_MIDI_ccNumber1        = 26;
                current_MIDI_ccNumber2        = 41;
            } else {
            }
            return false;
            break;
        case MIDI_CC12:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 12;
                current_MIDI_ccNumber1        = 27;
                current_MIDI_ccNumber2        = 42;
            } else {
            }
            return false;
            break;
        case MIDI_CC13:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 13;
                current_MIDI_ccNumber1        = 28;
                current_MIDI_ccNumber2        = 43;
            } else {
            }
            return false;
            break;
        case MIDI_CC14:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 14;
                current_MIDI_ccNumber1        = 29;
                current_MIDI_ccNumber2        = 44;
            } else {
            }
            return false;
            break;
        case MIDI_CC15:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 15;
                current_MIDI_ccNumber1        = 30;
                current_MIDI_ccNumber2        = 45;
            } else {
            }
            return false;
            break;
        case MIDI_ENCH1_1:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 65);
            } else {
            }
            return true;
        case MIDI_ENCH1_2:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 63);
            } else {
            }
            return true;
        case MIDI_ENCH2_1:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber1, 65);
            } else {
            }
            return true;
        case MIDI_ENCH2_2:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber1, 63);
            } else {
            }
            return true;
        case MIDI_ENCH3_1:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber2, 65);
            } else {
            }
            return true;
        case MIDI_ENCH3_2:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber2, 63);
            } else {
            }
            return true;
        default:
            break;
    }
    return true;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_FN1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif


void keyboard_post_init_user(void) {
    rgblight_sethsv(128, 255, 120);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _FN1:
            rgblight_sethsv(43, 255, 120);
            break;
        case _FN2:
            rgblight_sethsv(85, 255, 120);
            break;
        case _FN3:
            rgblight_sethsv(191, 255, 120);
            break;
        case _BASE:
            rgblight_sethsv(128, 255, 120);
            break;
        default: // for any other layers, or the default layer
            rgblight_sethsv(128, 255, 120);
            break;
    }
  return state;
}
