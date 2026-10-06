#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int main(void) {
    int (*operation)(int, int);

    operation = add;
    printf("add: %d\n", operation(10, 3));

    operation = sub;
    printf("sub: %d\n", operation(10, 3));

    operation = mul;
    printf("mul: %d\n", operation(10, 3));
operation=add;
    printf("\nAddress of add function: %p\n", (void*)add);
    printf("Value stored in operation: %p\n", (void*)operation);
    int(*fp[3])(int,int)={add,sub,mul};
    for(int j=0;j<3;j++){
        printf("result is %d\n",fp[j](10,3));


    }

    return 0;
}