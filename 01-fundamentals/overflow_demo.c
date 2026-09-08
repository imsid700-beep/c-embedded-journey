#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t counter = 255;
    counter = counter + 1;
    printf("counter after overflow: %u\n", counter);
    return 0;
}
