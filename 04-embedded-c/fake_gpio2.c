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
typedef enum {
    GPIO_MODE_INPUT  = 0,
    GPIO_MODE_OUTPUT = 1,
    GPIO_MODE_ALT_FN = 2,
    GPIO_MODE_ANALOG = 3
} GpioMode;

/* returns 0 on success, -1 if pin > 15 or mode > 3 (and changes nothing) */
int gpio_set_mode(GPIO_TypeDef *gpio, uint8_t pin, GpioMode mode)
{
    if (pin > 15 || mode > 3) {
        return -1;
    }
    gpio->MODER &= ~(0x3u << (pin * 2));
    gpio->MODER |= ((uint32_t)mode << (pin * 2));
    return 0;
}
int main(void) {
    int r;

    r = gpio_set_mode(GPIOA, 5, GPIO_MODE_OUTPUT);
    printf("ret=%d MODER=0x%08X\n", r, (unsigned int)GPIOA->MODER);

    r = gpio_set_mode(GPIOA, 0, GPIO_MODE_ALT_FN);
    printf("ret=%d MODER=0x%08X\n", r, (unsigned int)GPIOA->MODER);

    r = gpio_set_mode(GPIOA, 5, GPIO_MODE_ANALOG);
    printf("ret=%d MODER=0x%08X\n", r, (unsigned int)GPIOA->MODER);

    r = gpio_set_mode(GPIOA, 5, GPIO_MODE_INPUT);
    printf("ret=%d MODER=0x%08X\n", r, (unsigned int)GPIOA->MODER);

    r = gpio_set_mode(GPIOA, 16, GPIO_MODE_OUTPUT);
    printf("ret=%d MODER=0x%08X\n", r, (unsigned int)GPIOA->MODER);

    return 0;
}