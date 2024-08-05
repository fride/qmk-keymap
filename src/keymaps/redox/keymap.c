#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHA]  = LAYOUT_redox(REDOX(_DHORF_E)),	
	[UTIL]   = LAYOUT_redox(REDOX(_UTIL)),	
	[NUM]    = LAYOUT_redox(REDOX(_NUM)),	
	[SYM]    = LAYOUT_redox(REDOX(_SYM)),	
	[WINNAV] = LAYOUT_redox(REDOX(_WINNAV)),	
	[FUN]    = LAYOUT_redox(REDOX(_FUN)),	
};