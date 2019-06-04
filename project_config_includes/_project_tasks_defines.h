/*
 * file : _project_tasks_defines.h
 *
 *
 */

#ifndef _project_tasks_defines_H
#define _project_tasks_defines_H

#include "project_config.h"


/******   task priorities *********/
#define HEARTBEAT_THREAD_PRIORITY           (tskIDLE_PRIORITY + 1)
#define AUDIO_PATH_THREAD_PRIORITY          (tskIDLE_PRIORITY + 4)
#define SHELL_TASK_PRIORITY                 (tskIDLE_PRIORITY + 3)
#define ASYNC_TX_WRAPPER_TASK_PRIORITY      (tskIDLE_PRIORITY + 3)
#define FLASH_WRAPPER_TASK_PRIORITY         (tskIDLE_PRIORITY + 2)
/*********************************/


#define ADDITIONAL_STACK_SAFETY_MARGIN  20
#define DEFINE_STACK_SIZE(n)    (n + ADDITIONAL_STACK_SAFETY_MARGIN)
/******   task stack sizes *********/
#define HEARTBEAT_STACK_SIZE_BYTES              DEFINE_STACK_SIZE( 800 )
#define AUDIO_PATH_STACK_SIZE_BYTES             DEFINE_STACK_SIZE( 2000 )
#define SHELL_TASK_STACK_SIZE                   DEFINE_STACK_SIZE( 1500 )
#define ASYNC_TX_WRAPPER_TASK_STACK_SIZE        DEFINE_STACK_SIZE( 800 )
#define FLASH_WRAPPER_TASK_STACK_SIZE           DEFINE_STACK_SIZE( 800 )
/***********************************/


/***********************************/

#endif /* */
