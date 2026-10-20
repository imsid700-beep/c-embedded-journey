#include <stdio.h>
#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t ODR;
} GPIO_TypeDef;

static GPIO_TypeDef fake_gpioa = {0, 0};
#define GPIOA (&fake_gpioa)

/* write these three yourself */
void gpio_set_pin(GPIO_TypeDef *gpio, uint8_t pin){
    gpio->ODR |= (1u << pin);
}
void gpio_clear_pin(GPIO_TypeDef *gpio, uint8_t pin){
    gpio->ODR &= ~(1u << pin);
}
int  gpio_read_pin(GPIO_TypeDef *gpio, uint8_t pin){
    return (gpio->ODR & (1u << pin)) != 0;
}


int main(void) {
    gpio_set_pin(GPIOA, 5);
    gpio_set_pin(GPIOA, 0);
    printf("ODR = 0x%08X\n", (unsigned int)GPIOA->ODR);
    gpio_clear_pin(GPIOA, 5);
    printf("ODR = 0x%08X\n", (unsigned int)GPIOA->ODR);
    printf("pin 0: %d, pin 5: %d\n", gpio_read_pin(GPIOA, 0), gpio_read_pin(GPIOA, 5));
    return 0;
}