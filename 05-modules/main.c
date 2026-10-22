#include <stdio.h>
#include "ring_buffer.h"



int main(void) {
    RingBuffer rb;
    uint8_t v;

    rb_init(&rb);
    for (uint8_t i = 1; i <= 7; i++) {
        rb_push(&rb, i * 10);
    }
    printf("count=%u\n", (unsigned int)rb_count(&rb));
    printf("push 80 returned %d\n", rb_push(&rb, 80));
    while (rb_pop(&rb, &v) == 0) {
        printf("popped %u\n", (unsigned int)v);
    }
    return 0;
}
