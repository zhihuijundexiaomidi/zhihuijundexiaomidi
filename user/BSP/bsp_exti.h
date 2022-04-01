#ifndef __EXTI_H
#define	__EXTI_H

#include "main.h"
#include "FreeRTOS.h"
#include "event_groups.h"


extern EventGroupHandle_t EXTI_Key_Event_Handle;

/*******************************************************/
#define KEY01_UP_EVENT  (0x01 << 0)//设置事件掩码的位0
#define KEY01_DOWN_EVENT  (0x01 << 1)//设置事件掩码的位1
#define KEY02_UP_EVENT  (0x01 << 2)//设置事件掩码的位2
#define KEY02_DOWN_EVENT  (0x01 << 3)//设置事件掩码的位3

#define key01_state    HAL_GPIO_ReadPin(KEY01_GPIO_Port, KEY01_Pin)
#define key02_state    HAL_GPIO_ReadPin(KEY02_GPIO_Port, KEY02_Pin)

#define state_H			GPIO_PIN_SET
#define state_L			GPIO_PIN_RESET

void EXTI_Key_Config(void);

#endif /* __EXTI_H */
