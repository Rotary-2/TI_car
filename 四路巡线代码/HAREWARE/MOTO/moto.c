#include "moto.h"
#include "PWM.h"

/**************************************************************************
函数功能：电机的正反转
入口参数：
返回  值：无
**************************************************************************/

int SPEEDA1, SPEEDA2, SPEEDB1, SPEEDB2;
extern float speed1;
extern float speed2;

//首先定义PID结构体用于存放一个PID的数据
typedef struct
{
   	float kp, ki, kd; //三个系数
    float error, lastError; //误差、上次误差
    float integral, maxIntegral; //积分、积分限幅
    float output, maxOutput; //输出、输出限幅
}PID;

PID L_encoder_pid = {0}; //创建一个PID结构体变量
PID R_encoder_pid = {0}; //创建一个PID结构体变量

//用于初始化pid参数的函数
void PID_Init(PID *pid, float p, float i, float d, float maxI, float maxOut)
{
    pid->kp = p;
    pid->ki = i;
    pid->kd = d;
    pid->maxIntegral = maxI;
    pid->maxOutput = maxOut;
	
	pid->lastError = 0;
}
 
//进行一次pid计算
//参数为(pid结构体,目标值,反馈值)，计算结果放在pid结构体的output成员中
void PID_Calc(PID *pid, float reference, float feedback)
{
 	//更新数据
    pid->lastError = pid->error; //将旧error存起来
    pid->error = reference - feedback; //计算新error
    //计算微分
    float dout = (pid->error - pid->lastError) * pid->kd;
    //计算比例
    float pout = pid->error * pid->kp;
    //计算积分
    pid->integral += pid->error * pid->ki;
	printf("%d,%d,%d,",(int)pout, (int)pid->integral, (int)dout);
    //积分限幅
    if(pid->integral > pid->maxIntegral) pid->integral = pid->maxIntegral;
    else if(pid->integral < -pid->maxIntegral) pid->integral = -pid->maxIntegral;
    //计算输出
    pid->output = pout+dout + pid->integral;
		
    //输出限幅
    if(pid->output > pid->maxOutput) pid->output =   pid->maxOutput;
    else if(pid->output < 0) pid->output = 0;
}

void Forward(int Speed)
{
		SPEEDA1=Speed;SPEEDA2=0;  //左前轮  Speed=6000
		SPEEDB1=0;SPEEDB2=Speed;  //右前轮
		setSpeed();
}
//void Backward(int Speed)
//{
//	  SPEEDA1=0;SPEEDA2=Speed;
//	  SPEEDB1=Speed;SPEEDB2=0;
//		setSpeed();
//}
void Turnleft(int Speed)
{
		SPEEDA1=0;SPEEDA2=0;
		SPEEDB1=0;SPEEDB2=Speed; //Speed=6500   
		setSpeed();
}
void Turnright(int Speed)
{
		SPEEDA1=Speed;SPEEDA2=0;//Speed=6500
		SPEEDB1=0;SPEEDB2=0;
		setSpeed();
}
void Stop(void)
{
		SPEEDA1=0;SPEEDA2=0;
		SPEEDB1=0;SPEEDB2=0;
		setSpeed();
}
//void SpinLeft(int Speed)   //左轮后退右轮前进     电池7.9V左右左旋90度左右   （满电8.43V）//Speed=7000
//{
//		SPEEDA1=0;SPEEDA2=Speed;
//		SPEEDB1=0;SPEEDB2=Speed;
//		setSpeed();
//}
//void SpinRight(int Speed)   //左轮前进右轮后退      电池7.9V左右左旋90度左右
//{
//		SPEEDA1=Speed;SPEEDA2=0;//Speed=7000
//		SPEEDB1=Speed;SPEEDB2=0;
//		setSpeed();
//}

//由于只设置了两个轮子的两个pid， 这里把轮子反转的情况暂时注释掉了

void encoderPID_Init()
{
		PID_Init(&L_encoder_pid, 1.75, 0.12, 0.15, 100, 8000);
		PID_Init(&R_encoder_pid, 1.75, 0.12, 0.15, 100, 8000);
}

void setSpeed()
{
		//分别计算两个轮子pid
		float LfeedbackValue = speed1;
		float RfeedbackValue = speed2;
	
		float LtargetValue = SPEEDA1;
		float RtargetValue = SPEEDB2;
		
		PID_Calc(&L_encoder_pid, LtargetValue, LfeedbackValue);
		PID_Calc(&R_encoder_pid, RtargetValue, RfeedbackValue);
	
		printf("%d,%d,", SPEEDA1, SPEEDB2);
		printf("%d,%d,", (int)L_encoder_pid.output, (int)R_encoder_pid.output);
		printf("%d,%d\r\n", (int)speed1, (int)speed2);
	
		PWMA_IN1=(int)L_encoder_pid.output;
		PWMA_IN2=SPEEDA2;
		PWMB_IN1=SPEEDB1;
		PWMB_IN2=(int)R_encoder_pid.output;
}
