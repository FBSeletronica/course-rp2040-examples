#include <stdio.h>
#include "pico/stdlib.h"

#define LED 25

bool blinkLED(struct repeating_timer *timer)
{
    static bool i = 1;
    gpio_put(LED,i^=1);    

}
int main()
{
    stdio_init_all();

    gpio_init(LED);
    gpio_set_dir(LED,GPIO_OUT);

    struct repeating_timer blinkTimer;
    add_repeating_timer_ms(1000,blinkLED,NULL,&blinkTimer);

    while (1)
    {
        tight_loop_contents();
    }
    
}
