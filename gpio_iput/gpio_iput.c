/**
 * @file gpio_iput.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exemplo para exibir a leitura de um pino como entrada digital(botão)
 * @version 0.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022, Fábio Souza
 * 
 */
#include <stdio.h>
#include "pico/stdlib.h"

#define LED 25
#define BT 6

int main()
{

    //configuração
    gpio_init(BT);
    gpio_set_dir(BT,0);
    gpio_pull_up(BT);

    gpio_init(LED);
    gpio_set_dir(LED,1);
    

    //loop
    while(true){
        if(gpio_get(BT)){
            gpio_put(LED,0); 
        }
        else{
            gpio_put(LED,1); 
        }
    }

    return 0;
}
