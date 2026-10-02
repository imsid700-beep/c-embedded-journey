#include <stdio.h>
char *get_name(void) {
    static char name[] = "SKULL";
    return name;
}
int main(void) {
    char *s = get_name();
    s[0] = 'X';
    printf("%s\n", s);
}