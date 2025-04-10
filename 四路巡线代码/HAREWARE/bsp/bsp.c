/**
* @par Copyright (C): Shenzhen Yahboom Tech
* @file         bsp.c
* @brief        驱动总入口
*/

#include "bsp.h"
#include "moto.h"
#include "pwm.h"
#include "usart.h"
#include "encoder.h"
#include "linewalking.h"
#include "JY61P.h"

/**
* Function       bsp_init  
* @brief         硬件设备初始化
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void bsp_init(void)
{
	
		SystemInit(); //配置系统时钟为72M   
    delay_init();    //延时函数初始化
    uart_init(9600);		//串口初始化
	  PWM_Int(7199,0, 7199,0);      //初始化pwm输出 72000 000 /7199+1=10000 

		Encoder_Init_Tim2();
		Encoder_Init_Tim4();
		Timer_Init();
	
		LineWalking_GPIO_Init();			/*巡线传感器初始化*/
		JY61PInit();
	
}

