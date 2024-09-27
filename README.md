# QMK Keymap

## Focal (E on a thumb)

```
  ___V___, ___L___, ___H___, ___G___, ___K___,      ___Q___, ___F___, ___O___, ___U___, ___J___
  ___S___, ___R___, ___N___, ___T___, ___B___,      ___Y___, ___C___, ___A___, ___I___, _MAGIC_
  ___Z___, ___X___, ___M___, ___D___, ___P___,      _SQUOT_, ___W___, __DOT__, _SEMIC_, _COMMA_
                    NAV_SPC, OS_LSFT, OS_LSFT,      OS_LSFT, OS_LSFT, ___E___
```

## Dhorf (e)

## Hands Down Promethium
```
b f d l j ; u o y p
s n t h k , a e i c
v w g m x - . ' = /
      r
```
      

# Repeat Voodo

```c

   case REP_SFT:
    // TODO this only ever returns an n
     if (record->event.pressed) {
        if (record->tap.count > 0) {
          keyrecord_t press;
          press.event.type = KEY_EVENT;
          press.tap.count = 1;
          press.event.pressed = true;
          process_repeat_key(QK_REPEAT_KEY, &press);
          keyrecord_t release;
          release.event.type = KEY_EVENT;
          release.tap.count = 1;
          release.event.pressed = false;
          process_repeat_key(QK_REPEAT_KEY, &release);
          return PROCESS_RECORD_RETURN_TRUE;
        }
      }
      break;
```