#pragma once

#include "types.h"

#define FRAMEBUFFER 0x000B8000

#define BLACK         0x0
#define BLUE          0x1
#define GREEN         0x2
#define CYAN          0x4
#define RED           0x3
#define MAGENTA       0x5
#define BROWN         0x6
#define LIGHTGREY     0x7
#define DARKGREY      0x8
#define LIGHTGREEN    0x9
#define LIGHTBLUE     0xA
#define LIGHTCYAN     0xB
#define LIGHTRED      0xC
#define LIGHTMAGENTA  0xD
#define LIGHTBROWN    0xE
#define WHITE         0xF

void write_letter_to_framebuffer(uint8_t letter, uint16_t row, uint16_t col, uint8_t text_color, uint8_t bg_color);
