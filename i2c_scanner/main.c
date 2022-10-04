/**
 * @file main.c
 * @author Fabio Souza (contato@fabiosouza.org)
 * @brief  Exemplo para varrer dispositivos na I2C
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Definição dos pinos e canal I2C
#define I2C_ID        i2c0
#define I2C_SCL_PIN   PICO_DEFAULT_I2C_SCL_PIN
#define I2C_SDA_PIN   PICO_DEFAULT_I2C_SDA_PIN

// Definição para configuração da I2C
#define BAUD_RATE 100000   // standard 100KHz

// Programa principal
int main() {
    
    stdio_init_all();   

    sleep_ms(5000); //sleep opcional. Apenas para dar tempo de conectar o terminal serial

    // Configuração do canal I2C
    uint baud = i2c_init (I2C_ID, BAUD_RATE);
    printf ("I2C @ %u Hz\n", baud); //imprime configuração da I2C
    
    // Configuração dos pinos da I2C
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SCL_PIN);
    gpio_pull_up(I2C_SDA_PIN);

    printf("Procurando por dispositivos I2C...\n");
    printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");

    //varredura dos 128 endereços 
    for (int addr = 0; addr <= 0x7F; ++addr) {
        if ((addr % 16) == 0) {
            printf("%02x ", addr);
        }

        // Procura apenas por endereços não reservados
        int ret = PICO_ERROR_GENERIC;
        if (((addr & 0x78) != 0) && ((addr & 0x78) != 0x78)) {
            uint8_t rxdata;
            ret = i2c_read_blocking(i2c_default, addr, &rxdata, 1, false);
        }
        printf(ret < 0 ? "." : "X");                //Imprime estado da resposta
        printf((addr % 16) == 15 ? "\n" : "  ");    //se varreu toda linha, pula linha   
    }
    printf("Done.\n");

    //loop infinito
    while (1) {
        tight_loop_contents();
    }
}