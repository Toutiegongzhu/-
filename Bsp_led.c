#include "Bsp_led.h"

void LED_Bsp(uchar LEDbs){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_All, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LEDbs << 8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);

}
