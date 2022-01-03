#include QMK_KEYBOARD_H

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   1   |   2   |   3   |
 * |-------+-------+-------|
 * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |-------+-------+-------|
 * |  7/0  |   8   | 9/FN  | 7/0 = Dbl Tap 7 for 0  -  9/FN = Hold 9 for FN
 * `-----------------------'
 */
[0] =
LAYOUT(
        KC_1, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9
)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }

    return false;
}

void keyboard_post_init_user(void) {
    // Call the post init code.
    rgblight_enable_noeeprom(); // enables Rgb, without saving settings
    rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
}

static void render_logo(void) {
    static const char PROGMEM
    qmk_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91,
            0x92, 0x93, 0x94,
            0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1,
            0xB2, 0xB3, 0xB4,
            0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1,
            0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {

    render_logo();

    return false;
}
#endif

void suspend_power_down_user(void) {
    // code will run multiple times while keyboard is suspended
    if (rgblight_is_enabled()) {
        rgblight_disable_noeeprom();
    }
}

void suspend_wakeup_init_user(void) {
    // code will run on keyboard wakeup

    if (!rgblight_is_enabled()) {
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
    }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:        //ENC0_SW
            if (active) //ENC0 pressed
            {
                tap_code(KC_MUTE);
            } else //ENC0 released
            {
                //do nothing
            }
            break;

    }
}

