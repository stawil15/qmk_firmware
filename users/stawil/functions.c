
#include "quantum.h"
#include "functions.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static struct {
        bool on;
        bool first;
    } w_i_d_e_t_e_x_t = {false, false};

    if (w_i_d_e_t_e_x_t.on) {
        if (record->event.pressed) {
            switch (keycode) {
                case KC_A...KC_0:
                case KC_MINUS...KC_SLASH:
                case KC_SPC:
                    if (w_i_d_e_t_e_x_t.first) {
                        w_i_d_e_t_e_x_t.first = false;
                    } else {
                        send_char(' ');
                    }
                    break;
                case KC_ENT:
                    w_i_d_e_t_e_x_t.first = true;
                    break;
                case KC_BSPC:
                    send_char('\b'); // backspace
                    break;
            }
        }
    }

    static bool tAuNtTeXt = false;

    if (tAuNtTeXt) {
        if (record->event.pressed) {
            if (keycode != KC_SPC) {
            register_code(KC_CAPS);
            unregister_code(KC_CAPS);
            }
        }
    }

    switch (keycode) {
        /* z e s t y   m e m e s */
        case WIDETXT:
            if (record->event.pressed) {
                w_i_d_e_t_e_x_t.on = !w_i_d_e_t_e_x_t.on;
                w_i_d_e_t_e_x_t.first = true;
            }
            return false;
        case TAUNTXT:
            if (record->event.pressed) {
                tAuNtTeXt = !tAuNtTeXt;
                // when it's turned on, toggle caps lock (makes first letter lowercase)
                if (tAuNtTeXt) {
                    register_code(KC_CAPS);
                    unregister_code(KC_CAPS);
                }
            }
            return false;

        /* Unicode */
        case UC_HELP:
            if (record->event.pressed) {
                SEND_STRING("https://beta.docs.qmk.fm/using-qmk/software-features/feature_unicode");
            }
            return false;
        case UC_SHRG: // ¯\_(ツ)_/¯
            if (record->event.pressed) {
                send_unicode_string("0x00AF 0x005C 0x005F 0x0028 0x30C4 0x0029 0x005F 0x002F 0x00AF");
            }
            return false;

        default:
            return true; //Process all other keycodes normally
    }
}
