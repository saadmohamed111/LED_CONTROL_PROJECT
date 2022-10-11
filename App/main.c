#include "Led.h"
#include "IntCtrl.h"
#include "Dio.h"
#include "Port.h"
#include "SysTick.h"

static uint8 New_Tick_Flag = 0;

void Systick_New_Tick(void)
{
    
	/*a flag used as indication for new tick in the systick timer and then a new second indication */
    New_Tick_Flag = 1;
}

int main(void)
{
	Dio_Init(&Dio_Configuration);
  Port_Init(&Port_Configuration);
	IntCtrl_Init(&IntCtrl_Configuration);
	
	/*setting call back function to be called at executing of the systick ISR */
	SysTick_SetCallBack(Systick_New_Tick);
	
	/*setting time for generating interrupt to be every one second */
	SysTick_Start(1000);
	
	while(1)
	{
		if(New_Tick_Flag == 1)
		{
			LED_toggle();
			New_Tick_Flag = 0;
		}
	}
}
