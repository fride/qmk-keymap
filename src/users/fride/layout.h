#pragma once
#include QMK_KEYBOARD_H

enum layers {
  ALPHA,  
  UTIL,
  NUM,  
  NUM2,  
  SYM,
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
  W_ROTATE2,

  BI_PH,
};


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

// special keys
#define MAGIC QK_ALT_REPEAT_KEY
#define REPEAT QK_REPEAT_KEY
#define REP_SFT LSFT_T(QK_REPEAT_KEY)
#define ENT_GUI LGUI_T(KC_ENTER)

#define ESC_SYM LT(SYM,KC_ESC)
#define COLON_SYM LT(SYM,KC_COLON)

#define M_LT LT(NUM, KC_LT)
#define M_GT LT(SYM, KC_GT)

// thumb keys!
#define NAV_SPC LT(UTIL, KC_SPC)
#define MEH_SPC MEH_T(KC_SPC)
#define NUM_QUO LT(NUM, KC_QUOT)
#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH)
#define UM_CTL LCTL_T(KC_U)

// Home row - how to do!? shift gui alt ctrl

#define ___A___ RGUI_T(KC_A)
#define ___B___ KC_B
#define ___C___ RSFT_T(KC_C)
#define ___D___ KC_D
#define ___E___ LT(NUM,KC_E)
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ KC_H
#define ___I___ LALT_T(KC_I)
#define ___J___ KC_J
#define ___K___ MEH_T(KC_K)
#define ___L___ RALT_T(KC_L)
#define ___M___ KC_M
#define ___N___ LGUI_T(KC_N)
#define ___O___ MEH_T(KC_O)
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ LALT_T(KC_R)
#define ___S___ LCTL_T(KC_S)
#define ___T___ LSFT_T(KC_T)
#define ___U___ RALT_T(KC_U)
#define ___V___ KC_V
#define ___W___ HYPR_T(KC_W)
#define ___X___ KC_X
#define ___Y___ HYPR_T(KC_Y)
#define ___Z___ KC_Z
#define _MAGIC_ RCTL_T(MAGIC)
#define _COMMA_ KC_COMM
#define __DOT__ KC_DOT
#define _SLASH_ KC_SLSH
#define _SQUOT_ KC_QUOT
#define _DQUOT_ KC_DQUO
#define _MINUS_ KC_MINS
#define __HASH_ KC_HASH
#define _SEMIC_ KC_SCLN
#define _QUEST_ KC_QUES

#define ___0___ RSFT_T(KC_0)
#define ___2___ RGUI_T(KC_2)
#define ___4___ LALT_T(KC_4)
#define ___6___ RCTL_T(KC_6)
#define ___8___ KC_8

#define ___1___ LSFT_T(KC_1)
#define ___3___ LGUI_T(KC_3)
#define ___5___ LALT_T(KC_5)
#define ___7___ LCTL_T(KC_7)
#define ___9___ KC_9

#define _______ KC_TRNS
#define _XXXXX_ KC_NO
#define ___________________________________________ \
  _______, _______, _______, _______, _______


// ----------------
// layout wrappers inspired by https://github.com/pixelbreaker/qmk_userspace

#define _DHORF_E \
  ___V___, ___L___, ___H___, ___K___, ___Q___,      ___J___, ___F___, ___O___, ___U___, _COMMA_, \
  ___S___, ___R___, ___N___, ___T___, ___W___,      ___Y___, ___C___, ___A___, ___I___, _MAGIC_, \
  ___Z___, ___X___, ___M___, ___D___, ___B___,      ___P___, ___G___, _SQUOT_, _SEMIC_, __DOT__, \
                    NAV_SPC, OS_LSFT, SPACE_L,      KC_BSLS, OS_LSFT, ___E___


/*
See https://www.reddit.com/r/KeyboardLayouts/comments/1ej6q9n/comment/lgcvjp5/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button - but forfe is fine!/
v g l þ *  * u o p z
c s n t m  k i e a h
x f w d b  j y , . '
           r
*/

#define _HANDS_DOWN \
         KC_V,          KC_G,         KC_L,        KC_TH,          KC_BSPC,               KC_DEL,        KC_U,          KC_O,           KC_P,           KC_Z, \
  LCTL_T(KC_C),  LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T),  HYPR_T(KC_M),          HYPR_T(KC_K),  RSFT_T(KC_I),  RGUI_T(KC_E),   LALT_T(KC_A),   RCTL_T(KC_H), \
         KC_X,          KC_F,         KC_W,   MEH_T(KC_D) ,        KC_B,                  KC_J,    MEH_T(KC_Y),         KC_COMM,         KC_DOT,         KC_QUOT, \
                               LT(NUM,KC_R),        OS_LSFT,       SPACE_L,              KC_BSLS,       OS_LSFT,        NAV_SPC

