#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include "delay.h"
#include "moto.h"
#include "servo.h"
#include "linewalking.h"
#include "ultrasonic.h"
#include "usart.h"
#include "adc.h"


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

extern int g_CarState; //  1ǰ2��3��4��0ֹͣ
extern int CarSpeedControl;


void Protocol(void);



#endif
