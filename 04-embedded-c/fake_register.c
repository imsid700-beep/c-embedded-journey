#include <stdio.h>
#include <stdint.h>

static uint32_t fake_storage = 0;

#define FAKE_ODR (*(volatile uint32_t *)&fake_storage)

int main(void) {
    FAKE_ODR |= (1u << 5);
    printf("after set bit 5:   0x%08X\n", (unsigned int)FAKE_ODR);

    FAKE_ODR |= (1u << 0);
    printf("after set bit 0:   0x%08X\n", (unsigned int)FAKE_ODR);

    FAKE_ODR &= ~(1u << 5);
    printf("after clear bit 5: 0x%08X\n", (unsigned int)FAKE_ODR);

    return 0;
}