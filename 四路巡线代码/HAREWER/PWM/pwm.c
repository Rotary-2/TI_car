#include "pwm.h"

/**************************************************************************
函数功能：pwm初始化
入口参数：arr：设为一个时钟频率的最大值  psc： 预分频值
返回  值：无
**************************************************************************/

void PWM_Int(u16 arr,u16 psc,u16 arr2,u16 psc2 )
{
	GPIO_InitTypeDef GPIO_InitStructure;                //定义结构体GPIO_InitStructure
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;      //定义结构体TIM_TimeBaseStructure   
	TIM_OCInitTypeDef TIM_OCInitStructure;              //定义结构体TIM_OCInitStructure
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);//使能PB端口时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//使能定时器3
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //复用模式输出
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1; //PB0 、PB1
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_2MHz;        //IO口速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);        	//GPIO初始化
	
	TIM_TimeBaseStructure.TIM_Period = arr;                //设置下一个更新活动的自动重装载寄存器的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;             //预分配值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;           //时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode= TIM_OCMode_PWM1;             //PWM脉冲宽度调制1
	TIM_OCInitStructure.TIM_Pulse = 0;                           //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //设置TIM输出极性为高
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//比较输出使能
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);
	
	TIM_CtrlPWMOutputs(TIM3,ENABLE);//主输出使能
	
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);//使能预装载寄存器
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);              //使能自动装载允许位
	TIM_Cmd(TIM3,ENABLE);//启动定时器3
	
	
	
//		//定时器4
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能PB端口时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);//使能定时器4
//	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //复用模式输出
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6|GPIO_Pin_7; //PB6 、PB7
//	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_2MHz;        //IO口速度
//	GPIO_Init(GPIOB,&GPIO_InitStructure);        	//GPIO初始化
//	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //复用模式输出
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9; //PB8 、PB9
//	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_2MHz;        //IO口速度
//	GPIO_Init(GPIOB,&GPIO_InitStructure);        	//GPIO初始化
//	
//	TIM_TimeBaseStructure.TIM_Period = arr2;                //设置下一个更新活动的自动重装载寄存器的值
//	TIM_TimeBaseStructure.TIM_Prescaler = psc2;             //预分配值
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;           //时钟分割
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
//	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);
//	
//	TIM_OCInitStructure.TIM_OCMode= TIM_OCMode_PWM1;             //PWM脉冲宽度调制1
//	TIM_OCInitStructure.TIM_Pulse = 0;                           //设置待装入捕获比较寄存器的脉冲值
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //设置TIM输出极性为高
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//比较输出使能
//	TIM_OC1Init(TIM4,&TIM_OCInitStructure);
//	TIM_OC2Init(TIM4,&TIM_OCInitStructure);
//	TIM_OC3Init(TIM4,&TIM_OCInitStructure);
//	TIM_OC4Init(TIM4,&TIM_OCInitStructure);
//	
//	TIM_CtrlPWMOutputs(TIM4,ENABLE);//主输出使能
//	
//	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
//	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
//	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
//	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);//使能预装载寄存器
//	
//	TIM_ARRPreloadConfig(TIM4,ENABLE);              //使能自动装载允许位
//	TIM_Cmd(TIM4,ENABLE);//启动定时器4
}


