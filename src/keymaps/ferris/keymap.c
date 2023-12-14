#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"
#ifdef ACHORDION
#include "features/achordion.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [ALPHA] = LAYOUT_FERRIS(FERRIS(_STURDY)),
   [NUM] = LAYOUT_FERRIS(FERRIS(_NUM)),
   [UTIL] = LAYOUT_FERRIS(FERRIS(_UTIL))
};


// quickfix for the ferris - as it is not a split, or at least claims not to be ;)
static bool _on_left_hand(keypos_t pos) {
  return pos.row < MATRIX_ROWS / 2;
}

bool _achordion_opposite_hands(const keyrecord_t* tap_hold_record,
                              const keyrecord_t* other_record) {
  return _on_left_hand(tap_hold_record->event.key) !=
         _on_left_hand(other_record->event.key);
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand
  switch (tap_hold_keycode) {
    case MAGIC_GUI:
    case MEH_SPC:
    case COLON_SYM:
    case ESC_SYM:
    case NAV_SPC:
      return true;
    case ___T___:
      switch (other_keycode)
      {
        case ___X___:
        case ___C___:
          return true;
      
      default:
        break;
      }
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  //return true;
  // does not work on the ferris!?
  return _achordion_opposite_hands(tap_hold_record, other_record);
}

