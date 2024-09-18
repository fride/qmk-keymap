
//#define NAV_SPC LT(UTIL, KC_SPC)
#define NAV_SPC HYPR_T(KC_SPC)
#define MEH_SPC MEH_T(KC_SPC)
#define NUM_QUO LT(NUM, KC_QUOT)
#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH)
#define UM_CTL LCTL_T(KC_U)
#define REP_CTL LT(NUM,KKC_DEL

#define ___A___ LT(UTIL,KC_A)
#define ___B___ LCTL_T(KC_B)
#define ___C___ KC_C
#define ___D___ KC_D
#define ___E___ LT(SYM,KC_E)
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ KC_H
#define ___I___ KC_I
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ KC_M
#define ___N___ LT(NUM,KC_N)
#define ___O___ KC_O
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ LT(SYM,KC_R)
#define ___S___ KC_S
#define ___T___ LT(UTIL,KC_T)
#define ___U___ KC_U
#define ___V___ LGUI_T(KC_V)
#define ___W___ LALT_T(KC_W)
#define ___X___ KC_X
#define ___Y___ RCTL_T(KC_Y)
#define ___Z___ KC_Z
#define _MAGIC_ RALT_T(MAGIC)
#define _COMMA_ KC_COMM
#define __DOT__ LALT_T(KC_DOT)
#define _SLASH_ KC_SLSH
#define _SQUOT_ RGUI_T(KC_QUOT)
#define _DQUOT_ KC_DQUO
#define _MINUS_ KC_MINS
#define __HASH_ KC_HASH
#define _SEMIC_ KC_SCLN
#define _QUEST_ KC_QUES

#define ___0___ KC_0
#define ___2___ KC_2
#define ___4___ KC_4
#define ___6___ KC_6
#define ___8___ KC_8

#define ___1___ KC_1
#define ___3___ KC_3
#define ___5___ KC_5
#define ___7___ KC_7
#define ___9___ KC_9

#define __PUQ__ OSL(ALPHA2)

#define _ALPHA \
  ___Z___, ___M___, ___L___, ___C___, ___G___,      ___Q___, _COMMA_, __PUQ__, ___U___, ___P___, \
  ___S___, ___N___, ___R___, ___T___, ___D___,      ___O___, ___A___, ___E___, ___I___, ___H___, \
  ___F___, ___B___, ___W___, ___V___, ___J___,      ___X___, _SQUOT_, __DOT__, ___Y___, ___K___, \
                    NAV_SPC, OS_LGUI, _XXXXX_,      _XXXXX_, OS_LCTL , OS_LSFT

#define _ALPHA2 \
  _______ ,_______, _______, _______, _______      ,_______, ARROW,    FARROW, A(KC_U), _______, \
  A(KC_S), _______, _______, KC_TH,   _______      ,A(KC_O), A(KC_A),  A(KC_A), _______, _______ , \
  _______ ,_______, _______, _______, _______      ,_______, _______,  _______, _______, _______, \
                    _______, _______, _______      ,_______, _______,  _______


#define _UTIL_PUQ \
  SW_APP,  TAB_L,   TAB_R,   SW_WIN,  KC_NO,               KC_NO, KC_BSPC, KC_UP,   KC_DEL,  KC_NO, \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, OSM(MOD_MEH),        FWD,   KC_LEFT, KC_DOWN, KC_RGHT, BACK, \
  Z_UND,   Z_CUT,   Z_CPY,   Z_PST,   ALFRED,              KC_NO, KC_ESC,  KC_COLON,KC_NO,   KC_NO, \
                    KC_SPC, OS_LGUI,   KC_F19            , _______, _XXXXX_, _______

#define _SYM_LEFT \
    KC_LCBR, KC_AMPR, KC_GRV,  KC_AT,   _______,                         _______, _______, _______, _______, _______,\
    KC_LBRC, KC_CIRC, KC_TILD, KC_LPRN, KC_DOT,                          _______, _______, _______, _______, _______,\
    KC_LT,   KC_PIPE, KC_BSLS, KC_3,    _______,                         _______, _______, _______, _______, _______,\
                      _______, _______, _______,                         _______, _______, _______

#define _SYM_RIGHT \
    _______, _______, _______, _______, _______,                         _______, KC_DLR,  KC_SLSH, KC_ASTR, KC_RCBR,\
    _______, _______, _______, _______, _______,                         KC_DOT,  KC_RPRN, KC_MINS, KC_PLUS, KC_RBRC,\
    _______, _______, _______, _______, _______,                         _______, KC_HASH, KC_PERC, KC_EQL,  KC_GT,\
                      _______, _______, _______,                         _______, _______, _______        
    
#define _NUM \
  _______ , _______, _______, _______, _______      ,KC_BSLS,  ___7___, ___8___, ___9___,  _COMMA_, \
  _XXXXX_ , _XXXXX_, OS_LALT, OS_LGUI, _______      ,KC_SLASH, ___4___, ___5___, ___6___,  ___0___ , \
  _______ , _______, OS_LGUI, _XXXXX_, _______      ,KC_AT,    ___1___, ___2___, ___3___, __DOT__, \
                     KC_SPC,  OS_LGUI , _XXXXX_     ,_______, OS_LCTL,   ___0___
