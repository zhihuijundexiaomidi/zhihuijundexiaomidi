#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "App_Main.h"

#include "bsp_led.h"  
#include "bsp_debug.h"

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
  for(;;)
  {
    osDelay(1000);
  }
}


