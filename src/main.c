/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"

#include "gpio.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_init();

    for (;;)
        ;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_6) {
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == GPIO_PIN_SET) {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        }
    }
}
