/**
 * @file gpio_input_IRQ.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exibe como configurar uma interrupção em um pino configurado como entrada
 * @version 0.1
 * @date 2022-09-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "pico/stdlib.h"

#define LED 25
#define BT 6


void gpio_IRQ(uint gpio,uint32_t events)
{

    printf("GPIO: %d \tEVENTO: %d\n",gpio,events);

}

int main()
{
    stdio_init_all();

    puts("Testa IRQ");

    gpio_init(BT);
    gpio_set_dir(BT,0);
    gpio_pull_up(BT);

    gpio_set_irq_enabled_with_callback(BT, GPIO_IRQ_EDGE_FALL,true,&gpio_IRQ);
   
    while(true){

    }

    return 0;
}
