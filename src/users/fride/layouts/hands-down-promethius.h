
#define MEH_SPC HYPR_T(KC_SPC)
#define NUM_QUO LT(NUM, KC_QUOT)
#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH)
#define UM_CTL LCTL_T(KC_U)
#define REP_CTL LT(NUM,KKC_DEL

#define ___A___ RSFT_T(KC_A)
#define ___B___ KC_B
#define ___C___ LT(SYM,KC_C)
#define ___D___ KC_D
#define ___E___ KC_E
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ LSFT_T(KC_H)
#define ___I___ KC_I
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ KC_M
#define ___N___ KC_N
#define ___O___ KC_O
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ LT(UTIL,KC_R)
#define ___S___ LT(SYM,KC_S)
#define ___T___ KC_T
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ KC_X
#define ___Y___ KC_Y
#define ___Z___ KC_Z
#define _MAGIC_ RALT_T(MAGIC)
#define _COMMA_ LALT_T(KC_COMM)
#define __DOT__ RCTL_T(KC_DOT)
#define _SLASH_ KC_SLSH
#define _SQUOT_ KC_QUOT
#define _DQUOT_ KC_DQUO
#define _MINUS_ KC_MINS
#define __HASH_ KC_HASH
#define _SEMIC_ KC_SCLN
#define _QUEST_ KC_QUES
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
  ___B___, ___F___, ___D___, ___L___, ___J___,      _SEMIC_, __DOT__, _SQUOT_, _EQUAL_, _SLASH_, \
  ___S___, ___N___, ___T___, ___H___, ___K___,      _COMMA_, ___A___, ___E___, ___I___, ___C___, \
  ___V___, ___W___, ___G___, ___M___, ___X___,      _MINUS_, ___U___, ___O___, ___Y___, ___P___, \
                    ___R___, OS_LSFT, _XXXXX_,      _XXXXX_, OS_LSFT , MEH_SPC

#define _ALPHA2 \
  ___B___, ___F___, ___D___, ___L___, ___J___,      O_UML,   __DOT__, _SQUOT_, _EQUAL_, A_UML,  \
  ___S___, ___N___, ___T___, ___H___, ___K___,      _COMMA_, ___A___, ___E___, ___I___, ___C___, \
  ___V___, ___W___, ___G___, ___M___, ___X___,      U_UML,   ___U___, ___O___, ___Y___, ___P___, \
                    ___R___, OS_LSFT, _XXXXX_,      _XXXXX_, OS_LSFT , MEH_SPC


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
    
#define _NUM \
  _______ , _______, _______, _______, _______      ,KC_BSLS,  ___7___, ___8___, ___9___,  _COMMA_, \
  _______ , _XXXXX_, _______, _______, _______      ,KC_SLASH, ___4___, ___5___, ___6___,  ___0___ , \
  _______ , _______, OS_LALT, OS_LGUI, _______      ,KC_AT,    ___1___, ___2___, ___3___, __DOT__, \
                    MEH_SPC,  OS_LGUI , _XXXXX_     ,_______, OS_LCTL,   OS_LSFT
