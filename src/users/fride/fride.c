#include QMK_KEYBOARD_H
#include "features/layermodes.h"
#include "features/nshot_mod.h"
#include "features/swapper.h"
#include "features/tap_hold.h"
#ifdef ACHORDION
#include "features/achordion.h"
#endif
#include "features/adaptive_keys.h"
#include "features/process_records.h"
#include "features/custom_shift_keys.h"

#include "layout.h"

#define IS_SHIFTED(mods) \
  (mods | get_weak_mods() | get_oneshot_mods() & MOD_MASK_SHIFT);
#define UMLAUT(KC) tap_code16(A(KC))
#define UPPER_UMLAUT(KC) tap_code16(S(A(KC)))

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_EXLM}, 
    {KC_COMM, KC_QUES},
    {_DQUOT_, KC_LPRN},
    {_SQUOT_, KC_RPRN},
    {KC_MINS, KC_PLUS},
    {KC_SLASH, KC_PAST},
    // {KC_EQL, KC_EQL},  // Don't shift =
    // {KC_SLSH, KC_SLSH},  // Don't shift /
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef ACHORDION
  if (!process_achordion(keycode, record)) {
    return false;
  }
#endif
  process_num_word(keycode, record);

  update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record,
                 wap_app_cancel);

  update_swapper(&sw_win_active, KC_LGUI, KC_GRV, SW_WIN, keycode, record,
                 NULL);

  process_nshot_state(keycode, record);

  const uint8_t mods = get_mods();
  const bool shifted = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
                            ) &
                       MOD_MASK_SHIFT;

  if (!process_tap_hold(keycode, record)) {
    return false;
  }

  if (!process_adaptive_key(keycode, record)) {
    return false;
  }

  if (!process_custom_shift_keys(keycode, record)) { 
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
        case ___N___:
          unregister_weak_mods(MOD_MASK_CSAG);
          send_char('f');
          return false;
        case ___A___:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING("nd");
          return false;
        case ___Y___:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING("ou");
          return false;
        case KC_QUES:
        case KC_EXLM:
        case __DOT__:
          unregister_weak_mods(MOD_MASK_CSAG);
          send_char(' ');
          add_oneshot_mods(MOD_MASK_SHIFT);
          // set_repeat_key_keycode(KC_SPC);
          return false;
          // one time shift after space?
        case NAV_SPC:
          set_oneshot_mods(MOD_BIT(KC_LSFT));
          return false;
      }
    }
  }

  switch (keycode) {
    case MAGIC_GUI:
    // TODO this only ever returns an n
     if (record->event.pressed) {
        if (record->tap.count > 0) {
          keyrecord_t press;
          press.event.type = KEY_EVENT;
          press.tap.count = 1;
          press.event.pressed = true;
          process_repeat_key(QK_AREP, &press);
          keyrecord_t release;
          release.event.type = KEY_EVENT;
          release.tap.count = 1;
          release.event.pressed = false;
          process_repeat_key(QK_AREP, &release);
          return PROCESS_RECORD_RETURN_TRUE;
        }
      }
      break;
    case _DQUOT_:
      if (record->event.pressed) {
        if (shifted) {
          tap_code16(KC_LPRN);
        } else {
          tap_code16(KC_DQUO);
        }
        return false;
      }
      break;
    case LPAREN:
      if (record->event.pressed) {
        if (shifted) {
          tap_code16(KC_LT);
        } else {
          tap_code16(KC_LPRN);
        }
        return false;
      }
    case RPAREN:
      if (record->event.pressed) {
        if (shifted) {
          tap_code16(KC_GT);
        } else {
          tap_code16(KC_LPRN);
        }
        return false;
      }
    case ALFRED:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPACE) SS_UP(X_LALT));
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
        layer_off(UTIL);
        layer_off(NUM);
        // disable_caps_word();
        disable_num_word();
        layer_move(ALPHA);
        return false;
      }

    case NUMWORD:
      process_num_word_activation(record);
      return false;
    case M_LT:
      if (record->event.pressed && record->tap.count > 0) {
        if (shifted) {
          tap_code16(KC_LPRN);
        } else {
          tap_code16(KC_LT);
        }
        return false;
      }
      break;  
    case M_GT:
      if (record->event.pressed && record->tap.count > 0) {
        if (shifted) {
          tap_code16(KC_RPRN);
        } else {
          tap_code16(KC_GT);
        }
        return false;
      }
      break;  
    // case COLON_SYM: {
    //   if (record->event.pressed && record->tap.count > 0) {
    //     tap_code16(KC_COLON);
    //     return false;
    //   }
    //   break;
    // }
    case DI_TH:
      if (record->event.pressed) {
        SEND_STRING("th");
      }
      break;
    case DI_SH:
       if (record->event.pressed) {
        SEND_STRING("sh");
      }
      break;
    case DI_CH:
     if (record->event.pressed) {
        SEND_STRING("ch");
      }
      break;
    case DI_WH:
     if (record->event.pressed) {
        SEND_STRING("wh");
      }
      break;
    // case ESC_SYM: {
    //   if (record->event.pressed && record->tap.count > 0) {
    //     tap_code16(KC_ESC);
    //     return false;
    //   }
    //   break;
    // }
    case SZ:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_S) SS_UP(X_LALT));
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
    case M_SENTENCE:
      if (record->event.pressed) {
        tap_code16(KC_SPC);
        add_weak_mods(MOD_BIT(KC_LSFT));
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
    case KC_EXLM:
    case KC_LT:
    case KC_UP:
    case KC_DOWN:
    case KC_RIGHT:
    case A_UML:
    case O_UML:
    case U_UML:
    case KC_TH:
    case QU:
    case CPYPASTE:
      return true;
  }
  return false;
}

