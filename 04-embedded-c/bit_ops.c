#include <stdio.h>
#include <stdint.h>

void print_binary(uint8_t val) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}

int main(void) {
    uint8_t reg = 0b00000000;
    uint8_t mask = (1 << 3);

    printf("Initial reg:  "); print_binary(reg); printf("\n");

    reg = reg | mask;
    printf("After set:    "); print_binary(reg); printf("\n");

    if (reg & mask) {
        printf("Bit 3 is SET\n");
    }

    reg = reg ^ mask;
    printf("After toggle: "); print_binary(reg); printf("\n");

    reg = reg | mask;
    printf("Set again:    "); print_binary(reg); printf("\n");

    reg = reg & ~mask;
    printf("After clear:  "); print_binary(reg); printf("\n");

    return 0;
}