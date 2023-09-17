#pragma once
#include QMK_KEYBOARD_H

enum layers {
    ALPHA,
    ALPHA2,
    NUM,
    SYM,
    UTIL,
    FUN,
};

// Tap Dance keycodes
enum td_keycodes {
    ALT_LP // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};

enum custom_keycodes {
  QUOTE = SAFE_RANGE,
  LEADER,
  LLOCK,
  CIRC,
  GRV,
  TILD,
  DELIM, // on the NUM word layer

  LPAREN,
  RPAREN,

  // Smart caps lock and layers that turn off on certain keys
  CAPSWORD,
  MINS,
  NUMWORD,
  SYMWORD,
  SENTENCE,
  CAMEL,
  KEBAB,

  // Layer management
  CANCEL, // Cancel SYMWORD and NUMWORD
  CLEAR,  // Clear all WORD, one-shots and reset to BASE
  MG_THE,
  MG_ION,
  MG_ON,
  MG_ENT,
  MG_UST,
  MG_MENT,
  MG_VER,
  M_SENTENCE,

  // N-Shot Mods
  OS_LSFT, // OS Mods
  OS_LCTL, // OS Mods
  OS_LALT, // OS Mods
  OS_LGUI, // OS Mods
  TS_LCTL, // Two-shot ctrl

  // used below in the thumb
  NEXTSEN,

  // German special nonsense
  A_UML,
  O_UML,
  U_UML,
  SZ,

  ARROW_L,
  ARROW_R,  
  QU,
  KC_SCH,

  COPY_PASTE,
  SP_MOD, // oneshot modifier and tap, nav layer on hold. See 'NAV_MOD'
  SP_SFT,
  CPYPASTE,

  SW_APP,
  SW_WIN,
  MOUSE_TGL,
  SLASH,
  UNDER,
  ALFRED,

  // lates stuff
  QUOTE_BRACKET,
  KC_PH,
  KC_TH
};

// macOS shortcuts
#define Z_UND G(KC_Z)
#define Z_CUT G(KC_X)
#define Z_CPY G(KC_C)
#define Z_PST G(KC_V)
#define Z_RDO S(G(KC_Z))
#define Z_LOCK C(G(KC_Q))
#define Z_SLEEP S(C(KC_EJCT))
#define Z_SHUT C(A(G(KC_PWR)))
#define Z_SSHT G(S(KC_4))
#define Z_SRCD G(S(KC_5))
#define Z_VSML A(KC_LSFT)
#define Z_HASH A(KC_3)
#define Z_AT S(KC_2)
#define EURO S(A(KC_2))
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))

// special keys
#define MAGIC       QK_ALT_REPEAT_KEY
#define REPEAT      QK_REPEAT_KEY
#define ESC_SYM     LT(SYM,KC_ESC)
#define COLON_SYM   LT(SYM,KC_COLON)

// thumb keys!
#define NAV_SPC LT(UTIL, KC_SPC)
#define SYM_SPC LT(SYM,  KC_SPC)
#define SYM_REP LT(SYM,  QK_REP)


#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH) 

#define ___A___ LALT_T(KC_A)
#define ___B___ KC_B
#define ___C___ KC_C
#define ___D___ LSFT_T(KC_D)
#define ___E___ RGUI_T(KC_E)
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ KC_H
#define ___I___ RCTL_T(KC_I)
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ RALT_T(KC_M)
#define ___N___ RSFT_T(KC_N)
#define ___O___ RALT_T(KC_O)
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ LGUI_T(KC_R)
#define ___S___ LCTL_T(KC_S)
#define ___T___ LALT_T(KC_T)
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ KC_X
#define ___Y___ LT(NUM,KC_Y)
#define ___Z___ KC_Z
#define _COMMA_ KC_COMM
#define __DOT__ KC_DOT
#define _SLASH_ KC_SLSH
#define _SQUOT_ KC_QUOT
#define _DQUOT_ QUOTE_BRACKET
#define _MINUS_ KC_MINS
#define __HASH_ KC_HASH
#define _SEMIC_ KC_SCLN


#define ___0___ KC_0
#define ___1___ KC_1
#define ___2___ KC_2
#define ___3___ KC_3
#define ___4___ KC_4
#define ___5___ KC_5
#define ___6___ KC_6
#define ___7___ KC_7
#define ___8___ KC_8
#define ___9___ KC_9


#define _______ KC_TRNS
#define _XXXXX_ KC_NO
#define ___________________________________________ _______, _______, _______, _______, _______

/*
// https://www.reddit.com/r/KeyboardLayouts/comments/y7jkyj/the_hands_down_ive_been_using_lately/?utm_source=share&utm_medium=web2x&context=3
https://www.reddit.com/r/ErgoMechKeyboards/comments/13zj6qz/not_enough_keys/


This way, ALL symbols + numbers of a traditional board fit on a single layer
(excl. default layer punctuation)
*/
// clang-format off


