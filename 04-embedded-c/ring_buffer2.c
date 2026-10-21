#include <stdio.h>
#include <stdint.h>

#define RB_SIZE 8
#define RB_MASK (RB_SIZE - 1)
_Static_assert((RB_SIZE & (RB_SIZE - 1)) == 0, "RB_SIZE must be a power of 2");

typedef struct {
    uint8_t buf[RB_SIZE];
    volatile uint8_t head;   /* written only by the producer */
    volatile uint8_t tail;   /* written only by the consumer */
} RingBuffer;

void rb_init(RingBuffer *rb){
    rb->head=0;
    rb->tail=0;}

int  rb_is_empty(const RingBuffer *rb){
    return(rb->head==rb->tail);
}
int  rb_is_full(const RingBuffer *rb){
    return(((rb->head + 1) & RB_MASK )== rb->tail);
}
int  rb_push(RingBuffer *rb, uint8_t byte){
        volatile uint8_t next=(rb->head + 1) & RB_MASK;
    if(next==rb->tail){
        return -1;
    }else{

        rb->buf[rb->head]=byte;
        rb->head=next;
        return 0;
    }
}    /* 0 = ok, -1 = full  */
int  rb_pop(RingBuffer *rb, uint8_t *out){
    if(rb_is_empty(rb)){
        return -1;
    }else{
        *out=rb->buf[rb->tail];
        rb->tail=(rb->tail +1) & RB_MASK;
        return 0;
    }
};     /* 0 = ok, -1 = empty */
uint8_t rb_count(const RingBuffer *rb){
    return (rb->head - rb->tail) & RB_MASK;
}
/* your function bodies go here, above main */

int main(void) {
    RingBuffer rb;
    uint8_t v;

    rb_init(&rb);
    rb_push(&rb, 10);
    rb_push(&rb, 20);
    printf("count=%u\n", (unsigned int)rb_count(&rb));
    rb_pop(&rb, &v);
    printf("count=%u\n", (unsigned int)rb_count(&rb));
    printf("popped %u\n", (unsigned int)v);
    rb_push(&rb, 30);
    rb_push(&rb, 40);
    int r = rb_push(&rb, 50);
    printf("push 50 returned %d\n", r);
    while (rb_pop(&rb, &v) == 0) {
        printf("popped %u\n", (unsigned int)v);
    }
    printf("head=%u tail=%u\n", (unsigned int)rb.head, (unsigned int)rb.tail);
    return 0;
}