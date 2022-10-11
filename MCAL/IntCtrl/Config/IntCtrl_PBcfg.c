/******************************************************************************
*
* Module: IntCtrl
*
* File Name: IntCtrl.c
*
* Description: Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver.
******************************************************************************/

#include "IntCtrl.h"

/* PB structure used with IntCtrl_Init API */
const IntCtrl_ConfigType IntCtrl_Configuration = {
	SYSTICK,1,2


};
