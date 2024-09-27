#pragma once
#include QMK_KEYBOARD_H

enum layers {
  ALPHA,  
  ALPHA2,
  UTIL,
  NUM,  
  SYM,  
  SYM_LEFT,
  SYM_RIGHT,
  WINNAV,
  FUN,
  ALWAYS
};

// Tap Dance keycodes
enum td_keycodes {
  ALT_LP  // Our example key: `LALT` when held, `(` when tapped. Add additional
          // keycodes for each tapdance.
};

enum custom_keycodes {
  QUOTE = SAFE_RANGE,
  LEADER,
  LLOCK,
  CIRC,
  GRV,
  TILD,
  DELIM,  // on the NUM word layer

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
  CANCEL,  // Cancel SYMWORD and NUMWORD
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
  OS_LSFT,  // OS Mods
  OS_LCTL,  // OS Mods
  OS_LALT,  // OS Mods
  OS_LGUI,  // OS Mods
  TS_LCTL,  // Two-shot ctrl
  // German special nonsense
  A_UML,
  O_UML,
  U_UML,
  SZ,

  // long press umlaut


  ARROW_L,
  ARROW_R,
  QU,
  KC_SCH,

  COPY_PASTE,
  SP_MOD,  // oneshot modifier and tap, nav layer on hold. See 'NAV_MOD'
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
  KC_TH,

  // window management.
  WN_WEST,
  WN_EAST,
  WN_NORTH,
  WN_SOUTH,
  W_ROTATE,
  W_ROTATE2,
  ARROW,
  FARROW
};


#define NAV_SPC LT(UTIL, KC_SPC)


#define META_DEAD LT(UTIL, KC_LGUI)

#define NICE_QU LALT(KC_3)
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


// combo keys
#define ESC_SYM LT(SYM,KC_ESC)
#define CLN_SYM LT(SYM,KC_COLON)


// special keys
#define MAGIC QK_ALT_REPEAT_KEY
#define REPEAT QK_REPEAT_KEY
#define REP_SFT LSFT_T(QK_REPEAT_KEY)
#define ENT_GUI LGUI_T(KC_ENTER)

#define _______ KC_TRNS
#define _XXXXX_ KC_NO
#define ___________________________________________ \
  _______, _______, _______, _______, _______


#ifdef DHORF
#include "layouts/dhorfe.h"
#endif

#ifdef HANDS_DOWN_IE
#include "layouts/hands-down-ie.h"
#endif

#ifdef MAGIC_STURDY
#include "layouts/magic-sturdy.h"
#endif

#ifdef PUQ
#include "layouts/puq.h"
#endif

#ifdef FOCAL
#include "layouts/focali.h"
#endif

#ifdef PROMETH
#include "layouts/hands-down-promethius.h"
#endif

// ----------------
// layout wrappers inspired by https://github.com/pixelbreaker/qmk_userspace

// ikse pfui!
#define _QWERTY \
  KC_Q    ,KC_W    ,KC_E       ,KC_R    ,KC_T         ,KC_Y   , KC_U   ,  KC_I    ,KC_O,    KC_P, \
  KC_A    ,KC_S    ,KC_D       ,KC_F    ,KC_G         ,KC_H   , KC_J   ,  KC_K    ,KC_L   , KC_O, \
  KC_Z    ,KC_X    ,KC_V       ,KC_B    ,KC_B         ,KC_N   , KC_N   ,  KC_M ,   KC_COMM, KC_DOT, \
                    NAV_SPACE  ,OS_LGUI ,_______      ,OS_LALT, OS_LCTL, OS_LSFT

#define _UTIL \
  SW_APP,  TAB_L,   TAB_R,   SW_WIN,  KC_NO,               KC_NO, KC_BSPC, KC_UP,   KC_DEL,  KC_NO, \
  OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, OSM(MOD_MEH),        FWD,   KC_LEFT, KC_DOWN, KC_RGHT, BACK, \
  Z_UND,   Z_CUT,   Z_CPY,   Z_PST,   ALFRED,              KC_NO, KC_ESC,  KC_COLON,KC_NO,   KC_NO, \
                    _______, _______, _______            , _______, _______, _______

