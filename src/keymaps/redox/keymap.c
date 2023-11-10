#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"


// see the json file for a nicer display
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHA] = LAYOUT_redox(REDOX(_BIRD_JAN)),	
	[UTIL] = LAYOUT_redox(REDOX(_UTIL)),	
	[NUM] = LAYOUT_redox(REDOX(_NUM)),	
	[WINNAV] = LAYOUT_redox(REDOX(_WINNAV)),	
	[FUN] = LAYOUT_redox(REDOX(_FUN)),	
};