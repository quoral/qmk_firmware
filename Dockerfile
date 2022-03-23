FROM qmkfm/base_container

VOLUME /qmk_firmware
WORKDIR /qmk_firmware
COPY . .
RUN apt update && apt install teensy-loader-cli

CMD make all:default
