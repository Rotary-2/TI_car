#include "stm32f10x.h"
#include "three_linewalking.h"
#include "sys.h"
#include "moto.h"
#include "delay.h"

/**
* Function       three_LineWalking_GPIO_Init
* @brief         Ѳ�ߴ�����GPIO��ʼ���ӿ�
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void three_LineWalking_GPIO_Init(void)
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

#ifdef USE_LINE_L
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(LineWalk_L_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = LineWalk_L_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��PORT*/
  	GPIO_Init(LineWalk_L_PORT, &GPIO_InitStructure);		 
#endif

#ifdef USE_LINE_M
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(LineWalk_M_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = LineWalk_M_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��PORT*/
  	GPIO_Init(LineWalk_M_PORT, &GPIO_InitStructure);	
#endif

#ifdef USE_LINE_R
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(LineWalk_R_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = LineWalk_R_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��PORT*/
  	GPIO_Init(LineWalk_R_PORT, &GPIO_InitStructure);	
#endif
	
}


/**
* Function       three_GetLineWalking
* @brief         ��ȡѲ��״̬
* @param[in]     int *p_iL, int *p_iM,  int *p_iR  ��·Ѳ��λָ��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void three_GetLineWalking(int *p_iL, int *p_iM, int *p_iR)
{
	*p_iL = GPIO_ReadInputDataBit(LineWalk_L_PORT, LineWalk_L_PIN);
	*p_iM = GPIO_ReadInputDataBit(LineWalk_M_PORT, LineWalk_M_PIN);
	*p_iR = GPIO_ReadInputDataBit(LineWalk_R_PORT, LineWalk_R_PIN);
		
}

/**
* Function       three_LineWalking  
* @brief         Ѳ��ģʽ�˶�
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void three_LineWalking(void)
{
	int LineL = 0, LineM = 0, LineR = 0;

	three_GetLineWalking(&LineL, &LineM, &LineR);	//��ȡ���߼��״̬	

//  if( LineL == HIGH &&  LineM == HIGH) //ֱ�����
//    {  
//		SpinLeft(7000);
//		delay_ms(30);
//	}
//    else if ( LineM == HIGH && LineR == HIGH) //ֱ�����
//    {  
//		SpinRight(7000);
//		delay_ms(30);
//	}
//    if (LineL == LOW ) //���������΢������ת
//    {   
//		Turnleft(6000);   
//	}
//	else 
		if ( LineR == HIGH) //���������΢������ת
    {   
		Turnright(6000);   
	}
//    else if(LineM == LOW ) // ��ɫ, ����ǰ��
//    {  
//		Forward(6000);
//	}	
//   else if(LineL == HIGH && LineM == HIGH && LineR == HIGH) // ��ɫ, ����ǰ��
//    {  
//		Forward(6000);
//	}	
//		

}



