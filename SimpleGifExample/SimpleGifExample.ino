#define BASICSPIFFS
// Use NeoMatrix API, even if it may use the SmartMatrix backend depending on the CPU
#define NEOMATRIX
#define DISABLE_MATRIX_TEST
#include "GifAnim_Impl.h"


// If the matrix is a different size than the GIFs, allow panning through the GIF
// while displaying it, or bouncing it around if it's smaller than the display
int OFFSETX = 0;
int OFFSETY = 0;
int FACTX = 0;
int FACTY = 0;

// this is the location of the gif you want to loop
const char *pathname = "/gifs32x16/corkscrew.gif";

// Setup method runs once, when the sketch starts
void setup() {
    sav_setup();
    if (sav_newgif(pathname)) delay(100000); // while 1 loop only triggers watchdog on ESP chips
}

// loop method continuously repeats after setup() is run
void loop() {
    sav_loop();
}
