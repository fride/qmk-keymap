#include "layout.h"

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if ((mods & ~MOD_MASK_SHIFT) == 0) {
    switch (keycode) {      
      case KC_B:
        return KC_N;  // TODO BEFORE
      case KC_D:
        return KC_Y;
      case HOME_E:
        return KC_O;
      case HOME_F:
        return KC_T;      
      case KC_G:
        return KC_N;
      // case ___H___:
        // return KC_Y;
      case KC_I:
        return MG_ION;
      case KC_J:
        return MG_UST;
      case KC_K:
        return KC_S;
      case HOME_L:
        return KC_M; // N is wose!
      case KC_M:
        return KC_L; // AMT and co in Germann ;)
      case HOME_O:
        return KC_E;            
      case HOME_S:
        return KC_C;
      case HOME_T:
        return KC_M; //ment does not work that well with german
      case HOME_U:
        return KC_I;
      case KC_V:
        return MG_VER;
      case KC_W:
        return KC_R;
      case KC_EQL:
        return KC_GT;
      case KC_LPRN:
        return KC_RPRN;
      case KC_MINS:
        return KC_GT;
      case NAV_SPC:
        return MG_THE;
      case KC_ESC:
        return KC_COLON;
      case KC_COMM:
      case KC_DOT:
        return M_SENTENCE; // ODO does not work!
      case KC_1 ... KC_0:
        return KC_DOT;
      default:
        return KC_N;
    }
  } else if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case KC_A:  // Ctrl+A -> Ctrl+K
        return C(KC_K);
      case KC_C:  // Ctrl+C -> Ctrl+C
        return C(KC_C);
    }
  }
  return KC_TRNS;
}


// reeat
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        case SYM_REP:
        case SYM_SPC:
        case MAGIC_GUI:
            return false;
        case KC_A ... KC_Y:
              if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
              }
          break;
         
    }
    return true;
}

bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t *record,
                                  uint8_t *remembered_mods) {
  switch (keycode) {
    case SYM_REP:
    case SYM_SPC:
    case MAGIC_GUI:
        return false;

    // Forget Shift on letter keys A-Y when Shift or AltGr are the only mods.
    // Exceptionally, I want to remember Shift on Z for "ZZ" in Vim.
    case KC_A ... KC_Y:
      if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        *remembered_mods &= ~MOD_MASK_SHIFT;
      }
      break;
  }

  return true;
}
