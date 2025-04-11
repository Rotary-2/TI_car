#include "moto.h"
#include "PWM.h"

/**************************************************************************
�������ܣ����������ת
��ڲ�����
����  ֵ����
**************************************************************************/

int SPEEDA1, SPEEDA2, SPEEDB1, SPEEDB2;
extern float speed1;
extern float speed2;

//���ȶ���PID�ṹ�����ڴ��һ��PID������
typedef struct
{
   	float kp, ki, kd; //����ϵ��
    float error, lastError; //���ϴ����
    float integral, maxIntegral; //���֡������޷�
    float output, maxOutput; //���������޷�
}PID;

PID L_encoder_pid = {0}; //����һ��PID�ṹ�����
PID R_encoder_pid = {0}; //����һ��PID�ṹ�����

//���ڳ�ʼ��pid�����ĺ���
void PID_Init(PID *pid, float p, float i, float d, float maxI, float maxOut)
{
    pid->kp = p;
    pid->ki = i;
    pid->kd = d;
    pid->maxIntegral = maxI;
    pid->maxOutput = maxOut;
	
	pid->lastError = 0;
}
 
//����һ��pid����
//����Ϊ(pid�ṹ��,Ŀ��ֵ,����ֵ)������������pid�ṹ���output��Ա��
void PID_Calc(PID *pid, float reference, float feedback)
{
 	//��������
    pid->lastError = pid->error; //����error������
    pid->error = reference - feedback; //������error
    //����΢��
    float dout = (pid->error - pid->lastError) * pid->kd;
    //�������
    float pout = pid->error * pid->kp;
    //�������
    pid->integral += pid->error * pid->ki;
	printf("%d,%d,%d,",(int)pout, (int)pid->integral, (int)dout);
    //�����޷�
    if(pid->integral > pid->maxIntegral) pid->integral = pid->maxIntegral;
    else if(pid->integral < -pid->maxIntegral) pid->integral = -pid->maxIntegral;
    //�������
    pid->output = pout+dout + pid->integral;
		
    //����޷�
    if(pid->output > pid->maxOutput) pid->output =   pid->maxOutput;
    else if(pid->output < 0) pid->output = 0;
}

void Forward(int Speed)
{
		SPEEDA1=Speed;SPEEDA2=0;  //��ǰ��  Speed=6000
		SPEEDB1=0;SPEEDB2=Speed;  //��ǰ��
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
//void SpinLeft(int Speed)   //���ֺ�������ǰ��     ���7.9V��������90������   ������8.43V��//Speed=7000
//{
//		SPEEDA1=0;SPEEDA2=Speed;
//		SPEEDB1=0;SPEEDB2=Speed;
//		setSpeed();
//}
//void SpinRight(int Speed)   //����ǰ�����ֺ���      ���7.9V��������90������
//{
//		SPEEDA1=Speed;SPEEDA2=0;//Speed=7000
//		SPEEDB1=Speed;SPEEDB2=0;
//		setSpeed();
//}

//����ֻ�������������ӵ�����pid�� ��������ӷ�ת�������ʱע�͵���

void encoderPID_Init()
{
		PID_Init(&L_encoder_pid, 1.75, 0.12, 0.15, 100, 8000);
		PID_Init(&R_encoder_pid, 1.75, 0.12, 0.15, 100, 8000);
}

void setSpeed()
{
		//�ֱ������������pid
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
