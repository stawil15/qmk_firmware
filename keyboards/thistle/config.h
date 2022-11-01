// Copyright 2022 Saeed Tawil (@Saeed Tawil)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define USE_SERIAL

#define EE_HANDS
// 
// #define MATRIX_ROWS 5
// #define MATRIX_COLS 10

// // wiring of each half
// #define MATRIX_ROW_PINS {B5, B4, E6, D7, C6 }
// #define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6, F5, F4, D4, D1 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
