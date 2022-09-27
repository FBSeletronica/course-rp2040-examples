/**
 * @file gpio_input_masked.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exemplo para exibir a leitura e acionamento de varios pinos ao mesmo tempo
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();

    puts("Input Masked");

    gpio_init_mask(0b1111111111111111110000);
    gpio_set_dir_out_masked(0b0000000011111111110000); 
    gpio_set_dir_in_masked (0b1111111100000000000000);  

    for(int i = 14;i<22;i++){
        gpio_pull_up(i);
    }

    //loop
   while(true){
        int x = gpio_get_all();
        x= (x>>14)&0xFF;
        gpio_put_masked(0b11111111110000,x<<4);
        sleep_ms(1000);     
    }
}
