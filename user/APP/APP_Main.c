#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "cmsis_os.h"

#include "App_Main.h"

#include "bsp_led.h"  
#include "bsp_debug.h"
#include "bsp_exti.h"

static void Task01(void * argument);
osThreadId Task01_TaskHandle;

const osThreadAttr_t osID_Task01 = {
  .name = "osID_Task01",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

static void Task02(void * argument);
osThreadId Task02_TaskHandle;

const osThreadAttr_t osID_Task02 = {
  .name = "osID_Task02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

void APP_Main(void) {

      //定义线程任务01
  Task01_TaskHandle = osThreadNew(Task01, NULL, &osID_Task01);//创建线程任务01

	    //定义线程任务02
  Task02_TaskHandle = osThreadNew(Task02, NULL, &osID_Task02);//创建线程任务02


}




static void Task01(void * argument)
{

  for(;;)
  {
    led_check();
  }
}


static void Task02(void * argument)
{
	printf("串口重定义成功！pringtf打印信息正常。\r\n");
	EventBits_t r_event;  /* 定义一个事件接收变量 */
  for(;;)
  {
		r_event = xEventGroupWaitBits(EXTI_Key_Event_Handle,  /* 事件对象句柄 */
																		KEY01_UP_EVENT|KEY01_DOWN_EVENT|KEY02_UP_EVENT|KEY02_DOWN_EVENT,/* 接收线程感兴趣的事件 */
																		pdTRUE,   /* 退出时清除事件位 */
																		pdTRUE,   /* 满足感兴趣的所有事件 */
																		portMAX_DELAY);/* 指定超时事件,一直等 */
													
//			if((r_event & (KEY01_UP_EVENT|KEY01_DOWN_EVENT|KEY02_UP_EVENT|KEY02_DOWN_EVENT) == (KEY01_UP_EVENT|KEY01_DOWN_EVENT|KEY02_UP_EVENT|KEY02_DOWN_EVENT)) 
//			{
//				printf("123");
//			}
    osDelay(1000);
  }
}


