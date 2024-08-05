#!/usr/bin/env bash
# set -euxo pipefail

until [ $(find /dev -maxdepth 1 -name cu.usbmodem* -print -quit) ] 
do
    echo "No usb modem found. Please reset your divice."
    sleep 3
done

for usbdevice in /dev/cu.usbmodem*; do
    echo Flashing to ${usbdevice}
    avrdude -p atmega32u4 -c avr109 -U flash:w:/Users/jgf/code/private/totem-qmk/result/result/redox_rev1_base_fride.hex:i -P "${usbdevice}" -C '/Applications/QMK Toolbox.app/Contents/Resources/avrdude.conf'
    # avrdude -p atmega32u4 -c avr109 -U flash:w:/Users/jgf/code/private/totem-qmk/result/result/redox_rev1_base_fride.hex:i -P /dev/cu.usbmodem14601 -C avrdude.conf
    break
done
