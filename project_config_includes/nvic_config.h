/*
 * file : nvic_config.h
 *
 *
 *
 *
 *
 *
 */

#ifndef _nvic_config_H
#define _nvic_config_H

#include "_project_typedefs.h"
#include "_project_defines.h"
#include "_project_func_declarations.h"

#include "stm32f10x.h"

#define NVIC_CONFIG_START_OF_RAM	CONFIG_RAM_START_ADDR
//#define __CHECK_DEVICE_DEFINES
//#define __CMSIS_GENERIC

#if 0 // already defined in stm32f10x.h
typedef enum IRQn
{
/******  Cortex-M# Processor Exceptions Numbers ***************************************************/

///* ToDo: use this Cortex interrupt numbers if your device is a CORTEX-M0 device                   */
//  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
//  HardFault_IRQn                = -13,      /*!<  3 Hard Fault Interrupt                          */
//  SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
//  PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
//  SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

/* ToDo: use this Cortex interrupt numbers if your device is a CORTEX-M3 / Cortex-M4 device       */
  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
  MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt                   */
  BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt                           */
  UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt                         */
  SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
  DebugMonitor_IRQn             = -4,       /*!< 12 Debug Monitor Interrupt                       */
  PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
  SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

/******  Device Specific Interrupt Numbers ********************************************************/
/* ToDo: add here your device specific external interrupt numbers
         according the interrupt handlers defined in startup_Device.s
         eg.: Interrupt for Timer#1       TIM1_IRQHandler   ->   TIM1_IRQn                        */
//  <DeviceInterrupt>_IRQn        = 0,        /*!< Device Interrupt                                 */
	NVIC_API_Int_TIM1_UP = (  25 ),
	NVIC_API_Int_USB_RX = (  20 ),
	NVIC_API_Int_USART1_RX = ( 37 ),
	NVIC_API_Int_USART2_RX = ( 38 ),
	NVIC_API_Int_USART3_RX = (  39 ),
} IRQn_Type;

#endif

#endif /* */
