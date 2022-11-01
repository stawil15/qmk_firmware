/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    //    LAYER_POINTER,
    LAYER_CONFIG,
    LAYER_GAMING,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define CONFIG MO(LAYER_CONFIG)
#define BASE TO(LAYER_BASE)
// #define POINT TG(LAYER_POINTER)
// #define POINTING MO(LAYER_POINTER)
#define GAMING TG(LAYER_GAMING)

enum macros {
    DESK_LEFT = SAFE_RANGE,
    DESK_RIGHT,
    SCREENSHOT,
    SPOTLIGHT,
    R_BRACE,
    L_BRACE,
    //    UNDO,
    //    CUT,
    //    COPY,
    //    PASTE,
};

enum tapdance {
    //    POINTER_TOGGLE,
    //    POINTER_OFF,
    SLASH_SCROLL,
    HIGH_CLICK,
    LOW_CLICK,
    DOT_SNIPE,
};

enum tap_actions { SINGLE_TAP = 1, SINGLE_HOLD = 2, DOUBLE_TAP = 3, DOUBLE_HOLD = 4 };

typedef struct {
    bool is_press_action;
    int  state;
} tap;

// instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {.is_press_action = true, .state = 0};

int cur_dance(qk_tap_dance_state_t *state);

// for the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

/** \brief Automatically enable sniping-mode on the pointer layer. */
// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  TD(DOT_SNIPE), TD(SLASH_SCROLL), KC_RCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LALT,  KC_SPC, KC_BSPC,     KC_DEL,  KC_ENT,
                                     KC_LGUI, TD(LOW_CLICK),     TD(HIGH_CLICK)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX,   KC_UP, XXXXXXX, L_BRACE, R_BRACE,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,      KC_P0, _______,
                                           _______, _______,     CONFIG
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SCREENSHOT, KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,     KC_EQL, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, L_BRACE,    R_BRACE, KC_F3, DESK_LEFT, DESK_RIGHT, XXXXXXX, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,SPOTLIGHT,_______,    _______, _______,
                                            _______, CONFIG,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

//  [LAYER_POINTER] = LAYOUT_charybdis_4x6(
//  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
//  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//       _______, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SCREENSHOT, KC_VOLD,
//  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//       _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, SPOTLIGHT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//       _______,    UNDO,     CUT,    COPY,   PASTE, XXXXXXX,    DESK_LEFT, DESK_RIGHT, XXXXXXX, SNIPING, DRGSCRL, TD(POINTER_OFF),
//  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                                  SNIPING, KC_BTN1, KC_BTN2,    KC_BTN1, KC_BTN2,
//                                      DESK_LEFT, DESK_RIGHT,    KC_F3
//  //                            ╰───────────────────────────╯ ╰──────────────────╯
//  ),

  [LAYER_GAMING] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
          BASE, _______, _______, _______, _______, _______,    _______, _______, _______, _______,  XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX,  XXXXXXX, KC_VOLD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,  _______,   XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,  XXXXXXX, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    XXXXXXX, XXXXXXX, XXXXXXX, SNIPING,  DRGSCRL, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    KC_BTN3, KC_BTN2,
                                           _______,  KC_ENT,    KC_BTN1
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_CONFIG] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
          BASE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    EEP_RST, QK_BOOT, XXXXXXX, XXXXXXX,  S_D_MOD,  DPI_MOD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S_D_RMOD, DPI_RMOD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  GAMING,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

};

// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb_red();
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DESK_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTL);
            }
            return false;
        case DESK_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_RGHT);
                unregister_code(KC_LCTL);
            }
            return false;
        case SCREENSHOT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_4);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            return false;
        case SPOTLIGHT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
                //                layer_off(LAYER_POINTER);
            }
            return false;
        case R_BRACE:
            if (record->event.pressed) {
                SEND_STRING("}");
            }
            return false;
        case L_BRACE:
            if (record->event.pressed) {
                SEND_STRING("{");
            }
            return false;
            //        case UNDO:
            //            if (record->event.pressed) {
            //                register_code(KC_LGUI);
            //                tap_code(KC_Z);
            //                unregister_code(KC_LGUI);
            //            }
            //            return false;
            //        case CUT:
            //            if (record->event.pressed) {
            //                register_code(KC_LGUI);
            //                tap_code(KC_X);
            //                unregister_code(KC_LGUI);
            //            }
            //            return false;
            //        case COPY:
            //            if (record->event.pressed) {
            //                register_code(KC_LGUI);
            //                tap_code(KC_C);
            //                unregister_code(KC_LGUI);
            //            }
            //            return false;
            //        case PASTE:
            //            if (record->event.pressed) {
            //                register_code(KC_LGUI);
            //                tap_code(KC_V);
            //                unregister_code(KC_LGUI);
            //            }
            //            return false;
    }
    return true;
};

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else {
        if (state->interrupted || !state->pressed)
            return DOUBLE_TAP;
        else
            return DOUBLE_HOLD;
    }
}

// void toggle_finishes(qk_tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     switch (xtap_state.state) {
//         case SINGLE_TAP:
//             layer_on(LAYER_POINTER);
//             break;
//         case SINGLE_HOLD:
//             layer_on(LAYER_POINTER);
//             break;
//         case DOUBLE_TAP:
//             layer_off(LAYER_POINTER);
//             break;
//     }
// }
//
// void toggle_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (xtap_state.state) {
//         case SINGLE_HOLD:
//             layer_off(LAYER_POINTER);
//             break;
//     }
//     xtap_state.state = 0;
// }

// void pointer_finishes(qk_tap_dance_state_t *state, void *user_data) {
//     // do nothing
// }
//
// void pointer_toggle_reset(qk_tap_dance_state_t *state, void *user_data) {
//     layer_off(LAYER_POINTER);
// }

void slashscroll_finishes(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_SLSH);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
            charybdis_set_pointer_dragscroll_enabled(true);
            break;
        case DOUBLE_TAP:
            tap_code(KC_SLSH);
            tap_code(KC_SLSH);
            break;
    }
}

void slashscroll_reset(qk_tap_dance_state_t *state, void *user_data) {
    charybdis_set_pointer_dragscroll_enabled(false);
}

void dotsnipe_finishes(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_DOT);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
            charybdis_set_pointer_sniping_enabled(true);
            break;
        case DOUBLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
    }
}

void dotsnipe_reset(qk_tap_dance_state_t *state, void *user_data) {
    charybdis_set_pointer_sniping_enabled(false);
}

void click_raise_finishes(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_MS_BTN1);
            break;
        case SINGLE_HOLD:
            register_code(KC_MS_BTN1);
            break;
        case DOUBLE_HOLD:
            layer_on(LAYER_RAISE);
            break;
        case DOUBLE_TAP:
            tap_code(KC_MS_BTN1);
            tap_code(KC_MS_BTN1);
            break;
    }
}

void click_raise_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_MS_BTN1);
    layer_off(LAYER_RAISE);
}

void click_lower_finishes(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_MS_BTN2);
            break;
        case SINGLE_HOLD:
            register_code(KC_MS_BTN2);
            break;
        case DOUBLE_HOLD:
            layer_on(LAYER_LOWER);
            break;
        case DOUBLE_TAP:
            tap_code(KC_MS_BTN2);
            tap_code(KC_MS_BTN2);
            break;
    }
}

void click_lower_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_MS_BTN2);
    layer_off(LAYER_LOWER);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    //    [POINTER_TOGGLE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, toggle_finishes, toggle_reset),           // toggle pointer layer on tap, momentary layer on hold
    //    [POINTER_OFF]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pointer_finishes, pointer_toggle_reset),  // multiple taps to pointer layer button will always disable pointer layer.
    [SLASH_SCROLL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slashscroll_finishes, slashscroll_reset), // holding down "/|?" key momentarily engage drag scrolling on base layer.
    [HIGH_CLICK]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, click_raise_finishes, click_raise_reset), // tapping raise works as left click on base layer
    [LOW_CLICK]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, click_lower_finishes, click_lower_reset), // tapping lower works as right click on base layer
    [DOT_SNIPE]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dotsnipe_finishes, dotsnipe_reset), //Holding ".|>" momentarily engages sniping mode on base layer
};
