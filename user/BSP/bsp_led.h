#ifndef _BSP_LED_H
#define	_BSP_LED_H
#include "stm32f4xx.h"
/*******************************************************/
//功能开关
#define 	cmsis_os_enable		1

/*******************************************************/

//引脚定义
/*******************************************************/
//R 红色灯
#define LED1_PIN                  GPIO_PIN_10                 
#define LED1_GPIO_PORT            GPIOH                      
#define LED1_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()

//G 绿色灯
#define LED2_PIN                  GPIO_PIN_11                 
#define LED2_GPIO_PORT            GPIOH                      
#define LED2_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()

//B 蓝色灯
#define LED3_PIN                  GPIO_PIN_12                 
#define LED3_GPIO_PORT            GPIOH                       
#define LED3_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()
/************************************************************/

/** 控制LED灯亮灭的宏，
	* LED低电平亮，设置ON=0，OFF=1
	* 若LED高电平亮，把宏设置成ON=1 ，OFF=0 即可
	*/
#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

/* 带参宏，可以像内联函数一样使用 */
#define LED_Red(a)	  HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,a)


#define LED_Green(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,a)


#define LED_Yellow(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED3_PIN,a)



/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)			{p->BSRR=i;}			  //设置为高电平		
#define digitalLo(p,i)			{p->BSRR=(uint32_t)i << 16;}				//输出低电平
#define digitalToggle(p,i)	{p->ODR ^=i;}			//输出反转状态


/* 定义控制IO的宏 */
#define LED_Red_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED_Red_OFF		    digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED_Red_ON			  digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED_Green_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED_Green_OFF		    digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED_Green_ON			  digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED_Yellow_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED_Yellow_OFF		  digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED_Yellow_ON			  digitalLo(LED3_GPIO_PORT,LED3_PIN)


/* 基本混色，后面高级用法使用PWM可混出全彩颜色,且效果更好 */

//红
#define LED_RED  \
					LED1_ON;\
					LED2_OFF\
					LED3_OFF

//绿
#define LED_GREEN		\
					LED1_OFF;\
					LED2_ON\
					LED3_OFF

//蓝
#define LED_BLUE	\
					LED1_OFF;\
					LED2_OFF\
					LED3_ON

					
//黄(红+绿)					
#define LED_YELLOW	\
					LED1_ON;\
					LED2_ON\
					LED3_OFF
//紫(红+蓝)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF\
					LED3_ON

//青(绿+蓝)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON\
					LED3_ON
					
//白(红+绿+蓝)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON\
					LED3_ON
					
//黑(全部关闭)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF\
					LED3_OFF
typedef enum {
	LED_ID_START=0,
	red,
	yellow,
	green,
	LED_ID_END,
} led_id_t;		

typedef enum {
  led_ok=1,
	led_id_err,
	led_state_err,
} led_err_t;	


led_err_t led(uint8_t id,uint8_t state);


#if cmsis_os_enable 

void led_check(void);

#endif					

#endif /* __LED_H */
