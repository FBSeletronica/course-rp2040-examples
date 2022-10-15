/**
 * @file pwm_led_fade.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief Exemplo para fazer um efito fade em um led 
 *        Aumenta o brilho até 100% depois reduz o brillho até 0%. 
 *        O controle do brilho é feito na rotina de interrupção do PWM
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"

#define LED 5       //pino do LED


//interrupção do PWM
void on_pwm_wrap() {
    
    static int fade = 0;
    static bool going_up = true;

    pwm_clear_irq(pwm_gpio_to_slice_num(LED)); //limpa flag de interrupção

    //se incrementando
    if (going_up) {
        ++fade;                 //soma 1
        if (fade > 255) {       //se passou de 255
            fade = 255;         //mantem 255
            going_up = false;   //troca para deceremento
        }
    } else {                    //se decrementando
        --fade;                 //subtrai 1
        if (fade < 0) {         // se -1
            fade = 0;           //mantem 1
            going_up = true;    //troca para incremento
        }
    }
    pwm_set_gpio_level(LED, fade * fade); //saida do LED fade² para pegar todo do range do PWM
}

int main() {
    
    //configuração do GPIO
    gpio_set_function(LED, GPIO_FUNC_PWM); // Seleciona PWM para o pino do LED
    uint slice_num = pwm_gpio_to_slice_num(LED); // pega o slice referente ao pino   

    //configura interrupção do PWM
    pwm_clear_irq(slice_num);                               //limpa IRQ do slice
    pwm_set_irq_enabled(slice_num, true);                   //habilita IRQ para o slice 
    irq_set_exclusive_handler(PWM_IRQ_WRAP, on_pwm_wrap);   // configura handler
    irq_set_enabled(PWM_IRQ_WRAP, true);                    //habilita interrupção

    //cofiguração do PWM
    pwm_config config = pwm_get_default_config();  //configuração padrão - Feee Running, (0 to 2**16-1)
    pwm_config_set_clkdiv(&config, 4.f);           //configura o clock f = 125000000/65535/4 = 476Hz
    pwm_init(slice_num, &config, true);            //inicia PWM

    while (1)
        tight_loop_contents();      //nop
}