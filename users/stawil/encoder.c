
#include "quantum.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();

    if (index == 0) {
        if (mods_state & MOD_BIT(KC_LCTL)) {
            unregister_code(KC_LCTL);
            if (clockwise) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_WH_D);
            }
            register_code(KC_LCTL);
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else if (index == 1) {
        if (mods_state & MOD_BIT(KC_LCTL)) {
            unregister_code(KC_LCTL);
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            register_code(KC_LCTL);
        } else {
            if (clockwise) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_WH_D);
            }
        }
    } else {
        return true;
    }
    return false;
}
