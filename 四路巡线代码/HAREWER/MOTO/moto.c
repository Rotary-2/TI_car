#include "moto.h"
#include "PWM.h"

/**************************************************************************
�������ܣ����������ת
��ڲ�����
����  ֵ����
**************************************************************************/


void Forward(int Speed)
{
		PWMA_IN1=Speed;PWMA_IN2=0;  //��ǰ��  Speed=6000
		PWMB_IN1=0;PWMB_IN2=Speed;  //��ǰ��
}
void Backward(int Speed)
{

	  PWMA_IN1=0;PWMA_IN2=Speed;
	  PWMB_IN1=Speed;PWMB_IN2=0;
	}
void Turnleft(int Speed)
{
		PWMA_IN1=0;PWMA_IN2=0;
		PWMB_IN1=0;PWMB_IN2=Speed; //Speed=6500   
}
void Turnright(int Speed)
{
		PWMA_IN1=Speed;PWMA_IN2=0;//Speed=6500
		PWMB_IN1=0;PWMB_IN2=0;
}
void Stop(void)
{
		PWMA_IN1=0;PWMA_IN2=0;
		PWMB_IN1=0;PWMB_IN2=0;
}
void SpinLeft(int Speed)   //���ֺ�������ǰ��     ���7.9V��������90������   ������8.43V��//Speed=7000
{
		PWMA_IN1=0;PWMA_IN2=Speed;
		PWMB_IN1=0;PWMB_IN2=Speed;
}
void SpinRight(int Speed)   //����ǰ�����ֺ���      ���7.9V��������90������
{
		PWMA_IN1=Speed;PWMA_IN2=0;//Speed=7000
		PWMB_IN1=Speed;PWMB_IN2=0;
}


