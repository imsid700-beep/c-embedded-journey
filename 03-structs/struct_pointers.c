#include <stdio.h>

struct Point { int x; int y; };

void move_point(struct Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

void print_point(const struct Point *p) {
    printf("(%d, %d)\n", p->x, p->y);
}
int main(void) {
    struct Point pt = {0, 0};

    print_point(&pt);
    move_point(&pt, 5, 3);
    print_point(&pt);

    return 0;
}