#include <stdio.h>

void numbershift(int *a, int b, int i);

void movezeros(int *arr,int n){
    int i=n-1;
    int b=0;
for(int k=0;k<n;k++){
    if(*(arr+i)!=0){
        b++;
        i--;
        printf("11 %d\n",i);
    }
      else if(*(arr+i)==0){
        if(b==0){
            b=0;
            i--;
            printf("21 %d",i);
        }
        else {numbershift(arr,b,i);
            b=0;
            i--;
            printf("22 %d\n",i);



        }
      }

}

}
void numbershift(int *a, int b,int x){
    int y=x;
int k;
for(int j=0;j<b;j++){
    k=*(a+y);
    *(a+y)=*(a+y+1);
    *(a+y+1)=k;
    y++;
printf("hurray %d %d\n",y,y);

}}

int main() {
    int arr[] = {0, 5, 0, 3, 8, 0, 2, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d n \n",n);

    printf("Before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    movezeros(arr, n);

    printf("\nAfter:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}