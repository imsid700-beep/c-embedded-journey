#include <stdio.h>

void increment(int *p) {
    *p = *p + 1;
}

int main(void) {
    int x = 5;

    printf("Before increment: x = %d\n", x);
    increment(&x);
    printf("After increment:  x = %d\n", x);

    return 0;
}
