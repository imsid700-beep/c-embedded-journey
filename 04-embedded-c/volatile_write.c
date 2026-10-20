#include <stdint.h>

uint32_t data_reg;
volatile uint32_t data_reg_v;

void send_plain(void) {
    data_reg = 0x41;
    data_reg = 0x42;
}

void send_volatile(void) {
    data_reg_v = 0x41;
    data_reg_v = 0x42;
}