#define NAV_SPC LT(UTIL, KC_SPC)
#define MEH_SPC MEH_T(KC_SPC)
#define NUM_QUO LT(NUM, KC_QUOT)
#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH)
#define UM_CTL LCTL_T(KC_U)
#define NUM_SPC LT(NUM,KC_SPC)

#define ___A___ RCTL_T(KC_A)
#define ___B___ KC_B
#define ___C___ RSFT_T(KC_C)
#define ___D___ LT(NUM,KC_D)
#define ___E___ KC_E
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ KC_H
#define ___I___ LALT_T(KC_I)
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ KC_M
#define ___N___ LCTL_T(KC_N)
#define ___O___ KC_O
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ LALT_T(KC_R)
#define ___S___ LGUI_T(KC_S)
#define ___T___ LSFT_T(KC_T)
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ KC_X
#define ___Y___ KC_Y
#define ___Z___ KC_Z
#define _MAGIC_ RGUI_T(MAGIC)
#define _COMMA_ KC_COMM
#define __DOT__ LALT_T(KC_DOT)
#define _SLASH_ KC_SLSH
#define _SQUOT_ KC_QUOT
#define _DQUOT_ KC_DQUO
#define _MINUS_ KC_MINS
#define __HASH_ KC_HASH
#define _SEMIC_ KC_SCLN
#define _QUEST_ KC_QUES
#define _ALPA_ OSL(ALPHA2)

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

#define _ALPHA \
  ___V___, ___L___, ___H___, ___G___, ___K___,      ___Q___, ___F___, ___O___, ___U___, _SQUOT_, \
  ___S___, ___R___, ___N___, ___T___, ___B___,      ___Y___, ___C___, ___A___, ___I___, _MAGIC_, \
  ___Z___, ___X___, ___M___, ___D___, ___P___,      _SQUOT_, ___W___, __DOT__, _SEMIC_, _COMMA_, \
                    NAV_SPC, _MAGIC_, OS_LSFT,      OS_LSFT, _MAGIC_, ___E___

#define _ALPHA2 \
  KC_Q    ,KC_Z   , _______, _______, _______      ,_______, _______, A(KC_O), A(KC_U),  A(KC_S), \
  A(KC_S), KC_LBRC, KC_LCBR, KC_LPRN, _______      ,_______, _______, A(KC_A), _______, ARROW , \
  _______ ,KC_RBRC, KC_RCBR, KC_RPRN, _______      ,_______, _______, _______, _______, _______, \
                    _______, _______, _______      ,_______, _______, _______

#define _NUM \
  _______ , _______, _______, _______, _______      ,KC_BSLS,  ___7___, ___8___, ___9___,  _COMMA_, \
  OS_LGUI , OS_LCTL, OS_LCTL, OS_LSFT, _______      ,KC_SLASH, ___4___, ___5___, ___6___,  ___0___ , \
  _______ , _______, OS_LSFT, _XXXXX_, _______      ,KC_AT,    ___1___, ___2___, ___3___, __DOT__, \
                    _XXXXX_,  _XXXXX_ , _XXXXX_     ,_______, KC_SPC,   ___0___

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
