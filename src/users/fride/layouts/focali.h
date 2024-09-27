#define NAV_SPC LT(UTIL, KC_SPC)
#define MEH_SPC HYPR_T(KC_SPC)

#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH)
#define NUM_SPC LT(NUM,KC_SPC)



#define ___A___ LALT_T(KC_A)
#define ___B___ HYPR_T(KC_B)
#define ___C___ RGUI_T(KC_C)
#define ___D___ MEH_T(KC_D)
#define ___E___ LT(NUM, KC_E)
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ RALT_T(KC_H)
#define ___I___ LCTL_T(KC_I)
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ KC_M
#define ___N___ LALT_T(KC_N)
#define ___O___ RALT_T(KC_O)
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ LCTL_T(KC_R)
#define ___S___ LSFT_T(KC_S)
#define ___T___ LGUI_T(KC_T)
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ MEH_T(KC_X)
#define ___Y___ HYPR_T(KC_Y)
#define ___Z___ KC_Z
#define _MAGIC_ RSFT_T(MAGIC)
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
#define _EQUAL_ KC_EQL

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
  ___V___, ___L___, ___H___, ___G___, ___K___,      ___Q___, ___F___, ___O___, ___U___, ___J___, \
  ___S___, ___R___, ___N___, ___T___, ___B___,      ___Y___, ___C___, ___A___, ___I___, _MAGIC_, \
  ___Z___, ___X___, ___M___, ___D___, ___P___,      _SQUOT_, ___W___, __DOT__, _SEMIC_, _COMMA_, \
                    NAV_SPC, OS_LSFT, OS_LSFT,      OS_LSFT, OS_LSFT, ___E___

#define _ALPHA2 \
  KC_Q    ,KC_Z   , _______, _______, _______      ,_______, _______, A(KC_O), A(KC_U),  A(KC_S), \
  A(KC_S), KC_LBRC, KC_LCBR, KC_LPRN, _______      ,_______, _______, A(KC_A), _______, ARROW , \
  _______ ,KC_RBRC, KC_RCBR, KC_RPRN, _______      ,_______, _______, _______, _______, _______, \
                    _______, _______, _______      ,_______, _______, _______

// inspired by https://github.com/grassfedreeve/zmk-config-akohekohe?tab=readme-ov-file

// and from https://github.com/bredfield/zmk-config/blob/main/images/30%20Key.png
#define _NUM \
  KC_GRV  ,KC_EQL  ,KC_MINS, KC_UNDS,  KC_PAST      ,KC_BSLS ,KC_HASH, KC_AMPR ,KC_PIPE ,KC_TILD, \
  ___1___ ,___2___  ,___3___ ,___4___ ,KC_PLUS      ,KC_GRV ,___7___, ___8___ ,___9___, ___0___, \
  _XXXXX_ ,KC_COLON,KC_PERC  ,___5___, KC_CIRC       ,KC_AT, ___6___ ,__DOT__, _SEMIC_, _COMMA_, \
                    KC_LT,    KC_GT  , _XXXXX_      ,_______, _______, _XXXXX_


#define _SYM \
  KC_EXLM,     KC_AT,   KC_HASH,    KC_DLR,     KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,     KC_QUOT,\
  KC_PLUS,     KC_EQL,  KC_LPRN,    KC_RPRN,    KC_DQT,        KC_COLN, KC_RBRC,  KC_LBRC, KC_RCBR,     KC_LCBR,\
  KC_LT,       KC_PIPE, KC_MINS,    KC_GT,      KC_BSLS,       KC_GRV,  KC_UNDS, KC_SLSH, KC_TILD,     KC_SCLN,\
                        OS_LALT, OS_LGUI, _______,            _______, OS_LCTL , OS_LSFT
                        
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
