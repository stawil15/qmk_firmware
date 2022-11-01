#pragma once

#include "thistle.h"

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
  #include <avr/io.h>
  #include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
  //7 + 10 = 17
  k00, k01, k02, k03, k04, k05, k06,      k08, k09, k10, k11, k12, k13,  k14,    k16, \
  k17,   k19, k20, k21, k22, k23,       k24, k25, k26, k27, k28, k29, k30, k32,  k33, \
  k34,    k36, k37, k38, k39, k40,       k42, k43, k44, k45, k46, k47,   k48,    k50, \
  k52,      k53, k54, k55, k56, k57,   k58, k59, k60, k61, k62, k63,  k64,  k66, k67, \
  k68,  k69,  k71,  k72,     k74,         k75,  k77,  k78,  k79,  k81, k82, k83, k84  \
) \
{ \
    { k00,   k01,   k02,   k03,   k04,   k05,   k06,   KC_NO, KC_NO, KC_NO }, \
    { k17,   KC_NO, k19,   k20,   k21,   k22,   k23,   KC_NO, KC_NO, KC_NO }, \
    { k34,   KC_NO, k36,   k37,   k38,   k39,   k40,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, k53,   k54,   k55,   k56,   k57,   k58,   KC_NO, KC_NO, KC_NO }, \
    { k68,   k69,   KC_NO, k71,   k72,   KC_NO, k74,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, k08,   k09,   k10,   k11,   k12,   k13,   k14,   KC_NO, k16   }, \
    { k24,   k25,   k26,   k27,   k28,   k29,   k30,   KC_NO, k32,   k33   }, \
    { KC_NO, k42,   k43,   k44,   k45,   k46,   k47,   k48,   KC_NO, k41   }, \
    { k58,   k59,   k60,   k61,   k62,   k63,   k64,   KC_NO, k66,   k67   }, \
    { k75,   KC_NO, k77,   k78,   k79,   KC_NO, k81,   k82,   k83,   k84   }  \
}
