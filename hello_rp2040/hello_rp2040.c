/**
 * @file hello_rp2040.c
 * @author Fabio Souza
 * @brief Exemplo inicial para entender o processo de compilação e configurações básicas
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022, Fábio Souza
 * 
 */

//bibliotecas 
#include <stdio.h> 
#include "pico/stdlib.h"

//definições
#define HIGH 1      //nivel lógico alto
#define LOW  0      //nível lógico baixo

int main()
{

    stdio_init_all();
    
    //configuração do LED
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;  //constante para manipulação do LED
    gpio_init(LED_PIN);                         //inicia pino como I/O
    gpio_set_dir(LED_PIN,GPIO_OUT);             //configura pino como saída
   
    /*loop infinito*/
    while(true){
        puts("Hello, world!");                  //mensagem no console
        gpio_put(LED_PIN,HIGH);                 //liga LED
        sleep_ms(500);                          //espera 500 ms
        gpio_put(LED_PIN,LOW);                  //desliga LED
        sleep_ms(500);                          //espera 500 ms
    }

    return 0;
}