#define _NUMWORD \
   KC_GRV   , KC_EQUAL, KC_MINUS, KC_UNDS, KC_PAST      ,KC_BSLS, KC_HASH,  KC_AMPR, KC_PIPE,  _COMMA_, \
   ___7___  , ___5___ , ___3___ , ___1___, KC_PLUS      ,KC_CIRC, ___0___,  ___2___, ___4___,  ___6___ , \
   KC_TILDE , KC_LT   , KC_GT,    ___9___, KC_SLASH     ,KC_AT,   ___8___,  _SEMIC_, KC_COLON, __DOT__, \
                         KC_SPC,  KC_LT  , KC_GT        ,_XXXXX_, _XXXXX_, _XXXXX_
 

/*

#define _SYM \
  KC_GRV  ,KC_LT   ,KC_GT,   KC_AT  , KC_DOT       ,KC_AMPR, ARROW,    KC_LBRC, KC_RBRC, KC_PERC, \
  KC_EXLM ,KC_MINS ,KC_PLUS ,KC_EQL,  KC_HASH      ,KC_PIPE, KC_COLON, KC_LPRN, KC_RPRN, KC_QUES , \
  KC_CIRC ,KC_SLSH ,KC_PAST, KC_CIRC, _______      ,KC_TILD, KC_AMPR,  KC_LCBR, KC_RCBR, KC_AT, \
                    _______, _______, _______      ,_______, _______, _______
*/

#define _WINNAV \
  KC_NO,        W_ROTATE,     WN_NORTH,     W_ROTATE2,    KC_PLUS,      KC_BSLS, MEH(KC_6),    MEH(KC_7),      MEH(KC_8),     KC_TILD, \
  SPACE_L,      WN_WEST,      A(KC_F),      WN_EAST,      SPACE_R,      KC_NO,   MEH(KC_4),    MEH(KC_5),      MEH(KC_6),     LALT_T(KC_6), \
  KC_NO,        KC_NO,        WN_SOUTH,     KC_NO,        KC_NO,        KC_NO,   MEH(KC_1),    MEH(KC_2),      MEH(KC_3),     KC_SLSH, \
                              NAV_SPC,      KC_1,         KC_2,         KC_2,  KC_1,   _______

#define _FUN \
  KC_NO,        W_ROTATE,     WN_NORTH,     W_ROTATE2,    KC_PLUS,           KC_BSLS, KC_F7,        KC_F8,           KC_F9,      KC_F10, \
  OS_LALT,      OS_LCTL,      OS_LGUI,      OS_LSFT,      OSM(MOD_MEH),      KC_NO,   KC_F4,        KC_F5,           KC_F6,      KC_F11, \
  KC_NO,        KC_NO,        WN_SOUTH,     KC_NO,        KC_NO,             KC_NO,   KC_F1,        KC_F2,           KC_F3,      KC_F12, \
                              KC_NO,        KC_NO,        KC_NO,             KC_2,    KC_1,         _______


#define LAYOUT_TOTEM(...) LAYOUT(__VA_ARGS__)
#define TOTEM(k) CONV_TOTEM(k)
#define CONV_TOTEM( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
            k59, k60, k61,        k64, k65, k66 \
) \
        k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
        k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
KC_NO,  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, KC_NO, \
                  k59, k60, k61,        k64, k65, k66

// -------------------------------------------------------------------------------------------------------- //





/*

#define _TEMPLATE_LAYER \
  _______ ,_______, _______, _______, _______      ,_______, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______      ,_______, _______,  _______, _______, _______ , \
  _______ ,_______, _______, _______, _______      ,_______, _______,  _______, _______, _______, \
                    _______, _______, _______      ,_______, _______, _______

*/