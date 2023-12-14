#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"


// see the json file for a nicer display
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHA] = LAYOUT_redox(REDOX(_HANDS_DOWN_VV)),	
	[UTIL] = LAYOUT_redox(REDOX(_UTIL)),	
	[NUM] = LAYOUT_redox(REDOX(_NUM)),	
	[NUM2] = LAYOUT_redox(REDOX(_NUM2)),	
	[SYM] = LAYOUT_redox(REDOX(_SYM)),	
	[WINNAV] = LAYOUT_redox(REDOX(_WINNAV)),	
	[FUN] = LAYOUT_redox(REDOX(_FUN)),	
};