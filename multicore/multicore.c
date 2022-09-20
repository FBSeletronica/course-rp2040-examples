#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/adc.h"
 

// Core 1 
void core1_entry() {

    while (true){
        uint16_t temp_raw = multicore_fifo_pop_blocking();
        const float conversion_factor = 3.3f / (1 << 12);
        float result = (float)temp_raw * conversion_factor;
        float temp = 27.0f - (result - 0.706f)/0.001721f;
        printf("Temperatura = %.2f C\n", temp);        
    }
}

// Core 0
int main(void){
    stdio_init_all();           //inicia STDIO

    multicore_launch_core1(core1_entry); // Inicia core 1 

    // Confiugura sensor de temperatura interno (ADC)
    adc_init();
    adc_set_temp_sensor_enabled(true); // habilita sensor de temperatura 
    adc_select_input(4);               //seleciona canal 4

    //Loop infinito - Ler sensor de temperatura a cada 500 ms
    while (1) {
        uint16_t temp_raw = adc_read();
        multicore_fifo_push_blocking(temp_raw);
        sleep_ms(500);
    }
}