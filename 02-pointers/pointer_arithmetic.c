#include <stdio.h>

int main(void) {
    double arr[5] = {10, 20, 30, 40, 50};
    double *p = arr;

    printf("arr[2] = %f\n", arr[2]);
    printf("*(arr + 2) = %f\n", *(arr + 2));
    printf("*(p + 2) = %f\n", *(p + 2));

    printf("\nsizeof(arr) = %zu bytes\n", sizeof(arr));
    printf("sizeof(p) = %zu bytes\n", sizeof(p));

    printf("\nWalking the array with pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(p + %d) = %f, address = %p\n", i, *(p + i), (void*)(p + i));
    }

    printf("\nWalking with p++ directly:\n");
    double *q = arr;
    for (int i = 0; i < 5; i++) {
        printf("*q = %f, address = %p\n", *q, (void*)q);
        q++;
    }

    return 0;
}