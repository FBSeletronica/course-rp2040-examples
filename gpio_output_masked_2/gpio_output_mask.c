/**
 * @file gpio_output.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exemplo Display 7 segmentos - Saídas mascaradas
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022, Fábio Souza
 * 
 */

#include <stdio.h>
#include "pico/stdlib.h"


// função principal
int main()
{
    uint16_t i =1;

    //configura pinos como GPIO -OUTPUT
    gpio_init_mask(0b11111111110000);
    gpio_set_dir_out_masked(0b11111111110000);

    for(uint8_t i = 0; i<2;i++){
        gpio_put_masked(0b11111111110000,0b10101010100000);
        sleep_ms(1000);
        gpio_put_masked(0b11111111110000,0b01010101010000);   
        sleep_ms(1000);
    }
 
    gpio_put_masked(0b11111111110000,0);    //apaga todos os LEDs
    //loop
    while(true){
        gpio_put_masked(0b11111111110000,i<<4);
        i = i<<1;
        if(i>=1024) i=1;
        sleep_ms(1000);

    }
}
