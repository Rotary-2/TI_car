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

	四路巡线传感器 从车身后面往前看： 左侧到右边巡线传感器顺序为  L1 L2 |黑线| R1  R2	  对应原理图 IN2 IN1 |黑线| IN3 IN4
	                                                        PC13 PC14    PC15 PB12
																													  橙 黄        绿  蓝
	编码器  PA0        PA1        PB6        PB7
	        TIM2_CH1   TIM2_CH2   TIM4_CH1   TIM4_CH2
	
	串口    PA9 PA10
	
	电机    PA6       PA7        PB0        PB1
				 TIM3_CH1   TIM3_CH2   TIM3_CH3   TIM3_CH4

	姿态传感器
	USB-TTL                   STM32Core              		  JY901s
	VCC          -----           VCC        ----        	 VCC
	TX           -----           RX1  (GPIOA_10)   
	RX           -----           TX1  (GPIOA_9)
	GND          -----           GND    ----       			    GND
															 RX2  (GPIOA_3)  ----       TX
															 TX2  (GPIOA_2)  ----       RX
*/

int left_Encoder_NUM;
int right_Encoder_NUM;
extern float fAngle[3];
int speed;
extern float speed1;
extern float speed2;
int j;

int main(void)
{	
	 /*外设初始化*/
	bsp_init();	 	 
	
	 
	while(1)
	{

	//	  LineWalking();		//四路巡线模式
	//		left_Encoder_NUM = Read_Encoder(2);
	//	
	////		printf("Left %d  ", left_Encoder_NUM);
	//		right_Encoder_NUM = Read_Encoder(4);
	//		printf("%d %d\r\n", left_Encoder_NUM, right_Encoder_NUM);

	//		printf("Right %d\r\n", right_Encoder_NUM);
	//		JY61PWork();
	//		printf("angle:%.3f %.3f %.3f\r\n", fAngle[0], fAngle[1], fAngle[2]);
		
		
//		Forward(6500);
	
		
		for (speed = 3500; speed < 6500; speed += 500)
		{
				for (j = 0; j < 200; j++)
				{
						Forward(speed);
//						printf("%f, %f, %d\r\n", speed1, speed2, speed);
						delay_ms(10);
				}
		}
		for (speed = 6500; speed > 3500; speed -= 500)
		{
				for (j = 0; j < 200; j++)
				{
						Forward(speed);
						delay_ms(10);
				}
		}
	}
}



