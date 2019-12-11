# Use an ESP32 to display GIFs on your Project Mc2 LED purse

[![Youtube Demo](demo.gif)](https://www.youtube.com/watch?v=3-5VtH-2Txw)

[YouTube - Proof of concept WiFi controller](https://www.youtube.com/watch?v=pXGxG_d0u60)

## Hardware (BOM)
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

## Software
For links to software I recommend using, please see [`SOFTWARE.md`](https://github.com/rorosaurus/esp32-hub75-driver/blob/master/SOFTWARE.md)

Please note: my PCB works with [SmartMatrix](https://github.com/pixelmatix/SmartMatrix/tree/teensylc) library, not [PxMatrix](https://github.com/2dom/PxMatrix).

## Mounting
I have no solution to mount the LED display anywhere. For the time being I'm using half of the purse shell as an ugly mount. This display is missing the common screw mounts on HUB75 panels. I'd love to hear your mounting ideas!

## Power usage and powering your project
Brightness | Power
-----------|------
25/255 | 1W (0.2A @ 5V)
255/255 | 5W (1A @ 5V)

If you plan to daisy-chain these panels: please power the panels directly, then siphon power from your panels to your ESP32. The ESP32 board traces are not designed to supply extra power for these types of panels. However, you can safely get away with it for a single LED panel if you really want to keep it simple. For more info, see [`POWER.md`](https://github.com/rorosaurus/esp32-hub75-driver/blob/master/POWER.md)!
