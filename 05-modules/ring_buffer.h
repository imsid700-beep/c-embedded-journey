#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

#define RB_SIZE 8
#define RB_MASK (RB_SIZE - 1)
_Static_assert((RB_SIZE & (RB_SIZE - 1)) == 0, "RB_SIZE must be a power of 2");

typedef struct {
    uint8_t buf[RB_SIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
} RingBuffer;

void    rb_init(RingBuffer *rb);
int     rb_is_empty(const RingBuffer *rb);
int     rb_is_full(const RingBuffer *rb);
int     rb_push(RingBuffer *rb, uint8_t byte);
int     rb_pop(RingBuffer *rb, uint8_t *out);
uint8_t rb_count(const RingBuffer *rb);

#endif