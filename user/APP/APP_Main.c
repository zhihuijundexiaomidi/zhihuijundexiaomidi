#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "App_Main.h"

#include "bsp_led.h"  


void Task01(void * argument);
osThreadId Task01_TaskHandle;

const osThreadAttr_t osID_Task01 = {
  .name = "osID_Task01",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

void APP_Main(void) {

      //定义线程任务01
  Task01_TaskHandle = osThreadNew(Task01, NULL, &osID_Task01);//创建线程任务01



}




void Task01(void * argument)
{

  for(;;)
  {
    led_check();
  }
}





