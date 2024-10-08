

build: clean
    DOCKER_BUILDKIT=1 docker buildx build -o type=local,dest=result . 

totem:
    DOCKER_BUILDKIT=1 docker buildx build --build-arg="KEYBOARD=totem" -o type=local,dest=result . 
redox:
    DOCKER_BUILDKIT=1 docker buildx build --build-arg="KEYBOARD=redox" -o type=local,dest=result . 
planck:
    DOCKER_BUILDKIT=1 docker buildx build --build-arg="KEYBOARD=planck/rev6" -o type=local,dest=result . 
ferris:
    DOCKER_BUILDKIT=1 docker buildx build --build-arg="KEYBOARD=ferris/0_2" -o type=local,dest=result . 

planck_flash: planck
    dfu-util -a 0 -d 0483:DF11 -s 0x08000000:leave -D /Users/jgf/code/private/totem-qmk/result/result/planck_rev6_fride.bin
    
ferris_flash: ferris
    ./flash_ferris.sh    

fetch_totem_src:
    git submodule add -f git@github.com:GEIGEIGEIST/qmk-config-totem.git
    git submodule sync
    ( cd qmk-config-totem && git checkout main )

fetch_qmk:
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/qmk/qmk_firmware
    echo "Update git sub-modules..."
    git submodule sync --recursive
    git submodule update --init --recursive --progress
    ( cd qmk_firmware && git checkout "master" )

flash: 
    cp result/result/totem_fride.uf2 /Volumes/RPI-RP2/

redox-flash: redox
    ./flash_redox.sh    

clean:
    rm -rf result/result/*