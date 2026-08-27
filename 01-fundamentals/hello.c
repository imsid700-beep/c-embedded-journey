#include <stdio.h>

int add(int a, int b) {
    int sum = a + b;
    // no return statement here, deliberately
}

int main(void) {
    printf("%d\n", add(2, 3));
    return 0;
}