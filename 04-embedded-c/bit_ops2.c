#include <stdio.h>
#include <stdint.h>
int is_bit_set(uint8_t reg, int bit_position){
    if(reg & (1<<bit_position)){ return 1;}else{  return 0;}
}
void print_binary(uint8_t val) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}
int main(void) {
    uint8_t reg = 0b00000000;
    uint8_t mask = (1 << 0)|(1 << 2)| (1 << 5);
    reg=reg|mask;
    print_binary(reg);
    printf("\n");
   printf("bit %d: %d\n", 0, is_bit_set(reg, 0));
    printf("bit %d: %d\n", 1, is_bit_set(reg, 1));
    printf("bit %d: %d\n", 2, is_bit_set(reg, 2));
    printf("bit %d: %d\n", 3, is_bit_set(reg, 3));
    printf("bit %d: %d\n", 4, is_bit_set(reg, 4));
    printf("bit %d: %d\n", 5, is_bit_set(reg, 5));

    return 0;


}