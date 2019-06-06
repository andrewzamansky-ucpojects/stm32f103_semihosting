/*
 *
 *   file  :  main.cpp
 *
 */



/***************   includes    *******************/

#include "_project_typedefs.h"
#include "_project_defines.h"
#include "_project_func_declarations.h"

#include "dev_management_api.h"


/***************   defines    *******************/


/***************   typedefs    *******************/


/**********   external variables    **************/

/***********   loacal variables    **************/

static const char hello_world_str[] = "++++++++hello world\r\n";

/*
 * function : main()
 *
 */
int main(void)
{
	struct dev_desc_t * dev;

	dev = DEV_OPEN("semihosting_dev");
	if (NULL == dev) goto error;
	DEV_IOCTL_0_PARAMS(dev, IOCTL_DEVICE_START);

	DEV_WRITE(dev, (uint8_t*)hello_world_str, sizeof(hello_world_str) - 1);

	while(1);
error :
	while(1);
}