#define _UTIL \
  SW_APP,  TAB_L,   TAB_R,   SW_WIN,  KC_NO,               KC_NO, KC_BSPC, KC_UP,   KC_DEL,  KC_NO, \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, OSM(MOD_MEH),        FWD,   KC_LEFT, KC_DOWN, KC_RGHT, BACK, \
  Z_UND,   Z_CUT,   Z_CPY,   Z_PST,   ALFRED,              KC_NO, KC_ESC,  KC_COLON,KC_NO,   KC_NO, \
                    KC_SPC, KC_SPC,   KC_F19            , _______, _XXXXX_, _______

#define _NUM \
  KC_GRV   , KC_EQUAL, KC_MINUS, KC_UNDS, KC_PAST      ,KC_BSLS, KC_HASH,  KC_AMPR, KC_PIPE,  _COMMA_, \
  ___7___  , ___5___ , ___3___ , ___1___, KC_PLUS      ,KC_CIRC, ___0___,  ___2___, ___4___,  ___6___ , \
  KC_TILDE , KC_LT   , KC_GT,    ___9___, KC_SLASH     ,KC_AT,   ___8___,  _SEMIC_, KC_COLON, __DOT__, \
                        KC_LT,   KC_GT  , _______      ,_XXXXX_, _XXXXX_, _XXXXX_
 
#define _SYM \
  KC_GRV  ,KC_LT   ,KC_GT,   KC_AT  , KC_DOT       ,KC_AMPR, MAGIC,    KC_LBRC, KC_RBRC, _______, \
  KC_EXLM ,KC_MINS ,KC_PLUS ,KC_EQL,  KC_HASH      ,KC_PIPE, KC_COLON, KC_LPRN, KC_RPRN, KC_PERC , \
  _______ ,KC_SLSH ,KC_PAST, KC_CIRC, _______      ,KC_TILD, KC_AMPR,  KC_LCBR, KC_RCBR, _______, \
                    _______, _______, _______      ,_______, _______, _______

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


// Layout aliases for json keymap
#define LAYOUT_redox(...) LAYOUT(__VA_ARGS__)

#define CONV_REDOX( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
            k59, k60, k61,        k64, k65, k66 \
) \
     KC_NO   ,KC_7    ,KC_5    ,KC_3    ,KC_1    ,KC_9    ,                                            KC_8    ,KC_0    ,KC_2    ,KC_4    ,KC_6  ,KC_NO   , \
     KC_TAB  ,k15     ,k16     ,k17     ,k18     ,k19     ,KC_F11   ,                         KC_F12  ,k22     ,k23     ,k24     ,k25     ,k26     ,KC_BSLS , \
     OS_LSFT ,k29     ,k30     ,k31     ,k32     ,k33     ,KC_DLR  ,                         KC_DLR   ,k36     ,k37     ,k38     ,k39     ,k40 ,    OS_LSFT , \
     KC_LSFT ,k43     ,k44     ,k45     ,k46     ,k47     ,KC_NO   ,QK_BOOT ,        QK_BOOT ,KC_NO   ,k50     ,k51     ,k52     ,k53     ,k54     ,KC_RSFT , \
     KC_LCTL ,KC_LALT ,KC_LEFT ,KC_RIGHT   ,     k59     ,    k60     ,k61     ,        k64      ,k65     ,k66     ,KC_LBRC ,KC_RBRC ,KC_NO   ,KC_NO 

#define REDOX(k) CONV_REDOX(k)

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

#define LAYOUT_FERRIS(...) LAYOUT(__VA_ARGS__)

#define FERRIS(k) CONV_FERRIS(k)

#define CONV_FERRIS( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
            k59, k60, k61,        k64, k65, k66 \
) \
        k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
        k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
        k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
                      k60, k61,         k64, k65


#define LAYOUT_PLANCK(...) LAYOUT(__VA_ARGS__)
#define PLANCK(k) CONV_PLANCK(k)
#define CONV_PLANCK( \
    k01, k02, k03, k04, k05,    k06, k07, k08, k09, k0a, \
    k11, k12, k13, k14, k15,    k16, k17, k18, k19, k1a, \
    k21, k22, k23, k24, k25,    k26, k27, k28, k29, k2a, \
              k33, k34, k35,    k36, k37, k38            \
    ) \
     KC_ESC, k01, k02, k03, k04, k05, \
     KC_TAB, k11, k12, k13, k14, k15, \
     OS_LSFT, k21, k22, k23, k24, k25, \
     KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, KC_RCTL, k36, \
     k06, k07, k08, k09, k0a, KC_BSPC, \
     k16, k17, k18, k19, k1a, KC_ENTER, \
     k26, k27, k28, k29, k2a, OSL(NUM), \
     k37, OSL(NUM), KC_RGUI, OSL(NUM), k34, k35



/*

#define _TEMPLATE_LAYER \
  _______ ,_______, _______, _______, _______      ,_______, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______      ,_______, _______,  _______, _______, _______ , \
  _______ ,_______, _______, _______, _______      ,_______, _______,  _______, _______, _______, \
                    _______, _______, _______      ,_______, _______, _______

*/