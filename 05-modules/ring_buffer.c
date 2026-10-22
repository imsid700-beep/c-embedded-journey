#include "ring_buffer.h"
void rb_init(RingBuffer *rb){
    rb->head=0;
    rb->tail=0;
}


int  rb_is_empty(const RingBuffer *rb){
    return(rb->head==rb->tail);
}


int  rb_is_full(const RingBuffer *rb){
    return(((rb->head + 1) & RB_MASK )== rb->tail);
}

int  rb_push(RingBuffer *rb, uint8_t byte){
         uint8_t next=(rb->head + 1) & RB_MASK;
    if(next==rb->tail){
        return -1;
    }else{

        rb->buf[rb->head]=byte;
        rb->head=next;
        return 0;
    }
} 

/* 0 = ok, -1 = full  */
int  rb_pop(RingBuffer *rb, uint8_t *out){
    if(rb_is_empty(rb)){
        return -1;
    }else{
        *out=rb->buf[rb->tail];
        rb->tail=(rb->tail +1) & RB_MASK;
        return 0;
    }
}

/* 0 = ok, -1 = empty */
uint8_t rb_count(const RingBuffer *rb){
    return (rb->head - rb->tail) & RB_MASK;
}