#include <gb/gb.h>
#include <stdint.h>
#include "sgb_border.h"

#include "border_data.h"
/*

- The entire image should be 256 x 224 pixels

- The game area in the center should be:
  - 160 x 144 pixels, from (48,40) to (207,183)
  - The pixels in the game area at the center of the image should be set
    to 100% Alpha Transparency (as in the example image). If this is not
    done then the game area may share a palette color with other parts
    of the border leading to tile pattern flashing while the border loads.

- See the pandocs for additional details
  - https://gbdev.io/pandocs/SGB_Functions.html
  - https://gbdev.io/pandocs/SGB_Color_Palettes.html
*/

void main(void) {

    // Wait 4 frames
    // For SGB on PAL SNES this delay is required on startup, otherwise borders don't show up
    for (uint8_t i = 4; i != 0; i--) vsync();

    // The display must be ON before calling set_sgb_border()
    DISPLAY_ON;
    set_sgb_border(SGB_border_chr, sizeof(SGB_border_chr), SGB_border_map, sizeof(SGB_border_map), SGB_border_pal, sizeof(SGB_border_pal));
    while(1) {
        vsync();
    }
}