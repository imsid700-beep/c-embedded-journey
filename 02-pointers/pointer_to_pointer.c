#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    printf("\naddress of x:  %p\n", (void*)&x);
    printf("value of p:    %p\n", (void*)p);
    printf("address of p:  %p\n", (void*)&p);
    printf("value of pp:   %p\n", (void*)pp);

    return 0;
}