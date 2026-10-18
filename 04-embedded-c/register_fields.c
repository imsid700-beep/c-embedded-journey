
#include <stdint.h>
#include <stdio.h>

#define SPEED_SHIFT 2u
#define SPEED_MASK  (0x3u << SPEED_SHIFT)

void print_binary(uint8_t reg) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (reg >> i) & 1);
    }
    printf("\n");
}

uint8_t get_speed(uint8_t reg) {
    return (reg & SPEED_MASK) >> SPEED_SHIFT;
}

uint8_t set_speed(uint8_t reg, uint8_t value) {
    if (value > 3u) {
        return reg;
    }

    reg = reg & (uint8_t)~SPEED_MASK;
    reg = reg | (uint8_t)(value << SPEED_SHIFT);

    return reg;
}

int main(void) {
    uint8_t reg = 0b10100001;

    reg = set_speed(reg, 3);
    print_binary(reg);

    uint8_t speed = get_speed(reg);
    printf("%u\n", (unsigned int)speed);

    uint8_t test_values[] = {
        0x00, 0x04, 0x08, 0x0C
    };

    for (int i = 0; i < 4; i++) {
        printf("Register: ");
        print_binary(test_values[i]);
        printf("Speed: %u\n",
               (unsigned int)get_speed(test_values[i]));
    }

    uint8_t test_reg = set_speed(0xFF, 1);

    printf("set_speed(0xFF, 1) = 0x%02X\n",
           (unsigned int)test_reg);
    printf("Binary: ");
    print_binary(test_reg);

    uint8_t invalid_reg = set_speed(0xFF, 4);
    printf("set_speed(0xFF, 4) = 0x%02X\n",
           (unsigned int)invalid_reg);

    return 0;
}
