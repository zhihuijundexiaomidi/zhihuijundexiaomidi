/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  lilingxiong
  * @version V0.1
  * @date    2022-03-30
  * @brief   led应用函数接口
  ******************************************************************************
  * @attention
  *一切的开端都要从点灯开始说起，mxcub能够直接初始化底层后，我们只需要把板级支持包的接口和
  *对应的硬件接口关联在一起。led只是简单的GPIO的输出操作，而hal库已经完成了这些硬件接口。我们
	*只需要从定义一下名字，让功能看起来更直观就可以了。
  ******************************************************************************
  */
	
#include "bsp_led.h"   
#include "stdint.h"
led_err_t led(uint8_t id,uint8_t state)
{
	led_err_t ERR=led_ok;
	if(id <= LED_ID_START || id >= LED_ID_END)
	{
		ERR=led_id_err;//返回错误的ID信息
	}
	if(state != OFF && state != LED_ID_END)
	{
		ERR=led_state_err;//返回错误的ID信息
	}
	if(state == OFF)
	{
				switch(id)
			{
				case red:LED_Red_OFF;break;
				case yellow:LED_Yellow_OFF;break;
				case green:LED_Green_OFF;break;
				default: break;
			}
	}
	else if(state == ON)
	{
			switch(id)
			{
				case red:LED_Red_ON;break;
				case yellow:LED_Yellow_ON;break;
				case green:LED_Green_ON;break;
				default: break;
			}
	}
	return ERR;
	
}



#if cmsis_os_enable
#include "cmsis_os.h"

void led_check(void)
{
	int i = 0;
	for(i=LED_ID_START+1;i<LED_ID_END;i++)
	{
			led(i,ON);
			osDelay(1000);//延迟一秒
			led(i,OFF);
//		  osDelay(1000);//延迟一秒
	}
}

#endif


