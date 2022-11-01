#include QMK_KEYBOARD_H
#include "emoji.h"
#include "functions.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ctl_L   Opt_L    Cmd_L                                SPACE                               Cmd_R    FN      Ctl_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6,  KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  SCRNSHT,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,   KC_7,  KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,   KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,   KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LOPT, KC_LCMD,                      KC_SPC,                        KC_RCMD, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        QK_BOOT,   DYN_REC_START1,  DYN_REC_START2,  DYN_REC_STOP, XXXXXXX,   WIDETXT,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                   RGB_TOG,
        XXXXXXX,   DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_SAD,   RGB_SAI,   XXXXXXX,                   RGB_MODE_BREATHE,
        XXXXXXX,   X(E_100),        X(E_FIRE),       X(E_OKAY),    X(E_CLAP), X(E_EYES), X(E_GRIM), X(E_THNK), X(E_UGHH),  X(E_SWET), X(E_HART), X(E_SPOK), X(E_ANGL), XXXXXXX,                   RGB_HUI,
        CAPS_WORD, X(E_LMAO),       X(E_ROFL),       X(E_CRYY),    X(E_COOL), X(E_WINK), X(E_KISS), X(E_HRNY), X(E_LOVD),  X(E_GRIN), X(E_ROLL), X(E_TONG),            XXXXXXX,                   RGB_HUD,
        KC_LOCK,                    X(E_PRAY),       X(E_PRTY),    X(E_SKUL), X(E_BEEE), X(E_BBB),  X(E_BUSS), X(E_TRAIN), XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,          RGB_VAI, RGB_MODE_RAINBOW,
        XXXXXXX,   XXXXXXX,         XXXXXXX,                                             XXXXXXX,                                     XXXXXXX,   XXXXXXX,   XXXXXXX,   RGB_MODE_REVERSE, RGB_VAD, RGB_MODE_FORWARD
    )
};
