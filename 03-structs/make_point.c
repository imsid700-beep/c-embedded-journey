#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Point make_point(int x, int y) {
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}

int main(void) {
    struct Point result = make_point(3, 4);
    printf("result.x = %d, result.y = %d\n", result.x, result.y);
    return 0;
}