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
#ifdef ENCODER_ENABLE
    static uint8_t encoder_state[2] = {0};
    //Use these keymap positions to specify the encoder functions on rotate.
    static keypos_t encoder_ccw[2] = {{4, 0}, {4, 2}};
    static keypos_t encoder_cw[2] = {{4, 1}, {4, 3}};

    void encoder_action_unregister(void) {
        for (int index = 0; index < 2; ++index) {
            if (encoder_state[index]) {
                keyevent_t encoder_event = (keyevent_t){.key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index], .pressed = false, .time = (timer_read() | 1)};
                encoder_state[index] = 0;
                action_exec(encoder_event);
            }
        }
    }

    void encoder_action_register(uint8_t index, bool clockwise) {
        keyevent_t encoder_event = (keyevent_t){.key = clockwise ? encoder_cw[index] : encoder_ccw[index], .pressed = true, .time = (timer_read() | 1)};
        encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
        action_exec(encoder_event);
    }

    void matrix_scan_user(void) { encoder_action_unregister(); }

    bool encoder_update_user(uint8_t index, bool clockwise) {
        encoder_action_register(index, clockwise);
        return false;
    };
#endif

