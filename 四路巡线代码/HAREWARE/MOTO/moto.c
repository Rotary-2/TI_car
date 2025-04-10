#include "moto.h"
#include "PWM.h"

/**************************************************************************
函数功能：电机的正反转
入口参数：
返回  值：无
**************************************************************************/


void Forward(int Speed)
{
		PWMA_IN1=Speed;PWMA_IN2=0;  //左前轮  Speed=6000
		PWMB_IN1=0;PWMB_IN2=Speed;  //右前轮
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
void SpinLeft(int Speed)   //左轮后退右轮前进     电池7.9V左右左旋90度左右   （满电8.43V）//Speed=7000
{
		PWMA_IN1=0;PWMA_IN2=Speed;
		PWMB_IN1=0;PWMB_IN2=Speed;
}
void SpinRight(int Speed)   //左轮前进右轮后退      电池7.9V左右左旋90度左右
{
		PWMA_IN1=Speed;PWMA_IN2=0;//Speed=7000
		PWMB_IN1=Speed;PWMB_IN2=0;
}


