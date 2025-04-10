#ifndef __JY61P_H
#define __JY61P_H

#include "stm32f10x.h"

void JY61PInit(void);
void JY61PWork(void);
void CopeCmdData(unsigned char ucData);
static void ShowHelp(void);
static void CmdProcess(void);
static void SensorUartSend(uint8_t *p_data, uint32_t uiSize);
static void Delayms(uint16_t ucMs);
static void SensorDataUpdata(uint32_t uiReg, uint32_t uiRegNum);
static void AutoScanSensor(void);

#endif