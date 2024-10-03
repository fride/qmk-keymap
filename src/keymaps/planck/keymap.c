#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"


#define LAYOUT_PLANCK(...) LAYOUT_planck_grid(__VA_ARGS__)
#define PLANCK(k) CONV_PLANCK(k)
#define CONV_PLANCK( \
    k01, k02, k03, k04, k05,    k06, k07, k08, k09, k0a, \
    k11, k12, k13, k14, k15,    k16, k17, k18, k19, k1a, \
    k21, k22, k23, k24, k25,    k26, k27, k28, k29, k2a, \
              k33, k34, k35,    k36, k37, k38            \
    ) \
     KC_ESC,  k01,   k02,   k03, k04, k05,    k06, k07, k08, k09,   k0a,   KC_DEL, \
     KC_BSPC, k11,   k12,   k13, k14, k15,    k16, k17, k18, k19,   k1a,   KC_ENTER, \
     OS_LSFT, k21,   k22,   k23, k24, k25,    k26, k27, k28, k29,   k2a,   OS_LSFT, \
     KC_NO,   KC_NO, KC_NO, k35, k33, k34,    k37, k38, k36, KC_NO, KC_NO, KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// [QWERTY]  = LAYOUT_PLANCK(PLANCK(_QWERTY)),	
	[ALPHA]  = LAYOUT_PLANCK(PLANCK(_ALPHA)),	
	[ALPHA2]  = LAYOUT_PLANCK(PLANCK(_ALPHA2)),	
	[UTIL]   = LAYOUT_PLANCK(PLANCK(_UTIL)),	
	[NUM]    = LAYOUT_PLANCK(PLANCK(_NUMWORD)),	
	[SYM]    = LAYOUT_PLANCK(PLANCK(_SYM)),	
	[SYM_LEFT]    = LAYOUT_PLANCK(PLANCK(_SYM_LEFT)),	
	[SYM_RIGHT]    = LAYOUT_PLANCK(PLANCK(_SYM_RIGHT)),	
	[WINNAV] = LAYOUT_PLANCK(PLANCK(_WINNAV)),
	[FUN]    = LAYOUT_PLANCK(PLANCK(_FUN)),	
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
//    case NUM_SPC:
    case NAV_SPC:
    case ___E___:
    case MEH_SPC:
      return true;
	case ___D___:
		if (other_keycode == ___V___) {
			return true;
		}
		break;
	case ___R___:
	case ___T___:
    switch (other_keycode){
      case OS_LALT:
      case OS_LGUI:
        return true;
    }
		break;
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