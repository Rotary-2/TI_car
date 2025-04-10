/**
* @par Copyright (C): Shenzhen Yahboom Tech
* @file         bsp.c
* @brief        ���������
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
* @brief         Ӳ���豸��ʼ��
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void bsp_init(void)
{
	
		SystemInit(); //����ϵͳʱ��Ϊ72M   
    delay_init();    //��ʱ������ʼ��
    uart_init(9600);		//���ڳ�ʼ��
	  PWM_Int(7199,0, 7199,0);      //��ʼ��pwm��� 72000 000 /7199+1=10000 

		Encoder_Init_Tim2();
		Encoder_Init_Tim4();
		Timer_Init();
	
		LineWalking_GPIO_Init();			/*Ѳ�ߴ�������ʼ��*/
		JY61PInit();
	
}

