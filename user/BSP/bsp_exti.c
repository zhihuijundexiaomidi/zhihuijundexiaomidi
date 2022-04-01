/**
  ******************************************************************************
  * @brief   I/O线中断应用bsp
  ******************************************************************************
  ******************************************************************************
  */
  
#include "bsp_exti.h"
#include <stdio.h>
#include "bsp_debug.h"


EventGroupHandle_t EXTI_Key_Event_Handle =NULL;
 /**
  * @brief  配置 PA0 为线中断口，并设置中断优先级
  * @param  无
  * @retval 无
  */
void EXTI_Key_Config(void)
{
		/* 创建 Event_Handle */
    EXTI_Key_Event_Handle = xEventGroupCreate();	 
	 if(NULL != EXTI_Key_Event_Handle)
    debug_printf("infra_red_Event_Handle 事件创建成功!\r\n");
	 else
		debug_printf("infra_red_Event_Handle 事件创建失败!\r\n");
}


BaseType_t xHigherPriorityTaskWoken = pdFALSE;

void KEY1_IRQHandler_APP(void)
{
	GPIO_PinState bitstatus = key01_state;
  //确保是否产生了EXTI Line中断
	if(__HAL_GPIO_EXTI_GET_IT(KEY01_Pin) != RESET) 
	{
		//key1 event 
			if(bitstatus == state_H)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY01_DOWN_EVENT,&xHigherPriorityTaskWoken);
			}
		  else if(bitstatus == state_L)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY01_UP_EVENT,&xHigherPriorityTaskWoken);
			}
			
		
    //清除中断标志位
		__HAL_GPIO_EXTI_CLEAR_IT(KEY01_Pin);     
	}  
}

void KEY2_IRQHandler_APP(void)
{
	GPIO_PinState bitstatus = key01_state;
  //确保是否产生了EXTI Line中断
	if(__HAL_GPIO_EXTI_GET_IT(KEY02_Pin) != RESET) 
	{
		//key2 event 
			if(bitstatus == state_H)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY02_DOWN_EVENT,&xHigherPriorityTaskWoken);
			}
		  else if(bitstatus == state_L)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY02_UP_EVENT,&xHigherPriorityTaskWoken);
			}	
		
    //清除中断标志位
		__HAL_GPIO_EXTI_CLEAR_IT(KEY02_Pin);     
	}  
}



