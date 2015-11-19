/*
 * file : global_typedefs.h
 *
 *
 *
 *
 *
 *
 */

#ifndef _global_typedefs_H
#define _global_typedefs_H

#include <stdio.h>
#include "stdint.h"
#include "stdlib.h"
#include <string.h>
#include <ctype.h>
#include "dev_managment_api.h"
#include "PRINTF_api.h"

#define ADDITIONAL_STACK_SAFATY_MARGIN	 20
#define DEFINE_STACK_SIZE(n)    (n + ADDITIONAL_STACK_SAFATY_MARGIN)

#define TASK_NORMAL_PRIORITY    (tskIDLE_PRIORITY + 1)


#else
#pragma message( "warning : this header file had already been included" )
#endif /* */
