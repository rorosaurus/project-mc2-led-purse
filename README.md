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
Note: some ESP32 dev boards require you to hold the BOOT button for ~3s to connect during sketch upload.

### SimpleGifExample
This is the bare minimum Arduino sketch that will display a gif you specify on the display.  

### AnimatedGIFs
This is a more complicated sketch that loops between all gifs in the specified folder on SPIFFS.



## GIFs
The gifs are loaded onto the ESP32's SPIFFS: an integrated filesystem that shares the same flash memory as your program.  You have 4MB shared. Edit your own gifs using Photoshop or some other editor, then use [this Arduino IDE plugin](https://github.com/me-no-dev/arduino-esp32fs-plugin) to upload .gifs to your ESP32!

# Hardware and wiring
I recommend using the [PCB I designed to drive HUB75 panels with an ESP32](https://github.com/rorosaurus/esp32-hub75-driver), which simplifies your wiring. If you don't want to do that, you can wire the display yourself manually using `ESP32_FORUM_PINOUT` from [MatrixHardware_ESP32_V0.h](https://github.com/pixelmatix/SmartMatrix/blob/teensylc/src/MatrixHardware_ESP32_V0.h)

You can reuse the button the purse comes with, wiring it to a GPIO pin and GND. But I've noticed that button seems super fidget-y compared to normal cheap pushbuttons.

I have no solution to mount the LED display anywhere. For the time being I'm using half of the purse shell as an ugly mount.

# Power usage
Brightness | Power
-----------|------
25/255 | 1W (0.2A @ 5V)
255/255 | 5W (1A @ 5V)

# More info
This project is forked from Marc Merlin's fantastic [AnimatedGIFs](https://github.com/marcmerlin/AnimatedGIFs) repository. Please check out that page for information about how to use this project in greater detail.
