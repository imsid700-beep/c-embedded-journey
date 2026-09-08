int* address(int x){
    return &x;

}
int main(void){
    int a=5;
    int* p=address(a);
    printf("dereferenced value: %d\n", *p);
    
}