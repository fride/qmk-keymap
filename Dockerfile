FROM docker.io/qmkfm/base_container:latest as base
RUN <<EOF
    pip install qmk
    qmk setup -y -H /qmk_firmware
EOF
WORKDIR /qmk_firmware
RUN <<EOF
git fetch && git pull -r
git status
mkdir -p /qmk_firmware/keyboards/totem
mkdir -p /qmk_firmware/users/fride
mkdir -p /qmk_firmware/keyboards/totem/keymaps/totem
mkdir -p /qmk_firmware/keyboards/redox/keymaps/fride
EOF

COPY ./qmk-config-totem/totem/ /qmk_firmware/keyboards/totem/
COPY ./src/keymaps/totem/ /qmk_firmware/keyboards/totem/keymaps/fride/
COPY ./src/keymaps/planck/ /qmk_firmware/keyboards/planck/keymaps/fride/
COPY ./src/keymaps/redox/ /qmk_firmware/keyboards/redox/keymaps/fride/
COPY ./src/keymaps/ferris/ /qmk_firmware/keyboards/ferris/keymaps/fride/
COPY ./src/users/fride/ /qmk_firmware/users/fride/
# make bash as default command
CMD ["/bin/bash"]

ARG KEYMAP=fride
ARG KEYBOARD=totem
FROM base as build
RUN mkdir  /qmk_firmware/.build
RUN qmk format-json /qmk_firmware/keyboards/redox/keymaps/fride/keymap-yann.json >/qmk_firmware/.build/keymap-yann.json
#RUN cp /qmk_firmware/keyboards/redox/keymaps/fride/keymap-yann.json /qmk_firmware/.build/keymap-yann.json
RUN qmk json2c -o /qmk_firmware/.build/generated_keyboard.c /qmk_firmware/keyboards/redox/keymaps/fride/keymap-yann.json
RUN qmk compile -kb ${KEYBOARD} -km fride

FROM scratch as result
COPY  --from=build /qmk_firmware/.build ./result/