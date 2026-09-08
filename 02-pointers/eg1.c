void increment(int *p){
    *p=*p+1;

}
int main(void){
    int x=10;
    printf("Value of x before increment: %d\n",x);
    increment(&x);
    printf("Value of x after increment: %d\n",x);
    return 0;
}