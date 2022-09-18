/**
 * @file gpio_output.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exemplo para exibir a configuração de um pino como saída digital
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
    //configuração
    gpio_init(25);              //configura pino para ser um GPIO
    gpio_set_dir(25,1);         //configura pino para funcionar como saída

    gpio_put(25,1);             //coloca nível alto no pino
    gpio_put(25,0);             //coloca nível baixo no pino

    //loop
    while(true){

    }

}
