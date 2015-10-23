#include <stm32f4xx_gpio.h>
#include "stm32f4xx.h"
#include "misc.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "stm32f4xx_gpio.h"

#include "diagnostics.h"

static void init_leds (void);

int main(void) {

    SystemInit();

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);


    init_leds();

//    GPIO_InitTypeDef  GPIO_InitStructure;
//    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//
//    GPIO_SetBits(GPIOD, GPIO_Pin_7);

    vTaskStartScheduler();
}

static void init_leds (void)
{
    LEDInitStruct_t led_init_struct;

    led_init_struct.GPIOx = GPIOD;
    led_init_struct.off_time = 0;
    led_init_struct.on_time = 0;
    led_init_struct.GPIO_Clock = RCC_AHB1Periph_GPIOD;
    led_init_struct.purpose = LED_PURPOSE_CAN;
    led_init_struct.GPIO_Pin = GPIO_Pin_7;
    led_init(CAN_LED,&led_init_struct);

    led_init_struct.purpose = LED_PURPOSE_ERROR;
    led_init_struct.GPIO_Pin = GPIO_Pin_2;
    led_init(GEN_ERROR_LED,&led_init_struct);

    led_init_struct.purpose = LED_PURPOSE_APPLICATION;
    led_init_struct.GPIO_Pin = GPIO_Pin_6;
    led_init(WARNING_LED,&led_init_struct);

    led_init_struct.GPIO_Pin = GPIO_Pin_5;
    led_init(MOT_ERROR_LED,&led_init_struct);

    led_init_struct.GPIO_Pin = GPIO_Pin_4;
    led_init(V_ERROR_LED,&led_init_struct);

    led_init_struct.GPIO_Pin = GPIO_Pin_3;
    led_init(I_ERROR_LED,&led_init_struct);
    led_off(I_ERROR_LED);
    GPIO_WriteBit()

    led_init_struct.off_time = 500;
    led_init_struct.on_time = 500;

    led_init_struct.GPIOx = GPIOB;
    led_init_struct.GPIO_Clock = RCC_AHB1Periph_GPIOB;
    led_init_struct.GPIO_Pin = GPIO_Pin_5;
    led_init(HEARTBEAT,&led_init_struct);
}
