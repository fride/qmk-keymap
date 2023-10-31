#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"


#define REDOX(k) CONV_REDOX(k)
#define CONV_REDOX( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
            k59, k60, k61,        k64, k65, k66 \
) \
{ \
    { KC_GRV, KC_7, KC_5, KC_3, KC_1, KC_9, KC_NO }, \
    { KC_TAB, k15, k16, k17, k18, k19, KC_NO }, \
    { KC_ESC, k29, k30, k31, k32, k33, KC_NO }, \
    { OS_LSFT, k43, k44, k45, k46, k47, KC_NO }, \
    { OS_LCTL, KC_NO, KC_NO, k59, k60, k61, OS_LSFT }, \
    { KC_SLSH, KC_6, KC_4, KC_2, KC_0, KC_8, KC_NO }, \
    { KC_MINS, k26, k25, k24, k23, k22, KC_NO }, \
    { KC_BSPC, k40, k39, k38, k37, k36, KC_NO }, \
    { KC_ENTER, k54, k53, k52, k51, k50, KC_NO }, \
    { OS_LCTL, KC_NO, KC_NO, k66, k65, k64, OS_LSFT }  \
}

#define MY_REDOX(...) LAYOUT(__VA_ARGS__)

/*
q l d w v   j f o u ,
n r t s g   y h a e i
x z m c b   k p ' / .
*/

/*
     x  f  m  p  b   -  .  /  ,  q
  z  r  s  n  t  g   '  a  e  i  h  j
     w  c  l  d  v   :  u  o  y  k
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   // gallium with nicer B!
   [ALPHA]  = MY_REDOX(
        _XXXXX_, KC_1, KC_2,  KC_3,     KC_4,          KC_5,                                           KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     QK_BOOT,
        KC_CAPS, _______________HANDS_D___L1________________, _XXXXX_,                      _XXXXX_,   _______________HANDS_D___R1________________, KC_SCLN,
                 _______________HANDS_D___L2________________, _XXXXX_,                      _XXXXX_,   _______________HANDS_D___R2________________, 
        KC_QUES, _______________HANDS_D___L3________________, _XXXXX_, _XXXXX_,    _XXXXX_, _XXXXX_,   _______________HANDS_D___R3________________, KC_EXLM,
        _XXXXX_, _XXXXX_, _XXXXX_, _XXXXX_,      MEH_SPC,       OS_LGUI, OS_LALT,                     OS_LALT, OS_LCTL,       MAGIC_GUI, _XXXXX_, _XXXXX_, _XXXXX_, _XXXXX_
    ),

   [SYM] =  MY_REDOX(
        _XXXXX_, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_BOOT,
        _______, KC_QUOT, KC_LT,   KC_GT,   KC_DQUO, KC_DOT,  _______,                         _______, KC_AMPR, _______, KC_LBRC, KC_RBRC, KC_PERC, _______, 
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH, _______,                         _______, KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
        _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_SLSH, _______, _______, _______,       _______, _______, KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,   _______,
        _XXXXX_, _XXXXX_, _XXXXX_, _XXXXX_, MEH_SPC, OS_LSFT, OS_LSFT,                          OS_LCTL, OS_LCTL,MAGIC_GUI, _XXXXX_, _XXXXX_, _XXXXX_, _XXXXX_
    ),
   [SYM2] =  MY_REDOX(
        _XXXXX_, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_BOOT,
        _______, KC_QUOT, KC_LT,   KC_GT,   KC_DQUO, KC_DOT,  _______,                         _______, KC_AMPR, _______, KC_LBRC, KC_RBRC, KC_PERC, _______, 
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH, _______,                         _______, KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
        _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_SLSH, _______, _______, _______,       _______, _______, KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,   _______,
        _XXXXX_, _XXXXX_, _XXXXX_, _XXXXX_, MEH_SPC, OS_LSFT, OS_LSFT,                          OS_LCTL, OS_LCTL,MAGIC_GUI, _XXXXX_, _XXXXX_, _XXXXX_, _XXXXX_
    ),

   [NUM] = MY_REDOX(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F12   ,KC_F1    ,KC_F2  , KC_F3  , KC_F4   ,KC_F5  ,                                             KC_F6    ,KC_F7  , KC_F8 , KC_F9   ,KC_F10 ,KC_F11 ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC  ,KC_7,     KC_5,    KC_3 ,   KC_1  ,  KC_9,    KC_F11,                            KC_F12 ,   KC_8,    KC_0,    KC_2,    KC_4,   KC_6,    KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼                         ┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_Q    ,KC_LT,   KC_PERC, KC_LPRN,KC_LBRC, KC_LCBR,  KC_NO,                               KC_NO,   KC_EQL, KC_QUES, KC_QUOT, KC_PLUS, KC_PAST, KC_MINS,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT ,KC_GT,   KC_DOLLAR,KC_RPRN,KC_RBRC, KC_RCBR,KC_NO,   KC_NO,             KC_NO,    KC_NO,  KC_AT,   KC_EXLM, KC_DQUO, KC_MINS,  KC_SLASH, KC_RSFT,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       KC_NO ,KC_UP   ,KC_UP   ,KC_DOWN ,       OS_LSFT ,    NUMWORD , KC_DEL ,        KC_BSPC , TT(SYM),     SYM_SPC ,     KC_LEFT ,KC_RIGHT ,ARROW_R,KC_NO
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),

   [UTIL] = MY_REDOX(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F12   ,KC_F1    ,KC_F2  , KC_F3  , KC_F4   ,KC_F5  ,                                             KC_F6    ,KC_F7  , KC_F8 , KC_F9   ,KC_F10 ,KC_F11 ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC  ,________________UTILITY_L1________________ ,KC_F19  ,                          KC_PIPE ,________________UTILITY_R1________________,KC_EQL  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_Q    ,________________UTILITY_L2________________ ,OS_MEH  ,                          KC_DLR  ,________________UTILITY_R2________________ ,KC_MINS ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT ,________________UTILITY_L3________________ ,KC_NO   ,  KC_NO ,        KC_HOME ,KC_NO   ,________________UTILITY_R3________________ ,KC_RSFT ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       KC_NO ,KC_UP   ,KC_UP   ,KC_DOWN ,       OS_LSFT ,    NUMWORD , KC_DEL ,        KC_BSPC , TT(SYM),     SYM_SPC ,     KC_LEFT ,KC_RIGHT ,ARROW_R,KC_NO
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    )
};
