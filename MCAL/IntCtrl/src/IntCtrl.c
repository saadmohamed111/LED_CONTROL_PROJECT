/******************************************************************************
*
* Module: IntCtrl
*
* File Name: IntCtrl.c
*
* Description: Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver.
******************************************************************************/
#include "IntCtrl.h"
#include "IntCtrl_Regs.h"



STATIC uint8 IntCtrl_Status = INTCTRL_NOT_INITIALIZED;

/************************************************************************************
* Service Name: IntCtrl_Init
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/

void IntCtrl_Init(const IntCtrl_ConfigType* ConfigPtr)
{
	EXCEPTIONS_STATE;
	
	APINT = GROUP_SUBGROUP_FORMAT;
	
	uint8 i;
	
	for(i=0; i<INTCTRL_CONFIGURED_CHANNLES; i++)
	{
		if(ConfigPtr->Channels[i].InterruptPeripheralGates == SYSTICK)
		{
			/* Assign priority level 1 to the SysTick Interrupt */
			NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & 0x1FFFFFFF) | ((ConfigPtr->Channels[i].IntCtrl_GroupPriority) << 29);
		}
		else
		{
			/*do nothing */ 
		}
	}
}