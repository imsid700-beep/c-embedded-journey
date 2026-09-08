#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;

    printf("Value of x: %d\n", x);
    printf("Address of x (&x): %p\n", (void*)&x);
    printf("Value stored in p: %p\n", (void*)p);
    printf("Dereferenced p (*p): %d\n", *p);

    *p = 20;   // modify x THROUGH the pointer
    printf("\nAfter *p = 20:\n");
    printf("Value of x: %d\n", x);

    printf("\nSize of the pointer itself: %zu bytes\n", sizeof(p));
    printf("Size of what it points to: %zu bytes\n", sizeof(*p));

    return 0;
}
