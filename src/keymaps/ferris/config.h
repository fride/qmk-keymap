#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
/* Use I2C or Serial, not both */
#define USE_SERIAL
#define MASTER_LEFT

#define TAPPING_FORCE_HOLD          // Allows mod use immediately after tap use
#define TAPPING_FORCE_HOLD_PER_KEY  // BUT NOT EVERYWHERE.
#define TAPPING_TERM 200            // Base tapping term
#define TAPPING_TERM_PER_KEY        // Adjust tapping term for finger strength

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE


#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

// Immediately turn on layer if key is pressed quickly
// this cancels IGNORE_MOD_TAP_INTERRUPT.
// #define HOLD_ON_OTHER_KEY_PRESS

#define TAPPING_TOGGLE 1

// Combos
#undef COMBO_TERM
#define COMBO_TERM 20
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space and keeps me sane
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_VARIABLE_LEN

// does nothing :D
#define COMBO_ALLOW_ACTION_KEYS

#define DEFAULT_XCASE_SEPARATOR KC_MINS
#define XCASE_DELIMITER_KEY KC_UNDS

// Not supported without flto
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Autoshift! I'm to slow with the pinkies!
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_auto_shift.md
#define AUTO_SHIFT_TIMEOUT_PER_KEY

// Enable adaptive roles.
#define ADAPTIVE_KEYS_ENABLE 
#define ADAPTIVE_TERM (TAPPING_TERM/2) // rolling threshold

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

#define ACHORDION

#define FOCAL
