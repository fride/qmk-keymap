#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
#include "features/layermodes.h"
#include "features/nshot_mod.h"
#include "features/repeat_key.h"
#include "features/swapper.h"
#include "features/tap_hold.h"
#include "keycodes.h"
#include "layers.h"

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_QUES},  // Shift . is ?
    {KC_COMM, KC_EXLM},
    {KC_EQL, KC_EQL},  // Don't shift =
    {KC_SLSH, KC_SLSH},  // Don't shift /
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(*custom_shift_keys);

// ┌─────────────────────────────────────────────────┐
// │ s W A P P E R                                   │
// └─────────────────────────────────────────────────┘
bool sw_app_active = false;
bool sw_win_active = false;
bool wap_app_cancel(uint16_t keycode) {
  switch (keycode) {
    case KC_TAB:
    case KC_UP:
    case KC_RIGHT:
    case KC_DOWN:
    case KC_LEFT:
      return false;
  }
  return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if ((mods & ~MOD_MASK_SHIFT) == 0) {
    switch (keycode) {
      case ALPHA_18:
        return KC_O;
      case KC_B:
        return KC_N;  // TODO BEFORE
      case ALPHA_03: // C
        return KC_Y;
      case ALPHA_13:
        return KC_Y;
      case ALPHA_17:
        return KC_U;
      case ALPHA_15:
        return KC_N;
      case ALPHA_16:
        return KC_F;  // Fuenf!
      case ALPHA_23:
        return KC_Y;
      case ALPHA_19:
        return MG_ION;
      case ALPHA_22:
        return MG_UST;
      case ALPHA_21:
        return KC_S;
      case ALPHA_02:
        return KC_K;
      case ALPHA_01:
        return KC_T; // AMT and co in Germann ;)
      // N makes no sense!
      case ALPHA_08:
        return KC_A;
      case ALPHA_04:
        return KC_Y;
      case ALPHA_12:
        return KC_L;
      case ALPHA_10:
        return KC_K;
      case ALPHA_11:
        return KC_M; //ment does not work that well with german
      case ALPHA_07:
        return KC_E;
      case ALPHA_00:
        return MG_VER;
      case ALPHA_14:
        return KC_P;
      case KC_EQL:
        return KC_GT;
      case KC_LPRN:
        return KC_RPRN;
      case KC_MINS:
        return KC_GT;
      case SPACE:
        return MG_THE;
      case KC_ESC:
        return KC_COLON;
      case KC_1 ... KC_0:
        return KC_DOT;
      default:
        return KC_N;
    }
  } else if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case HOME_A:  // Ctrl+A -> Ctrl+K
        return C(KC_C);
      case KC_C:  // Ctrl+C -> Ctrl+C
        return C(KC_C);
    }
  }
  return KC_TRNS;
}

bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t *record,
                                  uint8_t *remembered_mods) {
  // Forget Shift on letter keys A-Y when Shift or AltGr are the only mods.
  // Exceptionally, I want to remember Shift on Z for "ZZ" in Vim.
  switch (keycode) {
    case KC_A ... KC_Y:
      if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        *remembered_mods &= ~MOD_MASK_SHIFT;
      }
      break;
  }

  return true;
}

