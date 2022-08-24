/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 alexmarmon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "process_unicode.h"

enum prilik_keycodes {
    _DUMMY = SAFE_RANGE,

    WIDETXT, // w i d e t e x t   f o r   a   w i d e   b o y
    TAUNTXT, // FoR ThE UlTiMaTe sHiTpOsTiNg eXpErIeNcE

    UC_HELP, // URL for QMK unicode help
    UC_SHRG,              // shrug       - ¯\_(ツ)_/¯

};

enum unicode_names {
    E_100, //💯
    E_BBB, //🅱
    E_CLAP, //👏
    E_EYES, //👀
    E_GRIM, //😬
    E_THNK, //🤔
    E_UGHH, //😩
    E_SWET, //😅
    E_ROFL, //🤣
    E_HART, //❤
    E_FIRE, //🔥
    E_LMAO, //😂
    E_HRNY, //😍
    E_PRAY, //🙏
    E_OKAY, //👌
    E_CRYY, //😭
    E_LOVD, //😍
    E_COOL, //😎
    E_GRIN, //😁
    E_WINK, //😉
    E_KISS, //😘
    E_ROLL,
    E_ANGL, //😇
    E_SPOK, //😱
    E_TONG, //
    E_PRTY,
    E_COMM,
    E_SKUL,
    E_PEAC,
    E_BEEE,
    E_TRAIN,
    E_BUSS
};

const uint32_t PROGMEM unicode_map[] = {
    [E_BBB]  = 0x1f171,
    [E_100]  = 0x1F4AF,
    [E_EYES] = 0x1f440,
    [E_CLAP] = 0x1f44f,
    [E_GRIM] = 0x1f62c,
    [E_THNK] = 0x1f914,
    [E_UGHH] = 0x1f629,
    [E_SWET] = 0x1f605,
    [E_LMAO] = 0x1f602,
    [E_HART] = 0x2764,
    [E_FIRE] = 0x1f525,
    [E_ROFL] = 0x1f923,
    [E_HRNY] = 0x1f60d,
    [E_PRAY] = 0x1f64f,
    [E_OKAY] = 0x1f44c,
    [E_CRYY] = 0x1f62d,
    [E_LOVD] = 0x1f970,
    [E_COOL] = 0x1f60e,
    [E_GRIN] = 0x1f601,
    [E_WINK] = 0x1f609,
    [E_KISS] = 0x1f618,
    [E_ROLL] = 0x1f612,
    [E_ANGL] = 0x1f607,
    [E_SPOK] = 0x1f631,
    [E_TONG] = 0x1f61c,
    [E_PRTY] = 0x1f389,
    [E_COMM] = 0x262d,
    [E_SKUL] = 0x2620,
    [E_PEAC] = 0x270c,
    [E_BEEE] = 0x1f41d,
    [E_BUSS] = 0x1f68e,
    [E_TRAIN] = 0x1f682
};

enum prilik_layers {
    _QWERTY,
    _ACTIONS,
    _MEMES,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L    Win_L    Alt_L                                SPACE                               Ct_R     FN      Alt_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC, KC_UP,   KC_END,
        KC_LCTL, KC_LALT,KC_LGUI,                             KC_SPC,                             KC_RALT,   MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
    QK_BOOTLOADER, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP, XXXXXXX, WIDETXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, XXXXXXX,     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,         RGB_TOG,
        XXXXXXX, X(E_100), X(E_FIRE), X(E_OKAY), X(E_CLAP), X(E_EYES), X(E_GRIM), X(E_THNK), X(E_UGHH), X(E_SWET),X(E_HART),X(E_SPOK),X(E_ANGL), RESET,            RGB_VAI,
        CAPS_WORD, X(E_LMAO),X(E_ROFL),X(E_CRYY),X(E_COOL),X(E_WINK),X(E_KISS),X(E_HRNY),X(E_LOVD),X(E_GRIN),X(E_ROLL),X(E_TONG),XXXXXXX,     RGB_VAD,
        KC_LOCK,       X(E_PRAY),X(E_PRTY),X(E_SKUL),X(E_BEEE),X(E_BBB),X(E_BUSS),X(E_TRAIN),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,RGB_SPI, RGB_HUI,
        XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, RGB_MODE_REVERSE, RGB_SPD, RGB_MODE_FORWARD
    ),

};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}

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
