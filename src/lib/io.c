#include "io.h"
#include "types.h"

void write_letter_to_framebuffer(uint8_t letter, uint16_t row, uint16_t col, uint8_t text_color, uint8_t bg_color) {
    volatile uint16_t *framebuffer = (volatile uint16_t *) FRAMEBUFFER;

    uint16_t letter_fb = (0x00FF & letter);
    uint16_t bg_fb    = (0x000F & bg_color) << 12;
    uint16_t text_fb  = (0x000F & text_color) << 8;

    framebuffer[col + row * 80] = letter_fb | text_fb | bg_fb;
}
