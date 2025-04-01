#ifndef __PS2_CONTROL_H__
#define __PS2_CONTROL_H__

#include "stm32f10x.h"
#include "sys.h"

#define PS2_MOSI_PIN	GPIO_Pin_15
#define PS2_MOSI_PORT	GPIOB
#define PS2_MOSI_RCC	RCC_APB2Periph_GPIOB

#define PS2_MISO_PIN	GPIO_Pin_14
#define PS2_MISO_PORT	GPIOB
#define PS2_MISO_RCC	RCC_APB2Periph_GPIOB


#define PS2_CS_PIN		GPIO_Pin_8
#define PS2_CS_PORT		GPIOA
#define PS2_CS_RCC		RCC_APB2Periph_GPIOA


#define PS2_SCK_PIN		GPIO_Pin_13
#define PS2_SCK_PORT	GPIOB
#define PS2_SCK_RCC		RCC_APB2Periph_GPIOB




#define DI   PBin(15)           //PB15  ����

#define DO_H PBout(14)=1        //����λ��
#define DO_L PBout(14)=0        //����λ��

#define CS_H PAout(8)=1       //CS����
#define CS_L PAout(8)=0       //CS����

#define CLC_H PBout(13)=1      //ʱ������
#define CLC_L PBout(13)=0      //ʱ������



//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2          9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      16



//These are stick values
#define PSS_RX 5                //��ҡ��X������
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

/*С������״̬ö��*/
enum{

  enSTOP = 0,
  enRUN,
  enBACK,
  enLEFT,
  enRIGHT,
  enUPLEFT,
  enUPRIGHT,
  enDOWNLEFT,
  enDOWNRIGHT,  
  enTLEFT,
  enTRIGHT

};

extern int g_CarState;
extern int CarSpeedControl;


extern u8 Data[9];
extern u16 MASK[16];
extern u16 Handkey;

void PS2_Init(void);
u8 PS2_DataKey(void);		  //��ֵ��ȡ
u8 PS2_AnologData(u8 button); //�õ�һ��ҡ�˵�ģ����
void PS2_ClearData(void);	  //������ݻ�����

void app_ps2_deal(void);
void app_CarstateOutput(void);



#endif

