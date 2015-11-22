/*
 *
 *   file  :  main.cpp
 *
 */



/***************   includes    *******************/

#include "_project_typedefs.h"
#include "_project_defines.h"
#include "_project_func_declarations.h"

#include "PRINTF_api.h"
#include "ARM_api.h"

#include "FLASH_api.h"
#include "NVIC_api.h"
#include "clocks_control_stm32f10x_api.h"


/***************   defines    *******************/

#define BUFFER_SIZE   2048


/***************   typedefs    *******************/


/**********   external variables    **************/
extern int __FLASH_START__;
extern int __APP_START_ON_FLASH_ADDR__;
extern int __APP_ENTRY_ADDR__;
extern int smihosting_is_active;

extern void	NVIC_APP_Init(void)  ;

/***********   loacal variables    **************/

/******************************************************/
/**** setup of static devices and device managment ****/

ARM_SH_API_CREATE_STATIC_DEV(sh_dev,"sh_arm");

INIT_STATIC_DEVICES(NULL);

pdev_descriptor_const semihosting_dev = &sh_dev;


/**** end ofsetup of static devices and device managment ****/
/************************************************************/

uint8_t buff[BUFFER_SIZE];


extern uint32_t  __RAM_START__ ;
#define NVIC_hal_RAM_Start			(&__RAM_START__) // defined in linker file

extern void do_software_interrupt_asm(void);


//pdev_descriptor semihosting_dev;

/* function : printf_init
 *
 *
 *
 */
void printf_init( void )
{
//	smihosting_is_active=1;
//	if(smihosting_is_active) // in semihost loader semihosting must always be on
//	{
		PRINTF_API_AddDebugOutput(semihosting_dev);
		PRINTF_API_AddNoteOutput(semihosting_dev);
//	}

//	PRINTF_API_AddDebugOutput(NULL,USB_Virtual_COM_API_SendData);
//	PRINTF_API_AddNoteOutput(NULL,USB_Virtual_COM_API_SendData);

//	PRINTF_API_AddDebugOutput(pUartHandle,UART_API_SendData);
//	PRINTF_API_AddNoteOutput(pUartHandle,UART_API_SendData);
}


static void prvSetupHardware( void )
{
	clocks_control_stm32f10x_init();


//	semihosting_dev=DEV_API_add_device((uint8_t*)"sh_arm",ARM_SH_API_Init_Dev_Descriptor);
	//ARM_SH_API_Init_Dev_Descriptor(semihosting_dev);
//	DEV_IOCTL(semihosting_dev , IOCTL_ARM_SH_PRINT_DONT_USE_TASK , 0 );
	DEV_IOCTL_0_PARAMS(semihosting_dev , IOCTL_DEVICE_START );

	printf_init();

	NVIC_API_Init();

}

typedef struct
{
	char *file_name;
	uint32_t address;
}image_t;

image_t images[]={
//		{"C:\\Work\\Booter_share\\booter.bin", (uint32_t)&__FLASH_START__},
//		{"C:\\Work\\Booter_share\\out.bin"	 , (uint32_t)&__APP_START_ON_FLASH_ADDR__}
		{BINARY_FILE	 , (uint32_t)&__APP_START_ON_FLASH_ADDR__}
};

/*
 * function : main()
 *
 */
int main(void)
{
	uint32_t i,prog_addr,fileHandle,file_size,read_size,total_read_size;
	uint32_t *pAppAddr __attribute__((unused));

	prvSetupHardware();

	pAppAddr = (uint32_t *)(&__APP_ENTRY_ADDR__);

	for(i=0 ; i < (sizeof(images)/sizeof(image_t)) ; i++)
	{
		PRINTF_DBG("programming %s ...\n",images[i].file_name);
		prog_addr=images[i].address;
		total_read_size=0;
		fileHandle=ARM_API_SH_Open(images[i].file_name,1);// rb - read,binary
		if ((fileHandle == 0 ) || (fileHandle == -1 ))
		{
			PRINT_STR_DBG("open fail\n");
		}
		else
		{
			file_size=ARM_API_SH_GetFileLength(fileHandle);
			FLASH_API_StartProgramming(prog_addr , file_size);
			while (BUFFER_SIZE > (read_size=ARM_API_SH_Read(fileHandle,buff,BUFFER_SIZE)))
			{
				read_size = BUFFER_SIZE - read_size;

				FLASH_API_ContinueProgramming(buff,read_size);
				total_read_size += read_size;
				PRINTF_DBG("%d.",(total_read_size));
			}

			ARM_API_SH_Close(fileHandle);
			PRINT_STR_DBG("done\n");
		}
	}

	pAppAddr=(uint32_t *)(((uint32_t)pAppAddr)+8); // activate semihosting

	// jump to application
	asm volatile(	"ldr r0,%[addr] \n"
    				"orr r0,r0,#0x01 \n"
    				"bx r0 \n"
    				: :[addr]"m"(pAppAddr):"memory");

	while(1)
	{

	}
}


