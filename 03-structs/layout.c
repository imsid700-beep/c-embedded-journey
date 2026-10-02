#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

struct A { uint8_t a; uint32_t b; uint8_t c; };
struct B { uint32_t b; uint8_t a; uint8_t c; };

int main(void) {
    printf("sizeof(struct A) = %zu\n", sizeof(struct A));
    printf("  offsets: a=%zu b=%zu c=%zu\n",
           offsetof(struct A, a), offsetof(struct A, b), offsetof(struct A, c));

    printf("sizeof(struct B) = %zu\n", sizeof(struct B));
    printf("  offsets: b=%zu a=%zu c=%zu\n",
           offsetof(struct B, b), offsetof(struct B, a), offsetof(struct B, c));
    return 0;
}