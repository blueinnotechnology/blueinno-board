# Blueinno-Board
[![Release](https://img.shields.io/github/v/release/blueinnotechnology/blueinno-board?style=plastic)](https://github.com/blueinnotechnology/blueinno-board/releases)

Arduino core repository for all Blueinno Boards

# Documentation

> TO BE UPDATED

See https://arduino-pico.readthedocs.io/en/latest/ along with the examples for more detailed usage information.


# Supported Boards
* Blueinno AIOT RP2040

# Installing via Arduino Boards Manager

> TO BE UPDATED

Open up the Arduino IDE and go to File->Preferences.

In the dialog that pops up, enter the following URL in the "Additional Boards Manager URLs" field:

https://github.com/blueinnotechnology/blueinno-board/releases/latest/download/package_rp2040_index.json

![image](https://user-images.githubusercontent.com/11875/111917251-3c57f400-8a3c-11eb-8120-810a8328ab3f.png)

Hit OK to close the dialog.

Go to Tools->Boards->Board Manager in the IDE

Type "inno" in the search box and select "Add":

![image](https://user-images.githubusercontent.com/11875/111917223-12063680-8a3c-11eb-8884-4f32b8f0feb1.png)

# Installing via GIT

To install via GIT, you will need to clone this repo into your Arduino hardware directory.  The location of this directory depends on your OS:

```
mkdir -p ~/Arduino/hardware/pico
git clone https://github.com/earlephilhower/arduino-pico.git ~/Arduino/hardware/pico/rp2040
cd ~/Arduino/hardware/pico/rp2040
git submodule update --init
cd pico-sdk
git submodule update --init
cd ../tools
python3 ./get.py
```

# Build OTA Bootloader
```
cd ota
./make-ota.sh
```

# Uploading Sketches

> TO BE UPDATED

To upload your first sketch, you will need to hold the BOOTSEL button down while plugging in the Pico to your computer.
Then hit the upload button and the sketch should be transferred and start to run.

After the first upload, this should not be necessary as the `arduino-pico` core has auto-reset support.
Select the appropriate serial port shown in the Arduino Tools->Port->Serial Port menu once (this setting will stick and does not need to be
touched for multiple uploads).   This selection allows the auto-reset tool to identify the proper device to reset.
Them hit the upload button and your sketch should upload and run.

In some cases the Pico will encounter a hard hang and its USB port will not respond to the auto-reset request.  Should this happen, just
follow the initial procedure of holding the BOOTSEL button down while plugging in the Pico to enter the ROM bootloader.

# Tutorials from Across the Web

> TO BE UPDATED

Here are some links to coverage and additional tutorials for using `arduino-pico`
* The File:: class is taken from the ESP8266.  See https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html
* Arduino Support for the Pi Pico available! And how fast is the Pico? - https://youtu.be/-XHh17cuH5E
* Pre-release Adafruit QT Py RP2040 - https://www.youtube.com/watch?v=sfC1msqXX0I
* Adafruit Feather RP2040 running LCD + TMP117 - https://www.youtube.com/watch?v=fKDeqZiIwHg
* Demonstration of Servos and I2C in Korean - https://cafe.naver.com/arduinoshield/1201
* Home Assistant Pico W integration starter project using Arduino - https://github.com/daniloc/PicoW_HomeAssistant_Starter
* Tutorials for the Raspberry Pi Pico / uPesy RP2040 DevKit board 
    - English version: https://www.upesy.com/blogs/tutorials/best-tutorials-for-rpi-pi-pico-with-arduino-code
    - French version: https://www.upesy.fr/blogs/tutorials/best-tutorials-for-rpi-pi-pico-with-arduino-code

# Licensing and Credits
* The [Arduino-pico](https://github.com/earlephilhower/arduino-pico/tree/master) is by Earle F. Philhower, III and licensed under the LGPL.
* The [Arduino IDE and ArduinoCore-API](https://arduino.cc) are developed and maintained by the Arduino team. The IDE is licensed under GPL.
* The [RP2040 GCC-based toolchain](https://github.com/earlephilhower/pico-quick-toolchain) is licensed under under the GPL.
* The [Pico-SDK](https://github.com/raspberrypi/pico-sdk) is by Raspberry Pi (Trading) Ltd and licensed under the BSD 3-Clause license.
* [Arduino-Pico](https://github.com/earlephilhower/arduino-pico) core files are licensed under the LGPL.
* [LittleFS](https://github.com/ARMmbed/littlefs) library written by ARM Limited and released under the [BSD 3-clause license](https://github.com/ARMmbed/littlefs/blob/master/LICENSE.md).
* [UF2CONV.PY](https://github.com/microsoft/uf2) is by Microsoft Corporation and licensed under the MIT license.
* Networking and filesystem code taken from the [ESP8266 Arduino Core](https://github.com/esp8266/Arduino) and licensed under the LGPL.
* DHCP server for AP host mode from the [Micropython Project](https://micropython.org), distributed under the MIT License.
* [FreeRTOS](https://freertos.org) is Copyright Amazon.com, Inc. or its affiliates, and distributed under the MIT license.
* [lwIP](https://savannah.nongnu.org/projects/lwip/) is (c) the Swedish Institute of Computer Science and licenced under the BSD license.
* [BearSSL](https://bearssl.org) library written by Thomas Pornin, is distributed under the [MIT License](https://bearssl.org/#legal-details).
* [UZLib](https://github.com/pfalcon/uzlib) is copyright (c) 2003 Joergen Ibsen and distributed under the zlib license.
* [LEAmDNS](https://github.com/LaborEtArs/ESP8266mDNS) is copyright multiple authors and distributed under the MIT license.
* [http-parser](https://github.com/nodejs/http-parser) is copyright Joyent, Inc. and other Node contributors.
* WebServer code modified from the [ESP32 WebServer](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer) and is copyright (c) 2015 Ivan Grokhotkov and others