// clang-format off
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  
   if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) {
    return false;
  }
  
  process_num_word(keycode, record);

  update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record,
                 wap_app_cancel);
  
  update_swapper(&sw_win_active, KC_LGUI, KC_GRV, SW_WIN, keycode, record,
                 NULL);

  process_nshot_state(keycode, record);

  if (!process_custom_shift_keys(keycode, record)) { 
    return false; 
  }
  const uint8_t mods = get_mods();
  const bool shifted = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
                       ) & MOD_MASK_SHIFT;

    if (!process_tap_hold(keycode, record)) {
        return false;
    }

    // this overrides the repeat keys.
    // because nf is a commonn bigram in german ;)
    if (record->event.pressed) {
      int rep_count = get_repeat_key_count();
      if (rep_count < -1 && keycode != MG_UST) {
          send_char('n');
          return false;
      }
       if (rep_count > 0) {
            switch (keycode) {
               case ALPHA_16:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    send_char('f');
                    return false;
                // one time shift after space?
                case ALPHA_31:
                  set_oneshot_mods(MOD_BIT(KC_LSFT));
                  return false;
                case ALPHA_19: // i -> ng 
                  SEND_STRING("ng");
                  return false;                
            }
       }       
    }
  
    switch (keycode) {      
      case ALFRED:
        if (record->event.pressed) {
            SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_SPACE) SS_UP(X_LALT));
            return false;
        }
      case NEXTSEN:  // Next sentence macro.
        if (record->event.pressed) {
          SEND_STRING(". ");
          add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
        }
        return false;
      case CANCEL:  
        if (record->event.pressed) {
  //     stop_leading();
          layer_off(_NAV);
          layer_off(_NUM);
          layer_off(_SYM);
          //disable_caps_word();
          disable_num_word();
          layer_move(_ALPHA);
          return false;
        }
      case NUMWORD:
        process_num_word_activation(record);
        return false;
      case CLN_SYM: {
        if (record->tap.count && record->event.pressed) {
          tap_code16(KC_COLON);
          return false;
        } else {
          return true;
        }         
      }
      case MAGIC: {
        if (record->tap.count > 0) {
          tap_code16(ALTREP);
          return false;
        } else {
          return true;
        }         
      }
      case ESC_SYM: {
        if (record->tap.count && record->event.pressed) {
          tap_code16(KC_ESC);
          return false;
        } else {
          return true;
        }         
      }
      case LSFT_T(REPEAT): {
        if (record->tap.count > 0) {
          repeat_key_tap();
          return false;
        } else {
          return true;
        }         
      }
      case A_UML:
        if (record->event.pressed) {
          // TODO SHIFT!
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_A));
          return false;
        }
      case O_UML:
        if (record->event.pressed) {
          // TODO SHIFT!
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_O));
          return false;
        }
      case U_UML:
        if (record->event.pressed) {
          // TODO SHIFT!
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_U));
          return false;
        }
      case SZ:
        if (record->event.pressed) {
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_S) SS_UP(X_LALT));
          return false;
        }
      case MG_ION:
        if (record->event.pressed) {
          SEND_STRING("on");
          return false;
        }
      case MG_VER:
      if (record->event.pressed) {
          SEND_STRING("er");
          return false;
      }
      case MG_UST:
      if (record->event.pressed) {
          SEND_STRING("ust");
          return false;
      }
      case MG_ENT:
      if (record->event.pressed) {
          SEND_STRING("ent");
          return false;
      }
      case MG_MENT:
      if (record->event.pressed) {
          SEND_STRING("ment");
          return false;
      }
      case MG_THE:
      if (record->event.pressed) {
        if (shifted) {
          SEND_STRING("the");
        } else {
          SEND_STRING("The");
        }
        return false;
      }
    }
  return true;
}


bool tap_hold(uint16_t keycode) {
    switch (keycode) {
      case KC_EQL:
      case KC_PAST:
      case KC_LPRN:
      case KC_LBRC:
      case KC_LCBR:
      case KC_LEFT:
      case KC_UP:
      case KC_DOWN:
      case KC_RIGHT:
      case CPYPASTE:
        return true;
    }
    return false;
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
      case CPYPASTE:
        tap_code16(G(KC_C));
        break;
      default:
            tap_code16(keycode);
    }
}
void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
      case CPYPASTE:
        tap_code16(G(KC_V));
        break;
      case KC_LEFT:
        tap_code16(G(KC_LEFT));
        break;
      case KC_UP:
        tap_code16(G(KC_UP));
        break;
      case KC_DOWN:
        tap_code16(G(KC_DOWN));
        break;
      case KC_RIGHT:
        tap_code16(G(KC_RIGHT));
        break;
      case KC_PAST:
        tap_code16(KC_SLSH);
        break;
      case KC_LPRN:
        tap_code16(KC_RPRN);
        break;
      case KC_LBRC:
        tap_code16(KC_RBRC);
        break;
      case KC_LCBR:
        tap_code16(KC_RCBR);
        break;
      case KC_EQL:
        send_string(" != ");
        break;
    }
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}