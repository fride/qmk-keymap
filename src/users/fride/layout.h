#pragma once
#include QMK_KEYBOARD_H

enum layers {
  ALPHA,  
  UTIL,
  NUM,  
  SYM,
  WINNAV,
  FUN,
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

  // TODO remove this stuff
  DI_TH,
  DI_SH,
  DI_CH,
  DI_WH,
  DI_GH,

  // N-Shot Mods
  OS_LSFT,  // OS Mods
  OS_LCTL,  // OS Mods
  OS_LALT,  // OS Mods
  OS_LGUI,  // OS Mods
  TS_LCTL,  // Two-shot ctrl

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
  W_ROTATE2
};


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

// special keys
#define MAGIC QK_ALT_REPEAT_KEY
#define REPEAT QK_REPEAT_KEY
#define MAGIC_GUI LALT_T(QK_ALT_REPEAT_KEY)

#define ESC_SYM LT(SYM,KC_ESC)
#define COLON_SYM LT(SYM,KC_COLON)

#define M_LT LT(UTIL, KC_LT)
#define M_GT LT(NUM,  KC_GT)

// thumb keys!
#define NAV_SPC LT(UTIL, KC_SPC)

#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH)

#define ___A___ RGUI_T(KC_A)
#define ___B___ KC_B
#define ___C___ KC_C
#define ___D___ KC_D
#define ___E___ LT(NUM,KC_E)
#define ___F___ LCTL_T(KC_F)
#define ___G___ KC_G
#define ___H___ RSFT_T(KC_H)
#define ___I___ RCTL_T(KC_I)
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ LALT_T(KC_L)
#define ___M___ KC_M
#define ___N___ LGUI_T(KC_N)
#define ___O___ LALT_T(KC_O)
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ LALT_T(KC_R)
#define ___S___ LCTL_T(KC_S)
#define ___T___ LSFT_T(KC_T)
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ KC_X
#define ___Y___ RCTL_T(KC_Y)
#define ___Z___ KC_Z
#define _COMMA_ KC_COMM
#define __DOT__ KC_DOT
#define _SLASH_ KC_SLSH
#define _SQUOT_ KC_QUOT
#define _DQUOT_ QUOTE_BRACKET
#define _MINUS_ KC_MINS
#define __HASH_ KC_HASH
#define _SEMIC_ KC_SCLN

#define ___0___ RSFT_T(KC_0)
#define ___2___ RGUI_T(KC_2)
#define ___4___ RCTL_T(KC_4)
#define ___6___ LALT_T(KC_6)
#define ___8___ KC_8

#define ___1___ LSFT_T(KC_1)
#define ___3___ LGUI_T(KC_3)
#define ___5___ LCTL_T(KC_5)
#define ___7___ LALT_T(KC_7)
#define ___9___ KC_9

#define _______ KC_TRNS
#define _XXXXX_ KC_NO
#define ___________________________________________ \
  _______, _______, _______, _______, _______


// ----------------

// layout wrappers inspired by https://github.com/pixelbreaker/qmk_userspace

// Layout aliases for json keymap
#define LAYOUT_redox(...) LAYOUT(__VA_ARGS__)

/*
V M L C P "        | B ^ U O , \
S T R D Y Q        $ F N E A I -
X K J G W            Z H ' ? .
        ⎵ ⇥     / @ ⇧
*/

#define _MAGIC_STURDY \
  ___V___ ,___M___ ,___L___ ,___C___ ,___P___   ,___B___ ,MAGIC   ,___U___, ___O___ ,_COMMA_, \
  ___S___ ,___T___ ,___R___ ,___D___ ,___Y___   ,___F___ ,___N___ ,___E___ ,___A___ ,___I___, \
  ___X___ ,___K___ ,___J___ ,___G___ ,___W___   ,___Z___ ,___H___ ,LPAREN  ,RPAREN  ,__DOT__, \
                    NAV_SPC ,OSL(FUN),SPACE_L   ,SPACE_R ,OSL(WINNAV), OS_LSFT

/*
x c l f v   z y o u '
r s n t p   k h e i a
q w m g b   j d , . /
*/
#define _BIRD \
  ___X___ ,___C___ ,___L___ ,___F___ ,___V___   ,___Z___ ,___Y___ ,___O___, ___U___, _COMMA_, \
  ___R___ ,___S___ ,___N___ ,___T___ ,___P___   ,___K___ ,___H___ ,___E___ ,___I___ ,___A___, \
  ___Q___ ,___W___ ,___M___ ,___G___ ,___B___   ,___J___ ,___D___ ,KC_LPRN ,KC_RPRN ,__DOT__, \
                      NAV_SPC,NAV_SPC,SPACE_L   ,SPACE_R,  LT(NUM,KC_E), MAGIC_GUI

