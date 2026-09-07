#include <stdio.h>

int global_initialized = 42;      // .data
int global_uninitialized=0;         // .bss
static int static_var = 0;        // .bss (explicitly zero)

int main(void) {
    int local_var = 7;            // stack

    printf("global_initialized address: %p\n", (void*)&global_initialized);
    printf("global_uninitialized address: %p\n", (void*)&global_uninitialized);
    printf("static_var address: %p\n", (void*)&static_var);
    printf("local_var address: %p\n", (void*)&local_var);

    return 0;
}