void tap_hold_send_tap(uint16_t keycode) {
  switch (keycode) {
    case QU:
      SEND_STRING("qu");
      break;
    case KC_TH:
      // TODO handle Shift!
      SEND_STRING("th");
      break;
    case CPYPASTE:
      tap_code16(G(KC_C));
      break;
    case A_UML:
      UMLAUT(KC_A);
      break;
    case O_UML:
      UMLAUT(KC_O);
      break;
    case U_UML:
      UMLAUT(KC_U);
      break;
    default:
      tap_code16(keycode);
  }
}
void tap_hold_send_hold(uint16_t keycode) {
  switch (keycode) {
    case QU:
      tap_code16(KC_Q);
      break;
    case A_UML:
      UPPER_UMLAUT(KC_A);
      break;
    case O_UML:
      UPPER_UMLAUT(KC_O);
      break;
    case U_UML:
      UPPER_UMLAUT(KC_U);
      break;
    case KC_TH:
      // TODO handle Shift!
      SEND_STRING("tion");
      break;
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
      SEND_STRING("()" SS_TAP(X_LEFT));
      break;
    case KC_LT:
      SEND_STRING("<>" SS_TAP(X_LEFT));
      break;
    case KC_LBRC:
      SEND_STRING("[]" SS_TAP(X_LEFT));
      break;
    case KC_LCBR:
      SEND_STRING("{}" SS_TAP(X_LEFT));
      break;
    case KC_EQL:
      send_string(" == ");
      break;
    case KC_EXLM:
      send_string(" != ");
      break;
  }
}

void matrix_scan_user(void) { tap_hold_matrix_scan(); }

uint16_t get_combo_term(uint16_t index, combo_t* combo) {
  switch (index) {
    default:
      return COMBO_TERM;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case ___S___:
    case ___T___:
    case ___I___:
    case ___A___:
      return TAPPING_TERM + 30;
    default:
      return TAPPING_TERM;
  }
}
// TODO https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
bool get_combo_must_tap(uint16_t index, combo_t* combo) { return false; }

#ifdef ACHORDION
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand
  switch (tap_hold_keycode) {
    case ESC_SYM:
    case MAGIC_GUI:
    case MEH_SPC:
      return true;
    case HOME_E:
      if (other_keycode == KC_P || other_keycode == KC_PIPE) {
        return true;
      }
      break;
    case ___T___:
      if (other_keycode == ___X___) {
        return true;
      }
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case MAGIC_GUI:
    case ESC_SYM:
    case MEH_SPC:
    case COLON_SYM:
      return 0;  // Bypass Achordion for these keys.
  }

  return 1000;  // Otherwise use a timeout of 1 second
}
#endif
