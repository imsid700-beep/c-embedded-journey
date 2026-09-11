#include <stdio.h>
#include <string.h>

int main(void) {
    char s2[] = "Hello";

    printf("s2 = %s\n", s2);
    printf("strlen(s2) = %zu\n", strlen(s2));
    printf("sizeof(s2) = %zu (includes the null terminator)\n", sizeof(s2));

    printf("\nWalking s2 byte by byte until null terminator:\n");
    char *p = s2;
    while (*p != '\0') {
        printf("char: %c, address: %p\n", *p, (void*)p);
        p++;
    }

    printf("\nModifying s2 (a real array, this is safe):\n");
    s2[0] = 'h';
    printf("s2 = %s\n", s2);

    return 0;
}