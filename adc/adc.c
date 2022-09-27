/**
 * @file adc.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief  Exemplo para leitura de um pino do ADC
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

int main() {
    stdio_init_all();
    printf("Exemplo ADC\n");

    adc_init();             //inicia ADC   
    adc_gpio_init(26);      //inicia gpio - coloca como entrada e não habilita pull up ou down
    adc_select_input(0);    // Seleciona o canal 0 (pino 26)

    while (1) {
        const float conversion_factor = 3.3f / (1 << 12);  // conversor de 12 bit - fundo de escola de 3,3V
        uint16_t result = adc_read();
        printf("ADC: %d, Tensão: %.2f V\n", result, result * conversion_factor);
        sleep_ms(500);
    }
}