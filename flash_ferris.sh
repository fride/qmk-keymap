#!/usr/bin/env bash
# set -euxo pipefail

# until [ $(find /dev -maxdepth 1 -name cu.usbmodem* -print -quit) ] 
# do
#     echo "No usb modem found. Please reset your divice."
#     sleep 3
# done

for usbdevice in /dev/cu.usbmodem*; do
    echo Flashing to ${usbdevice}
    dfu-util -a 0 -d 0483:DF11 -s 0x8000000:leave -D /Users/jgf/code/private/totem-qmk/result/result/ferris_0_2_base_fride.bin
    break
done
