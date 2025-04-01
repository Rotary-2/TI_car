#include "iravoid.h"
#include "stm32f10x.h"
#include "sys.h"
#include "moto.h"
#include "delay.h"

/**
* Function       IRAvoid_GPIO_Init
  
* @brief         ������ϴ�����GPIO��ʼ���ӿ�
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void IRAvoid_GPIO_Init(void)
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

#ifdef USE_IRAVOID_L1
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(IRAvoid_L1_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = IRAvoid_L1_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J4_PORT*/
  	GPIO_Init(IRAvoid_L1_PORT, &GPIO_InitStructure);		 
#endif

#ifdef USE_IRAVOID_R1
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(IRAvoid_R1_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = IRAvoid_R1_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J4_PORT*/
  	GPIO_Init(IRAvoid_R1_PORT, &GPIO_InitStructure);	
#endif

}
/**
* Function       bsp_GetIRavoid  
* @brief         ���ϴ�������ȡ״̬
* @param[in]     int *p_iL1, int *p_iR1 ���ұ���ָ��
* @param[out]    void
* @retval        void
* @par History   ��
*/

void bsp_GetIRavoid(int *p_iL1, int *p_iR1)
{
	*p_iL1 = GPIO_ReadInputDataBit(IRAvoid_L1_PORT, IRAvoid_L1_PIN);
	*p_iR1 = GPIO_ReadInputDataBit(IRAvoid_R1_PORT, IRAvoid_R1_PIN);	
}

/**
* Function       bsp_GetIRavoid_Data   
* @brief         ���ϴ�������ȡ״̬�ϱ�����
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/

int bsp_GetIRavoid_Data(void)
{
	int L1,R1,ReturnValue;
	L1 = GPIO_ReadInputDataBit(IRAvoid_L1_PORT, IRAvoid_L1_PIN);
	R1 = GPIO_ReadInputDataBit(IRAvoid_R1_PORT, IRAvoid_R1_PIN);
	ReturnValue = (L1 == 0 ? 10 : 0);
	ReturnValue += (R1 == 0 ? 1 : 0);
	return ReturnValue;
}


/**
* Function       app_IRAvoid
* @brief         �������ģʽ�˶�
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_IRAvoid(void)
{
	int IRL1 = 1, IRR1 = 1;

	bsp_GetIRavoid(&IRL1, &IRR1);

	/*�Ҳ��⵽*/
  	if( IRL1 == HIGH && IRR1 == LOW)
    {
      	SpinLeft(7000);
    }
	/*����⵽*/
    else if ( IRL1 == LOW && IRR1 == HIGH)
    {
      	SpinRight(7000);
    }
	/*���Ҿ�δ��⵽*/  
    else if (IRL1 == HIGH && IRR1 == HIGH)
    {   
		Forward(6000);
	}
	/*���Ҿ���⵽*/
    else if(IRL1 == LOW && IRR1 == LOW) 
    {  
		SpinRight(7000);
		delay_ms(500);
	}	
}

