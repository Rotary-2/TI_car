#ifndef __SERVO_H
#define	__SERVO_H

#include "stm32f10x.h"

extern int Angle_J1;

/*������Ҫ��ʼ���Ķ���궨�忪��*/
#define USE_SERVO_J1
#define Servo_J1_PIN	GPIO_Pin_11
#define Servo_J1_PORT	GPIOA
#define Servo_J1_RCC	RCC_APB2Periph_GPIOA

void Servo_J1(int v_iAngle);/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
void Servo_GPIO_Init(void);

void front_detection(void);
void left_detection(void);
void right_detection(void);

void TIM1_Int_Init(u16 arr,u16 psc);


#endif
