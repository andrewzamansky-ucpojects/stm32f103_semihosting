## imported variable $(APP_ROOT_DIR) is location of main
## makefile of current project
## 

PROJECT_NAME := semihosting_loader_stm32

###################################
#####   global flags :  #########
GLOBAL_PROJECT_SPECIFIC_CFLAGS +=  
#GLOBAL_PROJECT_SPECIFIC_CFLAGS += -fstack-usage -fcallgraph-info
GLOBAL_PROJECT_SPECIFIC_ASMLAGS += 
GLOBAL_PROJECT_SPECIFIC_LDFLAGS += 




###################################
#####   global defines :  #########
GLOBAL_DEFINES += NDEBUG #to disable  assert() macro
GLOBAL_DEFINES += STM32F10X_MD USE_STM3210B_EVAL 
##########################################
#####   global include files path :  #####   
#GLOBAL_INCLUDE_DIR +=  

######################################
#####  directiries to compile :  #####   
#SUBDIRS	 +=  



###################################
#####   components configuration includes folder :  #####  
 
###################################
#####   include components :  #####  
 
CONFIG_SOC_TYPE = stm32f10x#{nuc505,stm32f10x,stm8,atmega328,poleg}
CONFIG_INCLUDE_DEV_MENAGMENT = YES
CONFIG_INCLUDE_VERSION_MENAGMENT = YES
CONFIG_INCLUDE_PRINTF = YES
#CONFIG_INCLUDE_OS = freeRtos#{freeRtos,atomthreads}
#CONFIG_INCLUDE_BUILT_IN_FLASH = YES
#CONFIG_INCLUDE_HTTP = YES
#CONFIG_INCLUDE_ESP8266 = YES
#CONFIG_INCLUDE_UART = YES
#CONFIG_INCLUDE_UART_STM32_UART = YES
#CONFIG_INCLUDE_UART_USB_VIRTUAL_COM = YES
#CONFIG_INCLUDE_UART_ARM_SEMIHOSTING = YES
#CONFIG_INCLUDE_CONFIG = YES
#CONFIG_INCLUDE_JSMN = YES
#CONFIG_INCLUDE_UBOOT_SHELL = YES
#CONFIG_INCLUDE_USB_VIRTUAL_COM = YES
#CONFIG_INCLUDE_USB_MASS_STORAGE = YES
#CONFIG_INCLUDE_GPIO = YES
#CONFIG_INCLUDE_SERIAL_NUMBER = YES
CONFIG_INCLUDE_INTERNAL_CLOCK_CONTROL = YES
#CONFIG_INCLUDE_FAT_FS = YES
#CONFIG_INCLUDE_SPI_FLASH = YES
#CONFIG_INCLUDE_SYSTEM_TICK = YES
#CONFIG_INCLUDE_SHELL = YES
CONFIG_INCLUDE_NVIC = YES
#CONFIG_INCLUDE_LM35 = YES
#CONFIG_INCLUDE_ADC = YES
CONFIG_INCLUDE_INTERNAL_FLASH = YES

CONFIG_INCLUDE_STD_LIBRARIES = libc_nano.a


######################################
#####   misc configs  #####  

CONFIG_OUTPUT_NAME 						= semihosting_loader_stm32#if not used then name is 'out'
CONFIG_CPU_TYPE  						= cortex-m3#{cortex-a9,arm926ej-s,cortex-m3,stm8}
CONFIG_USE_COMPILER 					= ARM-NONE-EABI-GCC#{ARM-NONE-EABI-GCC,ARMCC,CXSTM8}
CONFIG_GCC_COMPILER_VERSION				= 4.9.3#{4.9.2,4.9.3}
CONFIG_RAM_START_ADDR  					= 0x20000000
CONFIG_RAM_SIZE							= 20k#add K for kilobytes or M for megabytes
CONFIG_FLASH_START_ADDR 				= 0x8000000
CONFIG_FLASH_SIZE						= 128k#add K for kilobytes or M for megabytes
CONFIG_CODE_LOCATION					= ram#{ram,flash}
#CONFIG_USED_FOR_SEMIHOSTING_UPLOADING 	= YES
CONFIG_OPTIMIZE_LEVEL 					= O0#{O0,O1,O2,O3,Os}
#CONFIG_POSITION_INDEPENDENT 			= YES // not yet implemented
CONFIG_CALCULATE_CRC32 					= YES
