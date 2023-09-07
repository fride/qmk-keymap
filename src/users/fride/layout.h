#pragma once
#include QMK_KEYBOARD_H

enum layers {
    ALPHA,
    NUM,
    SYM,
    MODS,
    FUN,
    NAV
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
  ALFRED
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

#define NAV_R LT(NAV,KC_R)
#define SYM_SPC LT(SYM,KC_SPC)

// special keys
#define MAGIC QK_ALT_REPEAT_KEY
#define REPEAT QK_REPEAT_KEY
// #define REPEAT_SYM LT(SYM, REPEAT)
#define SYM_REP LT(SYM, QK_REP)
#define SYM_MAG LT(SYM, QK_ALT_REPEAT_KEY)


#define NAV_SPC LT(NAV, KC_SPC)
#define ESC_SYM LT(SYM, KC_ESC)
#define CLN_NUM LT(SYM, KC_COLON)

#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH) 


#define ___A___ KC_A
#define ___B___ KC_B
#define ___C___ KC_C
#define ___D___ KC_D
#define ___E___ KC_E
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ KC_H
#define ___I___ KC_I
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ KC_M
#define ___N___ KC_N
#define ___O___ KC_O
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ KC_R
#define ___S___ KC_S
#define ___T___ KC_T
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ KC_X
#define ___Y___ KC_Y
#define ___Z___ KC_Z
#define _COMMA_ KC_COMM
#define __DOT__ KC_DOT
#define _SLASH_ KC_SLSH
#define _SQUOT_ KC_QUOT
#define _DQUOT_ QUOTE_BRACKET
#define _MINUS_ KC_MINS
#define __HASH_ KC_HASH

#define FIVE  LCTL_T(KC_5)
#define THREE LALT_T(KC_3)
#define ONE   LGUI_T(KC_1)
#define ZERO  RGUI_T(KC_0)
#define TWO   RALT_T(KC_2)
#define FOUR  RCTL_T(KC_4)


#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define ___________________________________________ _______, _______, _______, _______, _______

/*
// https://www.reddit.com/r/KeyboardLayouts/comments/y7jkyj/the_hands_down_ive_been_using_lately/?utm_source=share&utm_medium=web2x&context=3
https://www.reddit.com/r/ErgoMechKeyboards/comments/13zj6qz/not_enough_keys/

@  $€ &  |  ~    ^  7  8  9  %    (€ is shift+$)
{  (  )  }  `    +  4  5  6  -    (= is combo +4)
[  <  >  ]  #    *  1  2  3  /\   (\ is shift+/)
ctl  sft  alt    _  0  .

This way, ALL symbols + numbers of a traditional board fit on a single layer
(excl. default layer punctuation)
*/
// clang-format off

// The Bird Layout looks interesting!
/* https://github.com/jcmkk3/bird-layout
 
 x c l f v   z y o u '
 r s n t p   k h e i a
 q w m g b   j d , . /

*/

#define __THUMBS_ OS_LSFT, REPEAT,  SYM_MAG, NAV_SPC

// clang-format off
#define _BASE \
    ___X___, ___C___, ___L___, ___F___, KC_LPRN, KC_RPRN, ___Y___, ___O___, ___U___, _SQUOT_, \
	___R___, ___S___, ___N___, ___T___, ___P___, ___K___, ___H___, ___E___, ___I___, ___A___, \
	___Q___, ___W___, ___M___, ___G___, ___B___, ___J___, ___D___, _COMMA_, __DOT__, _SLASH_, \
	                                        __THUMBS_

// clang-format off
#define _NAV \
	SW_APP,  KC_ESC,  TAB_L,   TAB_R,   _______,     _______, KC_BSPC, KC_UP,   KC_DEL,  KC_Q,     \
	OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, OS_MEH,      FWD,     KC_LEFT, KC_DOWN, KC_RIGHT,BACK,     \
	_______, _______, _______, CPYPASTE,ALFRED,      _______, _______, _______, _______, _______,  \
	                           NAV_SPC, OS_MEH,      REPEAT,  OS_LSFT

// clang-format off
#define _NUM \
	KC_EXLM, KC_AT,   _______, _______, _______,      _______, KC_HASH,KC_AMPR, _______,  _______,   \
	KC_7,    FIVE,    THREE,   ONE,     KC_PLUS,      KC_PAST, ZERO,   TWO,     FOUR,     KC_6,   \
	_______, _______, KC_HASH, KC_9,    KC_PERC,      KC_CIRC, KC_8,   KC_COMM, KC_DOT,   KC_UNDS, \
	                           NAV_SPC, OS_MEH,       REPEAT,  OS_LSFT


// clang-format off
#define _SYM1 \
	  KC_TILD, KC_PLUS, KC_ASTR, KC_EXLM, KC_NO,     KC_NO,   KC_HASH, KC_AT,   KC_CIRC, KC_NO, \
      KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_PIPE,   KC_GRV,  KC_QUES, KC_LBRC, KC_RBRC, KC_NO, \
      KC_NO,   KC_LT,   KC_GT,   KC_PERC, KC_NO,     KC_SLSH, KC_AMPR, KC_LPRN, KC_RPRN, KC_UNDS, \
	                           NAV_SPC, OS_MEH,      REPEAT,  OS_LSFT


#define LAYOUT_FERRIS(...) LAYOUT(__VA_ARGS__) 

// Enable adaptive roles.
#define ADAPTIVE_KEYS_ENABLE
#define ADAPTIVE_TERM (TAPPING_TERM/2) // rol