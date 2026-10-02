#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

struct Sensor {
     float    calibrated;
      uint16_t raw;
    uint8_t  id;
   
    uint8_t  flags;
};

int main(void) {
    printf("sizeof(struct Sensor) = %zu\n", sizeof(struct Sensor));
    printf("offsets: id=%zu raw=%zu calibrated=%zu flags=%zu\n",
           offsetof(struct Sensor, id), offsetof(struct Sensor, raw),
           offsetof(struct Sensor, calibrated), offsetof(struct Sensor, flags));
    return 0;
}