#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"

// Layout aliases for json keymap
#define LAYOUT_redox(...) LAYOUT(__VA_ARGS__)

#define CONV_REDOX( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
            k59, k60, k61,        k64, k65, k66 \
) \
     KC_NO   ,KC_7    ,KC_5    ,KC_3    ,KC_1    ,KC_9    ,                                            KC_8    ,KC_0    ,KC_2    ,KC_4    ,KC_6  ,KC_NO   , \
     KC_TAB  ,k15     ,k16     ,k17     ,k18     ,k19     ,KC_F11   ,                         KC_F12  ,k22     ,k23     ,k24     ,k25     ,k26     ,KC_BSLS , \
     OS_LSFT ,k29     ,k30     ,k31     ,k32     ,k33     ,KC_DLR  ,                         KC_DLR   ,k36     ,k37     ,k38     ,k39     ,k40 ,    OS_LSFT , \
     KC_LSFT ,k43     ,k44     ,k45     ,k46     ,k47     ,KC_NO   ,QK_BOOT ,        QK_BOOT ,KC_NO   ,k50     ,k51     ,k52     ,k53     ,k54     ,KC_RSFT , \
     KC_LCTL ,KC_LALT ,KC_LPRN ,KC_RPRN   ,     k59     ,    k60     ,k61     ,        k64      ,k65     ,k66     ,KC_LBRC ,KC_RBRC ,KC_NO   ,KC_NO 

#define REDOX(k) CONV_REDOX(k)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHA]  = LAYOUT_redox(REDOX(_HANDS_DOWN)),	
	[ALPHA2]  = LAYOUT_redox(REDOX(_UML)),	
	[UTIL]   = LAYOUT_redox(REDOX(_UTIL)),	
	[NUM]    = LAYOUT_redox(REDOX(_NUM)),	
	[SYM]    = LAYOUT_redox(REDOX(_SYM)),	
	[WINNAV] = LAYOUT_redox(REDOX(_WINNAV)),	
	[FUN]    = LAYOUT_redox(REDOX(_FUN)),	
};