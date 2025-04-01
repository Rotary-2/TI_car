#include "stm32f10x.h"
#include "delay.h"
#include "bsp.h"
#include "iravoid.h"
#include "servo.h"
#include "ps2_control.h"
#include "three_linewalking.h"
#include "linewalking.h"
#include "encoder.h"
#include "JY61P.h"

/*

	��·Ѳ�ߴ����� �ӳ��������ǰ���� ��ൽ�ұ�Ѳ�ߴ�����˳��Ϊ  L1 L2 |����| R1  R2	  ��Ӧԭ��ͼ IN2 IN1 |����| IN3 IN4
	                                                        PC13 PC14    PC15 PB12
																													  �� ��        ��  ��
	������  PA0        PA1        PB6        PB7
	        TIM2_CH1   TIM2_CH2   TIM4_CH1   TIM4_CH2
	
	����    PA9 PA10
	
	���    PA6       PA7        PB0        PB1
				 TIM3_CH1   TIM3_CH2   TIM3_CH3   TIM3_CH4

	USB-TTL                   STM32Core              		  JY901s
	VCC          -----           VCC        ----        	 VCC
	TX           -----           RX1  (GPIOA_10)   
	RX           -----           TX1  (GPIOA_9)
	GND          -----           GND    ----       			    GND
															 RX2  (GPIOA_3)  ----       TX
															 TX2  (GPIOA_2)  ----       RX

*/

int Encoder_NUM;
extern float fAngle[3];


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
		JY61PWork();
		printf("angle:%.3f %.3f %.3f\r\n", fAngle[0], fAngle[1], fAngle[2]);
		
//	Forward(6500);
  
	}
 }

