/**
 * @file adc.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief  Exemplo para leitura de mais de 1 pino do ADC
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define ROBIN

int main() {
    stdio_init_all();
    printf("Exemplo ADC 2\n");

    adc_init();             //inicia ADC   
    adc_gpio_init(26);      //inicia gpio - coloca como entrada e não habilita pull up ou down
    adc_gpio_init(27);       //inicia gpio - coloca como entrada e não habilita pull up ou down
    

    // Reduce the sampling to 1 ms between readings
    float clkdiv = 0.001f * 48000000.0f - 1;
    adc_set_clkdiv(clkdiv);
    

    #ifdef ROBIN
    adc_fifo_setup (true, false, 0, false, false);
    //configura Round robin
    adc_set_round_robin (0b00011);
    adc_select_input(0);    // Seleciona o canal 0 (pino 26)
     // Start the ADC
    adc_run(true);
    #endif

    int analog_0, analog_1;
    while (1) {

        #ifdef ROBIN
            analog_0 =  adc_fifo_get_blocking();
            analog_1 =  adc_fifo_get_blocking();  
        #else
            adc_select_input(0); 
            analog_0 = adc_read();
            adc_select_input(1); 
            analog_1 = adc_read();
        #endif

        // Print out the averages
        printf("ANALOG 0 %d  ANALOG 1: %d\n", analog_0>>4, analog_1>>4);
/*
        const float conversion_factor = 3.3f / (1 << 12);  // conversor de 12 bit - fundo de escola de 3,3V
        uint16_t result = adc_read();
        printf("ADC: %d, Tensão: %.2f V\n", result, result * conversion_factor);
        sleep_ms(500);*/
    }
}