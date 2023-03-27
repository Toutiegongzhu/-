#include "interrupt.h"

struct key keys[4] = {0, 0, 0};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if(htim->Instance == TIM4)
	{
		keys[0].Key_sta = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
		keys[1].Key_sta = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
		keys[2].Key_sta = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
		keys[3].Key_sta = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		
		for(int i = 0; i < 4; i++)
		{
			switch(keys[i].Key_judge)
			{
				case 0:										// 第一步：判断是否按下
				{
					if(keys[i].Key_sta == 0)
					{
						keys[i].Key_judge = 1;
						keys[i].Key_time = 0;
					}
				}
				break;
				
				case 1:										// 第二步：确认按下
				{
					if(keys[i].Key_sta == 0)
					{
						keys[i].Key_judge = 2;
						keys[i].Sigle_flag = 1;
					}
					else
					{
						keys[i].Key_judge = 0;
					}
				}
				break;
				
				case 2:										// 第三步：判断是否按键松手
				{
					if(keys[i].Key_sta == 1)
					{
						keys[i].Key_judge = 0;
						
						if(keys[i].Key_time < 80)
						{
							keys[i].Short_falg = 1;
						}
					}
					else
					{
						keys[i].Key_time++;	
						if(keys[i].Key_time > 80)
						{
							keys[i].Long_flag = 1;
						}
					}
				}
				break;
				
			}
		}
	}
}
