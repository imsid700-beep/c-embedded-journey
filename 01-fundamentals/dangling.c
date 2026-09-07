#include <stdio.h>
int* address(int x){
    return &x;

}
int main(void){
    int a=5;
    int* p=address(a);
    printf("dereferenced  value: %d\n", *p);
    return 0;
}
