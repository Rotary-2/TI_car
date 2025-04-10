/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         iravoid.h
* @version      V1.0
* @brief        �����������ͷ�ļ�
* @details      
* @par History  ������˵��
*                 
*/

/*

	�ӳ��������ǰ���� ��ൽ�ұ�	  ��Ӧԭ��ͼ PB4 || PB5

*/

#ifndef __IRAVOID_H__
#define __IRAVOID_H__	

/*������Ͽ���*/
#define USE_IRAVOID_L1
#define USE_IRAVOID_R1
void IRAvoid_GPIO_Init(void);

#define IRAvoid_L1_RCC		RCC_APB2Periph_GPIOB
#define IRAvoid_R1_RCC		RCC_APB2Periph_GPIOB

#define IRAvoid_L1_PIN		GPIO_Pin_4
#define IRAvoid_R1_PIN		GPIO_Pin_5

#define IRAvoid_L1_PORT		GPIOB
#define IRAvoid_R1_PORT		GPIOB


void bsp_GetIRavoid(int *p_iL1, int *p_iR1);
int bsp_GetIRavoid_Data(void);
void app_IRAvoid(void);


#endif