/* @ is the magic key!

x c l f v   z y o u '
r s n t p   k h a i @
q w m g b   j d , . /
              e
*/
#define _BIRD_JAN \
  ___X___ ,___C___ ,___L___ ,___F___ ,___V___   ,___Z___ ,___Y___ ,___O___, ___U___ ,_COMMA_, \
  ___R___ ,___S___ ,___N___ ,___T___ ,___P___   ,___K___ ,___H___ ,___A___ ,___I___ ,MAGIC_GUI,   \
  ___Q___ ,___W___ ,___M___ ,___G___ ,___B___   ,___J___ ,___D___ ,LPAREN  ,RPAREN  ,__DOT__, \
                     NAV_SPC,NAV_SPC,SPACE_L   ,SPACE_R,  OS_LSFT, ___E___


#define _UTIL \
  SW_APP,  TAB_L,   TAB_R,   SW_WIN,  KC_NO,               KC_NO, KC_BSPC, KC_UP,   KC_DEL,  KC_NO, \
  OS_LALT, OS_LCTL, OS_LGUI, OS_LSFT, OSM(MOD_MEH),        FWD,   KC_LEFT, KC_DOWN, KC_RGHT, BACK, \
  Z_UND,   Z_CUT,   Z_CPY,   Z_PST,   ALFRED,              KC_NO, KC_ESC,  KC_COLON,KC_NO,   KC_NO, \
                    NAV_SPC, KC_1,    KC_2,                KC_2,  KC_1,    KC_SPC
#define _NUM \
  KC_GRV,      KC_NO,         KC_NO,        KC_NO,        KC_PLUS,      KC_BSLS, KC_HASH,      KC_AMPR,      KC_PIPE,      KC_TILD, \
  LALT_T(KC_7), LCTL_T(KC_5), LGUI_T(KC_3), LSFT_T(KC_1), KC_ASTR,      KC_NO,   RSFT_T(KC_0), RGUI_T(KC_2), RCTL_T(KC_4), LALT_T(KC_6), \
  KC_NO,        KC_COLN,      KC_SCLN,      KC_9,         KC_NO,        KC_NO,   KC_8,         KC_COMM,      KC_DOT,       KC_SLSH, \
                              NAV_SPC,      KC_1,         KC_2,         KC_2,  KC_1,   MAGIC_GUI
#define _WINNAV \
  KC_NO,        W_ROTATE,     WN_NORTH,     W_ROTATE2,    KC_PLUS,      KC_BSLS, MEH(KC_6),    MEH(KC_7),      MEH(KC_8),     KC_TILD, \
  SPACE_L,      WN_WEST,      A(KC_F),      WN_EAST,      SPACE_R,      KC_NO,   MEH(KC_4),    MEH(KC_5),      MEH(KC_6),     LALT_T(KC_6), \
  KC_NO,        KC_NO,        WN_SOUTH,     KC_NO,        KC_NO,        KC_NO,   MEH(KC_1),    MEH(KC_2),      MEH(KC_3),     KC_SLSH, \
                              NAV_SPC,      KC_1,         KC_2,         KC_2,  KC_1,   MAGIC_GUI

#define _FUN \
  KC_NO,        W_ROTATE,     WN_NORTH,     W_ROTATE2,    KC_PLUS,           KC_BSLS, KC_F7,        KC_F8,           KC_F9,      KC_F10, \
  OS_LALT,      OS_LCTL,      OS_LGUI,      OS_LSFT,      OSM(MOD_MEH),      KC_NO,   KC_F4,        KC_F5,           KC_F6,      KC_F11, \
  KC_NO,        KC_NO,        WN_SOUTH,     KC_NO,        KC_NO,             KC_NO,   KC_F1,        KC_F2,           KC_F3,      KC_F12, \
                              KC_NO,        KC_NO,        KC_NO,             KC_2,    KC_1,         MAGIC_GUI


#define CONV_REDOX( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
            k59, k60, k61,        k64, k65, k66 \
) \
     KC_NO   ,KC_7    ,KC_5    ,KC_3    ,KC_1    ,KC_9    ,                                            KC_8    ,KC_0    ,KC_2    ,KC_4    ,KC_6    ,KC_NO   , \
     KC_TAB  ,k15     ,k16     ,k17     ,k18     ,k19     ,KC_NO   ,                          KC_NO   ,k22     ,k23     ,k24     ,k25     ,k26     ,KC_EQL  , \
     KC_Q    ,k29     ,k30     ,k31     ,k32     ,k33     ,KC_LBRC ,                          KC_RBRC ,k36     ,k37     ,k38     ,k39     ,k40 ,    KC_MINS , \
     KC_LSFT ,k43     ,k44     ,k45     ,k46     ,k47     ,KC_NO   ,QK_BOOT ,        QK_BOOT ,KC_NO   ,k50     ,k51     ,k52     ,k53     ,k54     ,KC_RSFT , \
     KC_NO  ,KC_NO   ,KC_NO    ,KC_NO   ,     k59     ,    k60     ,k61     ,        k64     ,k65     ,    k66     ,     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO 

#define REDOX(k) CONV_REDOX(k)
