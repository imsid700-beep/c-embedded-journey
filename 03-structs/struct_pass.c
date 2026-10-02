#include <stdio.h>

struct Point { int x; int y; };

void move_by_value(struct Point p)    { p.x += 10; }
void move_by_pointer(struct Point *p) { p->x += 10; }

int main(void) {
    struct Point pt = {1, 2};

    move_by_value(pt);
    printf("after by value:   x = %d\n", pt.x);

    move_by_pointer(&pt);
    printf("after by pointer: x = %d\n", pt.x);
    return 0;
}