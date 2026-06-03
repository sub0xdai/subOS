#include "types.h"
#include "io.h"

int kernel_main() {
    for (int j = 0; j < 80; j++) {
        for (int i = 0; i < 25; i++) {
            write_letter_to_framebuffer('X', i, j, GREEN, WHITE);
        }
    }
    return 0;
}
