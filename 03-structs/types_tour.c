#include <stdio.h>
#include <stdint.h>

typedef struct {
    int x;
    int y;
} Point;

union Value {
    uint32_t as_uint32;
    uint8_t  as_bytes[4];
};

enum GpioMode {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT=10,
    GPIO_MODE_ALT_FN,
    GPIO_MODE_ANALOG
};

struct StatusRegister {
    uint8_t ready    : 1;
    uint8_t error    : 1;
    uint8_t mode     : 2;
    uint8_t reserved : 4;
};

int main(void) {
    Point p1 = {3, 4};
    printf("Point: x=%d, y=%d\n", p1.x, p1.y);

    union Value v;
    v.as_uint32 = 0x12345678;
    printf("\nUnion as uint32: 0x%X\n", v.as_uint32);
    printf("Union as bytes: %02X %02X %02X %02X\n",
           v.as_bytes[0], v.as_bytes[1], v.as_bytes[2], v.as_bytes[3]);

    enum GpioMode mode = GPIO_MODE_OUTPUT;
    printf("\nGpioMode value: %d\n", mode);
     
    struct StatusRegister status = {0};
    status.ready = 1;
    status.mode = 2;
    printf("\nsizeof(struct StatusRegister) = %zu byte(s)\n", sizeof(status));
    printf("ready=%u error=%u mode=%u\n", status.ready, status.error, status.mode);

    return 0;
}