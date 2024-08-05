# QMK Keymap


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