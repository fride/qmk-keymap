#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"

#define LAYOUT_FERRIS(...) LAYOUT(__VA_ARGS__)

#define FERRIS(k) CONV_FERRIS(k)

#define CONV_FERRIS( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
            k59, k60, k61,        k64, k65, k66 \
) \
        k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
        k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
        k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
                      k59, k60,         k65, k66


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHA]  = LAYOUT_FERRIS(FERRIS(_ALPHA)),	
	[ALPHA2]  = LAYOUT_FERRIS(FERRIS(_ALPHA2)),	
	[ALT_ALPHA]   = LAYOUT_FERRIS(FERRIS(_ALT_ALPHA)),	
	[UTIL]   = LAYOUT_FERRIS(FERRIS(_UTIL)),	
	[NUM]    = LAYOUT_FERRIS(FERRIS(_NUM)),	
	[SYM]    = LAYOUT_FERRIS(FERRIS(_SYM)),	
	[SYM_LEFT]    = LAYOUT_FERRIS(FERRIS(_SYM_LEFT)),	
	[SYM_RIGHT]    = LAYOUT_FERRIS(FERRIS(_SYM_RIGHT)),	
	[WINNAV] = LAYOUT_FERRIS(FERRIS(_WINNAV)),	
	[FUN]    = LAYOUT_FERRIS(FERRIS(_FUN)),	
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
    case ___R___:
    case ___I___:
    case NUM_SPC:
    case NAV_SPC:
      return true;
	default:
        break;
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