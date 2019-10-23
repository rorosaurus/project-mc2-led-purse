# Use an ESP32 to display GIFs on your Project Mc2 LED purse

[![Youtube Demo](demo.gif)](https://www.youtube.com/watch?v=3-5VtH-2Txw)

# Software

## Arduino
This project uses [the Arduino IDE](https://www.arduino.cc/en/Main/Software) to program everything!  You also need to [install board manager support for ESP32](https://github.com/espressif/arduino-esp32).

## Libraries
The below sketches will not compile unless you install all the required libraries listed here. I recommend installing them by downloading the repository and copying the contents to `My Documents/Arduino/libraries`.

* https://github.com/pixelmatix/SmartMatrix/tree/teensylc
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/marcmerlin/Framebuffer_GFX
* https://github.com/FastLED/FastLED
* https://github.com/marcmerlin/SmartMatrix_GFX

## Sketches

### SimpleGifExample
This is the bare minimum Arduino sketch that will display a gif you specify on the display.  

### AnimatedGIFs
This is a more complicated sketch that loops between all gifs in the specified folder on SPIFFS.



## GIFs
The gifs are loaded onto the ESP32's SPIFFS: an integrated filesystem that shares the same flash memory as your program.  You have 4MB shared. Edit your own gifs using Photoshop or some other editor, then use [this Arduino IDE plugin](https://github.com/me-no-dev/arduino-esp32fs-plugin) to upload .gifs to your ESP32!

# Hardware and wiring
I recommend using the [PCB I designed](https://github.com/rorosaurus/esp32-hub75-driver) to simplify your wiring. If you don't want to do that, you can wire the display yourself manually using `ESP32_FORUM_PINOUT` from [MatrixHardware_ESP32_V0.h](https://github.com/pixelmatix/SmartMatrix/blob/teensylc/src/MatrixHardware_ESP32_V0.h)

# More info
This project is forked from Marc Merlin's fantastic [AnimatedGIFs](https://github.com/marcmerlin/AnimatedGIFs) repository. Please check out that page for information about how to use this project in greater detail.
