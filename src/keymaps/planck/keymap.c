#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"


/*
   ___F___, ___R___, ___D___, ___P___, ___V___,      ___Q___, ___M___, ___U___, ___O___, ___Y___, \
   ___S___, ___N___, ___T___, ___C___, ___B___,      __DOT__, ___H___, ___E___, ___A___, ___I___, \
   ___Z___, ___J___, ___K___, ___G___, ___W___,      ___X___, ___L___, KC_SCLN, _SQUOT_ , _COMMA_, \
                      NUM_QUO, NAV_SPC, META_DEAD,      KC_BSLS, OS_LSFT,  NUMWORD                    
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [ALPHA]  = LAYOUT_PLANCK(PLANCK(_RECURVA)),   
   [UTIL]    = LAYOUT_PLANCK(PLANCK(_UTIL)), 
   [NUM]    = LAYOUT_PLANCK(PLANCK(_NUM)), 
   // [SYM]   = LAYOUT_PLANCK(PLANCK(_SYM1)) 
};