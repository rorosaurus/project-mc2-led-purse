# Use an ESP32 to display GIFs on your Project Mc2 LED purse

[![Youtube Demo](demo.gif)](https://www.youtube.com/watch?v=3-5VtH-2Txw)

[YouTube - Proof of concept WiFi controller](https://www.youtube.com/watch?v=pXGxG_d0u60)

# Hardware
* Project Mc2 LED Purse ([Usually costs ~$6](https://camelcamelcamel.com/Project-Mc2-Toy-Light-Purse/product/B071LQR2QG)): [Amazon](https://smile.amazon.com/dp/B071LQR2QG/), [Adafruit article](https://blog.adafruit.com/2019/03/06/issue-16-hackspace-magazine-can-i-hack-it-a-smart-pixel-purse-neopixels-making-hackspacemag-biglesp/)
  * A cheap 16x32px LED display you can harvest. The deafult driver/app requires 3.5mm headphone jack and phone connected at all times, otherwise after 30 seconds your pattern will freeze, then turn off. You're also limited to like 6 colors.  So let's make our own driver!
  * If you want to daisy-chain from this display, it's missing an output socket and ribbon cables:
    * SMT 2x8 Male IDC Socket: [AliExpress](https://www.aliexpress.com/item/32989866598.html)
    * 16P IDC Cable (might have come with your panel): [AliExpress](https://www.aliexpress.com/item/32873766356.html)
* [PCB I designed](https://github.com/rorosaurus/esp32-hub75-driver) to drive HUB75 panels with an ESP32: [Buy on Tindie!](https://www.tindie.com/products/18357/)
  * This part is optional, but *greatly* simplifies your wiring!
  * If you don't want to use my PCB, you can wire the display yourself manually using dupont connectors following `ESP32_FORUM_PINOUT` from [MatrixHardware_ESP32_V0.h](https://github.com/pixelmatix/SmartMatrix/blob/teensylc/src/MatrixHardware_ESP32_V0.h)
* ESP32-DEVKIT-V1: [Amazon ($14 for 2)](https://smile.amazon.com/gp/product/B07Q576VWZ/)

Total cost should be quite low for a 32x16 scantype LED panel with Wifi/BT, powered by micro-USB, capable of: playing gifs, scrolling text, and FastLED!

## Assembly Instructions
Some assembly required! (Soldering ~46 pins.) Full assembly instructions and more detailed information can be found here: [`ASSEMBLY.md`](https://github.com/rorosaurus/esp32-hub75-driver/blob/master/ASSEMBLY.md)

## Powering your project
To find out the best way to power your ESP32 and LED panels, please head over to my power document: [`POWER.md`](https://github.com/rorosaurus/esp32-hub75-driver/blob/master/POWER.md)!

# Software
Use your preferred image editor to make your animated .gifs! I used Photoshop, but you could also use GIMP or something!

## Drivers
The ESP32 cannot directly communicate over USB with your computer to reprogram itself. It [uses an onboard chip](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/establish-serial-connection.html) to do so, which requires you to install a driver. For most ESP32's, you only need to install the `CP210X` driver for your appropriate operating system.

[Download the driver here](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

## Arduino
I would recommend using the following software with this board:
* https://www.arduino.cc/en/Main/Software - The Arduino IDE, to program everything!
  * https://github.com/espressif/arduino-esp32 - Install board manager support for ESP32
  * https://github.com/me-no-dev/arduino-esp32fs-plugin - This Arduino IDE plugin makes it simple to upload .gifs to your ESP32

## Libraries
You'll need to install (by downloading, renaming the folder to remove `-master`, and copying to `My Documents/Arduino/libraries`) a few libraries to drive the LED panel:
* https://github.com/pixelmatix/SmartMatrix/tree/teensylc
  * Please note, this is a specific branch of SmartMatrix. ESP32 support only exists in this branch.
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/marcmerlin/Framebuffer_GFX
* https://github.com/FastLED/FastLED
* https://github.com/marcmerlin/SmartMatrix_GFX

If you want to use Wifi, you will need to install additional libraries:
* https://github.com/me-no-dev/AsyncTCP
* https://github.com/me-no-dev/ESPAsyncWebServer

## Sketches
Note: some ESP32 dev boards require you to hold the BOOT button for ~3s to connect during sketch upload. If you're using my PCB and you have attached the auto-bootloader capacitor, you don't need to worry about this! If you're using my PCB, when uploading to the board via Arduino IDE, please use the board: `DOIT ESP32 DEVKIT V1`.

Keep in mind you'll need to tweak some variables to match your LED panel size, scanrate, etc.

You can also find some example sketches for Wifi/Bluetooth/etc. in your Arduino IDE after installing ESP32 support and all your libraries! Example sketches are your friend!

### FeatureDemo
The demo of SmartMatrix features, straight from the SmartMatrix example sketches! I've lightly modified it to remove a couple demos that get VERY bright and might use too much power. However there's still a couple that are pretty blinding - be careful!

### MultipleTextLayers
Lightly modified example sketch from the SmartMatrix example library. Perfect for a minimal sketch that displays scrolling text!

### SimpleGifExample
This is the bare minimum Arduino sketch that will display a gif you specify on the display.  

### AnimatedGIFs
This is a more complicated sketch that loops between all gifs in the specified folder on SPIFFS.

### WifiControlledGIFs
This builds on AnimatedGIFs sketch to add a simple wifi server to switch between gifs and control brightness! Note this requires more memory, so it might not work on larger displays (like 128x64.. sorry [Furret](https://github.com/rorosaurus/FurretTotem)!)


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

If you plan to daisy-chain these panels, please power the panels directly. Then siphon power from your panels to your ESP32. The ESP32 board traces are not designed to supply extra power for these types of panels, but you can safely get away with it for a single LED panel if you really want to keep it simple.

# More info
This project is forked from Marc Merlin's fantastic [AnimatedGIFs](https://github.com/marcmerlin/AnimatedGIFs) repository. Please check out that page for information about how to use this project in greater detail.
