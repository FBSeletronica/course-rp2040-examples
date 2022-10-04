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

#define A_PIN   6
#define B_PIN   7
#define C_PIN   9
#define D_PIN   10
#define E_PIN   11
#define F_PIN   13
#define G_PIN   12
#define DP_PIN  8

//#define MASCARA_DIGITOS 0x3FC0
#define MASCARA_DIGITOS 0X0000 | ((1<<A_PIN)|(1<<B_PIN)|(1<<C_PIN)|(1<<D_PIN)|(1<<E_PIN)|(1<<F_PIN)|(1<<G_PIN)|(DP_PIN))

/*
--A--
F   B
--G--
E   C
--D--

SEG = PIN
A = 6
B = 7
C = 9
D = 10
E = 11
F = 13
G = 12
P = 8
*/
int tabela_digito[] = {
    // FGEDCPBA 
     0b10111011,    //0
     0b00001010,    //1
     0b01110011,    //2
     0b01011011,    //3   

};

// função principal
int main()
{
    uint8_t i =0;

    //configura pinos como GPIO -OUTPUT
    gpio_init_mask(MASCARA_DIGITOS);
    gpio_set_dir_out_masked(MASCARA_DIGITOS);   


    //loop
    while(true){
        gpio_put_masked (MASCARA_DIGITOS, tabela_digito[i]<<6); //atualiza display
        i++;            //incrementa contador
        if(i>3) i=0;    //se passou do valor máximo, reinicia
        sleep_ms(1000); //espera 1 s
    }
}
