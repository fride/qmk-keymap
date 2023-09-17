/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀  D E F A U L T

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"
#include "totem.h"

#define TOTEM(k) CONV_TOTEM(k)
#define CONV_TOTEM( \
         L00, L01, L02, L03, L04,    R00, R01, R02, R03, R04, \
         L10, L11, L12, L13, L14,    R10, R11, R12, R13, R14, \
         L20, L21, L22, L23, L24,    R20, R21, R22, R23, R24, \
                   L32, L33, L34,    R30, R31,R32 \
    )                                        \
    {                                        \
        { L00,    L01,   L02,   L03,   L04 }, \
        { L10,    L11,   L12,   L13,   L14 }, \
        { L20,    L21,   L22,   L23,   L24 }, \
        { KC_NO,  KC_NO, L32,   L33,   L34 }, \
        { R04,    R03,   R02,   R01,   R00 }, \
        { R14,    R13,   R12,   R11,   R10 }, \
        { R24,    R23,   R22,   R21,   R20 }, \
        { KC_NO,  KC_NO, R32,   R31,   R30 }, \
    }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [ALPHA] = TOTEM(BIRD),
//   [ALPHA]  = TOTEM(_MAGIC_STURDY),
//   [SYM]    = TOTEM(_SYM),
//   [ACCENT]    = TOTEM(_ACCENT),
//   [NUM]    = TOTEM(_NUM),
   [UTIL]   = TOTEM(UTILITY)
};