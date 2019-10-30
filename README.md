# Use an ESP32 to display GIFs on your Project Mc2 LED purse

[![Youtube Demo](demo.gif)](https://www.youtube.com/watch?v=3-5VtH-2Txw)

[YouTube - Proof of concept WiFi controller](https://www.youtube.com/watch?v=pXGxG_d0u60)

# Hardware
* Project Mc2 LED Purse ([Usually costs ~$6](https://camelcamelcamel.com/Project-Mc2-Toy-Light-Purse/product/B071LQR2QG)): [Amazon](https://smile.amazon.com/dp/B071LQR2QG/), [Adafruit article](https://blog.adafruit.com/2019/03/06/issue-16-hackspace-magazine-can-i-hack-it-a-smart-pixel-purse-neopixels-making-hackspacemag-biglesp/)
  * A cheap 16x32px LED display you can harvest. The deafult driver/app requires 3.5mm headphone jack and phone connected at all times, otherwise after 30 seconds your pattern will freeze, then turn off. You're also limited to like 6 colors.  So let's make our own driver!
  * If you want to daisy-chain from this display, it's missing an output socket and ribbon cables:
    * SMT 2x8 Male IDC Socket: [AliExpress](https://www.aliexpress.com/item/32989866598.html)
    * 16P IDC Cable (might have come with your panel): [AliExpress](https://www.aliexpress.com/item/32873766356.html)
* [PCB I designed to drive HUB75 panels with an ESP32](https://github.com/rorosaurus/esp32-hub75-driver) (I hope to sell this on Tindie shortly for < $10)
  * This part is optional, but *greatly* simplifies your wiring!
  * Female Pin Header 2X8 (connects this driver to the HUB75 panel): [Amazon](https://smile.amazon.com/gp/product/B07VJ3JCLT/), [AliExpress](https://www.aliexpress.com/item/32747224548.html)
  * If you don't want to use my PCB, you can wire the display yourself manually using dupont connectors following `ESP32_FORUM_PINOUT` from [MatrixHardware_ESP32_V0.h](https://github.com/pixelmatix/SmartMatrix/blob/teensylc/src/MatrixHardware_ESP32_V0.h)
* ESP32-DEVKIT-V1: [Amazon ($7)](https://smile.amazon.com/gp/product/B07Q576VWZ/), [AliExpress ($4)](https://www.aliexpress.com/item/32902307791.html)

Total cost should be <$20 for a 32x16 scantype LED panel, with Wifi/BT, powered by micro-USB, capable of playing gifs, scrolling text, and FastLED!

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

### WifiControlledGIFs
This builds on AnimatedGIFs sketch to add a simple wifi server to switch between gifs. Note this requires more memory, so it might not work on larger displays (like 128x64.. sorry [Furret](https://github.com/rorosaurus/FurretTotem)!)


## GIFs
The gifs are loaded onto the ESP32's SPIFFS: an integrated filesystem that shares the same flash memory as your program.  You have 4MB shared. Edit your own gifs using Photoshop or some other editor, then use [this Arduino IDE plugin](https://github.com/me-no-dev/arduino-esp32fs-plugin) to upload .gifs to your ESP32!

# Mounting and button
I have no solution to mount the LED display anywhere. For the time being I'm using half of the purse shell as an ugly mount. This display is missing the common screw mounts on HUB75 panels. I'd love to hear your mounting ideas!

You can reuse the button the purse comes with, wiring it to a GPIO pin and GND. But I've noticed that button seems super fidget-y compared to normal cheap pushbuttons.

# Power usage
Brightness | Power
-----------|------
25/255 | 1W (0.2A @ 5V)
255/255 | 5W (1A @ 5V)

# More info
This project is forked from Marc Merlin's fantastic [AnimatedGIFs](https://github.com/marcmerlin/AnimatedGIFs) repository. Please check out that page for information about how to use this project in greater detail.
