/**
 * @file pwm.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exemplo básico para configuração do PWM
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"


#define CALC_FREQ

#define PWM_OUT_1 4       //PWM A
#define PWM_OUT_2 5       //PWM B

uint32_t pwm_set_freq_duty(uint slice_num, uint chan, uint32_t f, int d){
    uint32_t clock = 125000000;
    uint32_t divisor16 = clock/f/4096 + (clock %(f*4096)!=0);
    if(divisor16/16 == 0)
    divisor16 = 16;
    uint32_t wrap = clock*16 /divisor16/f-1;
    pwm_set_clkdiv_int_frac(slice_num,divisor16/16,divisor16&0xF);
    pwm_set_wrap(slice_num,wrap);
    pwm_set_chan_level(slice_num,chan,wrap*d/100);
    return wrap;
}

int main() {
    
    #ifndef CALC_FREQ
    gpio_set_function(PWM_OUT_1, GPIO_FUNC_PWM);        //Seleciona PWM para o pino do LED
    uint slice_num = pwm_gpio_to_slice_num(PWM_OUT_1);  //pega o slice referente ao pino
    pwm_set_wrap(slice_num,500);
    pwm_set_gpio_level(PWM_OUT_1,250);
    pwm_set_enabled(slice_num,true);                    //habilita PWM

    while(1);
    
    #else
    //configuração do GPIO
    gpio_set_function(PWM_OUT_1, GPIO_FUNC_PWM);        //Seleciona PWM para o pino do LED
    uint slice_num = pwm_gpio_to_slice_num(PWM_OUT_1);  //pega o slice referente ao pino   
    uint chan = pwm_gpio_to_channel(PWM_OUT_1);        //pegar canal
    
    //cofiguração do PWM
    uint32_t wrap = pwm_set_freq_duty(slice_num, chan, 100, 50);
    pwm_set_enabled(slice_num,true);                    //habilita PWM
      

    while (1){
        uint32_t i;
        for(i = 0;i<wrap;i++){
            pwm_set_gpio_level(PWM_OUT_1, i);
            sleep_ms(1);
        }
    }
    #endif
}