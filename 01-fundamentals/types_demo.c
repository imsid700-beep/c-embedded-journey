#include <stdio.h>
#include <stdint.h>

int main(void) {
    printf("sizeof(char): %zu byte(s)\n", sizeof(char));
    printf("sizeof(short): %zu byte(s)\n", sizeof(short));
    printf("sizeof(int): %zu byte(s)\n", sizeof(int));
    printf("sizeof(long): %zu byte(s)\n", sizeof(long));
    printf("sizeof(long long): %zu byte(s)\n", sizeof(long long));
    printf("sizeof(float): %zu byte(s)\n", sizeof(float));
    printf("sizeof(double): %zu byte(s)\n", sizeof(double));
    printf("sizeof(uint8_t): %zu byte(s)\n", sizeof(uint8_t));
    printf("sizeof(uint32_t): %zu byte(s)\n", sizeof(uint32_t));

    uint8_t u = 255;
    int8_t s = (int8_t)u;   // reinterpret the same bit pattern as signed
    printf("\nSame bits (11111111) as uint8_t: %u\n", u);
    printf("Same bits (11111111) as int8_t:  %d\n", s);

    return 0;
}
