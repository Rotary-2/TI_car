#include "stm32f10x.h"
#include "delay.h"
#include "bsp.h"
#include "iravoid.h"
#include "servo.h"
#include "ps2_control.h"
#include "three_linewalking.h"
#include "linewalking.h"
#include "encoder.h"

/*

	��·Ѳ�ߴ����� �ӳ��������ǰ���� ��ൽ�ұ�Ѳ�ߴ�����˳��Ϊ  L1 L2 |����| R1  R2	  ��Ӧԭ��ͼ IN2 IN1 |����| IN3 IN4
	                                                        PC13 PC14    PC15 PB12
																													  �� ��        ��  ��
	������  PA0        PA1        PB6        PB7
	        TIM2_CH1   TIM2_CH2   TIM4_CH1   TIM4_CH2
	
	����    PA9 PA10
	
	���    PA6       PA7        PB0        PB1
				 TIM3_CH1   TIM3_CH2   TIM3_CH3   TIM3_CH4

*/

int Encoder_NUM;
int i;


int main(void)
 {	
	 /*�����ʼ��*/
	bsp_init();
	 	 
	 
  while(1)
	{
	
//	  LineWalking();		//��·Ѳ��ģʽ
		Encoder_NUM = Read_Encoder(2);
	
		printf("Left %d  ", Encoder_NUM);
		Encoder_NUM = Read_Encoder(4);
	
		printf("Right %d\r\n", Encoder_NUM);
		
	Forward(6500);
  
	}
 }

