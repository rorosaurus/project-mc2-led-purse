#ifndef animatedgif_config
#define animatedgif_config

// control the maximum dimensions of gif decoding
#define gif_width 32
#define gif_height 16

/* GifDecoder needs lzwMaxBits
 * The lzwMaxBits value of 12 supports all GIFs, but uses 16kB RAM
 * lzwMaxBits can be set to 10 or 11 for small displays, 12 for large displays
 * All 32x32-pixel GIFs tested work with 11, most work with 10
 */
const int lzwMaxBits = 12;

//#define NEOMATRIX // Switch to NEOMATRIX backend from native SMARTMATRIX backend
//#define NEOPIXEL_MATRIX  // If NEOMATRIX, use FastLED::NeoMatrix, not SmartMatrix_GFX

// enable debug mode over serial?
//#define DEBUGLINE 16

// If the matrix is a different size than the GIFs, set the offset for the upper left corner
// (negative or positive is ok).
extern int OFFSETX;
extern int OFFSETY;
extern int FACTX;
extern int FACTY;

// Note, you can use an sdcard on ESP32 or ESP8266 if you really want,
// but if your data fits in built in flash, why not use it?
// Use built in flash via SPIFFS/FATFS
// ESP32: https://github.com/me-no-dev/arduino-esp32fs-plugin
// https://github.com/marcmerlin/esp32_fatfsimage/blob/master/README.md
#if defined(ESP32)
    #include <SPIFFS.h>
    #define FSO SPIFFS
    //#include "FFat.h"
    //#define FSO FFat
    //#define FSOFAT
    // Do NOT add a trailing slash, or things will fail
      #define GIF_DIRECTORY "/gifs"
#endif

#endif
