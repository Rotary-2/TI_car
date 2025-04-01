/**
* @par Copyright (C): Shenzhen Yahboom Tech
* @file         bsp.c
* @brief        ���������
*/

#include "bsp.h"
#include "moto.h"
#include "pwm.h"
#include "adc.h"
#include "usart.h"
#include "encoder.h"
#include "servo.h"
#include "linewalking.h"
#include "iravoid.h"
#include "ps2_control.h"
#include "three_linewalking.h"
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

		TIM1_Int_Init(9, 72);				/*100Khz�ļ���Ƶ�ʣ�������10Ϊ10us  */ 
		Encoder_Init_Tim2();
		LineWalking_GPIO_Init();			/*Ѳ�ߴ�������ʼ��*/
		JY61PInit();
	
}