#define __THUMBS_ ___R___, MAGIC, REPEAT, MAGIC, OS_LSFT, NAV_SPC

#define _________________BIRD__L1__________________ ___X___, ___C___, ___L___, ___F___, _SLASH_
#define _________________BIRD__L2__________________ ___Z___,   ___S___, ___N___, ___T___, ___P___
#define _________________BIRD__L3__________________ _COMMA_, ___W___, ___M___, ___G___, ___B___

#define _________________BIRD__R1__________________ _SQUOT_, ___Y___, ___O___, ___U___, __DOT__
#define _________________BIRD__R2__________________ ___K___, ___H___, ___E___, ___I___, ___A___
#define _________________BIRD__R3__________________ ___J___, ___D___, KC_LPRN, KC_RPRN, KC_UNDS

#define BIRD _________________BIRD__L1__________________, _________________BIRD__R1__________________,\
             _________________BIRD__L2__________________, _________________BIRD__R2__________________,\
             _________________BIRD__L3__________________, _________________BIRD__R3__________________,\
                                                      __THUMBS_

#define _________________GERM__L1__________________ _______, _______, _______, _______, SZ
#define _________________GERM__L2__________________ _______, _______, _______, _______, _______
#define _________________GERM__L3__________________ _______, _______, _______, _______, _______
#define _________________GERM__R1__________________ _______, _______, _______, _______, _______
#define _________________GERM__R2__________________ _______, _______, _______, _______, _______
#define _________________GERM__R3__________________ _______, _______, O_UML, A_UML, U_UML


#define _______________NUMBERS___L1________________ _______, KC_EQL,  KC_PLUS, KC_MINS, _XXXXX_
#define _______________NUMBERS___L2________________ ___7___, ___5___, ___3___, ___1___, KC_PLUS
#define _______________NUMBERS___L3________________ _______, _XXXXX_, _XXXXX_, ___9___, KC_PAST

#define _______________NUMBERS___R1________________ _XXXXX_, ___7___, ___8___, ___9___, _COMMA_
#define _______________NUMBERS___R2________________ _XXXXX_, ___0___, ___2___, ___4___, ___6___
#define _______________NUMBERS___R3________________ _XXXXX_, ___8___, _SQUOT_, _SLASH_, __DOT__


#define ________________SYMBOLS_L1_________________ KC_TILD, KC_PLUS,  KC_PAST, KC_EXLM, _SLASH_
#define ________________SYMBOLS_L2_________________ MAGIC,   KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS
#define ________________SYMBOLS_L3_________________ _COMMA_, KC_LT,   KC_GT,   KC_PERC ,KC_NO

#define ________________SYMBOLS_R1_________________ _______, KC_HASH, KC_AT,   KC_CIRC, __DOT__
#define ________________SYMBOLS_R2_________________ KC_GRV,  KC_QUES, KC_LBRC, KC_RBRC, KC_PIPE
#define ________________SYMBOLS_R3_________________ KC_SLSH, KC_AMPR, KC_LPRN, KC_RPRN, KC_UNDS

#define ________________UTILITY_L1________________ SW_APP,  BACK,    TAB_L,   TAB_R,   FWD
#define ________________UTILITY_L2________________ OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, OS_MEH
#define ________________UTILITY_L3________________ Z_UND  , Z_CUT,   Z_CPY  , Z_PST   ,ALFRED

#define ________________UTILITY_R1________________ _______, KC_BSPC, KC_UP,   KC_DEL,  KC_Q
#define ________________UTILITY_R2________________ FWD,     KC_LEFT, KC_DOWN, KC_RIGHT,BACK
#define ________________UTILITY_R3________________ _______, _______,  _______, _______, _______

#define UTILITY \
    ________________UTILITY_L1________________, ________________UTILITY_R1________________,\
    ________________UTILITY_L2________________, ________________UTILITY_R2________________,\
    ________________UTILITY_L3________________, ________________UTILITY_R3________________,\
                                          __THUMBS_

#define ______________MAGICSTURDY_L1_______________ ___V___, ___M___, ___L___, ___C___, ___Q___
#define ______________MAGICSTURDY_L2_______________ ___S___, ___T___, ___R___, ___D___, ___P___
#define ______________MAGICSTURDY_L3_______________ ___X___, ___K___, ___J___, ___G___, ___W___

#define ______________MAGICSTURDY_R1_______________ ___Z___, MAGIC,   ___U___, ___O___, _COMMA_
#define ______________MAGICSTURDY_R2_______________ ___F___, ___N___, ___E___, ___A___, ___I___
#define ______________MAGICSTURDY_R3_______________ ___B___, ___H___, _SQUOT_, _SLASH_, __DOT__


#define LAYOUT_FERRIS(...) LAYOUT(__VA_ARGS__) 
