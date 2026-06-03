#include "types.h"

#define FRAMEBUFFER 0x000B8000

void write_letter_to_framebuffer(uint8_t letter, uint16_t, row, uint16_t col, uint8_t text_color, uint8_t bg_color) {
    volatile uint16_t *framebuffer = (volatile uint16_t*) FRAMEBUFFER;

    uint16_t letter_framebuffer = (0x00FF & letter);
    uint16_t bg_color_framebuffer = (0x000F & bg_color) << 12;
    uint16_t text_color_framebuffer = (0x00F & text_color) << 8;

    framebuffer[col + row*80] = letter_framebuffer | text_color_framebuffer | bg_color_framebuffer;
}

int kernel_main() {
    for (int j=0; j<80; j++) {
        for (int i=0; i<25; i++) {
            write_letter_to_framebuffer('X', i, j, GREEN, WHITE);
        }
    }
    return 0;
}
