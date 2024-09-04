#define NAV_SPC LT(UTIL, KC_SPC)
#define MEH_SPC MEH_T(KC_SPC)
#define NUM_QUO LT(NUM, KC_QUOT)
#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH)
#define UM_CTL LCTL_T(KC_U)
#define NUM_DEL LT(NUM,KKC_DEL

#define ___A___ RCTL_T(KC_A)
#define ___B___ KC_B
#define ___C___ LGUI_T(KC_C)
#define ___D___ KC_D
#define ___E___ RSFT_T(KC_E)
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ RGUI_T(KC_H)
#define ___I___ LT(SYM,KC_I)
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ KC_M
#define ___N___ LSFT_T(KC_N)
#define ___O___ KC_O
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ KC_R
#define ___S___ LCTL_T(KC_S)
#define ___T___ LT(SYM,KC_T)
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ LALT_T(KC_X)
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

#define _ALPHA \
  ___V___, ___G___, ___L___, _MAGIC_, ___Q___,      ___J___, ___U___, ___O___, ___P___, ___Z___, \
  ___C___, ___S___, ___N___, ___T___, ___M___,      ___K___, ___I___, ___E___, ___A___, ___H___, \
  ___X___, ___F___, ___W___, ___D___, ___B___,      ___J___, ___Y___, _COMMA_, __DOT__, _SQUOT_, \
                    ___R___, LMAGIC, OS_LSFT,    OS_LSFT, RMAGIC, NAV_SPC
