/**
 * @file pwm_generator.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exemplo para configuração do PWM com dois canais idependentes no mesmo Slice
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

#define PWM_OUT_1 4       //PWM1
#define PWM_OUT_2 5       //PWM2

uint32_t pwm_set_freq_duty(uint slice_num, uint chan, uint32_t f, int d){
    uint32_t clock = 125000000;
    uint32_t divisor16 = clock/f/4096 + (clock %(f*4096)!=0);
    if(divisor16/16 == 0)
    divisor16 = 16;
    uint32_t wrap = clock*16 /divisor16/f-1;
    pwm_set_clkdiv_int_frac(slice_num,divisor16/16,divisor16&0xF);
    pwm_set_wrap(slice_num,wrap);
    pwm_set_chan_level(slice_num,chan,wrap*d/100);
}

uint32_t pwm_get_wrap(uint slice_num){
    valid_params_if(PWM,slice_num>=0 && slice_num <NUM_PWM_SLICES);
    return pwm_hw->slice[slice_num].top;
}

void pwm_set_duty(uint slice_num, uint chan, int d){
    pwm_set_chan_level(slice_num,chan,pwm_get_wrap(slice_num)*d/100);
}

int main() {
    
    //configuração do GPIO
    gpio_set_function(PWM_OUT_1, GPIO_FUNC_PWM);        //Seleciona PWM para o pino do LED
    gpio_set_function(PWM_OUT_2, GPIO_FUNC_PWM);        //Seleciona PWM para o pino do LED
    uint slice_num = pwm_gpio_to_slice_num(PWM_OUT_1);  //pega o slice referente ao pino   
    uint chan_out1 = pwm_gpio_to_channel(PWM_OUT_1);        //pega canal
    uint chan_out2 = pwm_gpio_to_channel(PWM_OUT_2);        //pega canal    

    //cofiguração do PWM
    uint32_t wrap = pwm_set_freq_duty(slice_num, chan_out1, 100, 0);
    pwm_set_duty(slice_num,chan_out2,0);
    pwm_set_enabled(slice_num,true);                    //habilita PWM
    

    while (1){
        for(uint32_t  i = 0;i<100;i++){
            pwm_set_duty(slice_num,chan_out2,i);
            pwm_set_duty(slice_num,chan_out1,100-i);
            sleep_ms(100);
        }
        sleep_ms(1000);
    }
}