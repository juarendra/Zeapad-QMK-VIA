
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

