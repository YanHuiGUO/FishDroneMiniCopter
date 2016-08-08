/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

/* Ensure stdint is only used by the compiler, and not the assembler. */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
	#include <stdint.h>
	extern uint32_t SystemCoreClock;
#endif

#define configUSE_PREEMPTION			1 							// 使能抢占式调度器
#define configUSE_IDLE_HOOK				0 							// 失能空闲任务的钩子函数
#define configUSE_TICK_HOOK				0 							// 失能滴答定时器中断里面执行的钩子函数
#define configCPU_CLOCK_HZ				(SystemCoreClock )			// 定义 CPU 的主频
#define configTICK_RATE_HZ				( ( TickType_t ) 1000 )	    // 定义系统时钟节拍数,单位 Hz,一般取 1000Hz 即可。过高的的系统时钟节拍将使得 FreeRTOS 内核运行占用过多的时间，增加系统负荷。
#define configMAX_PRIORITIES			( 6 )						// 定义可供用户使用的最大优先级数, 如果这个定义的是 5，那么用户可以使用的优先级号是 0,1,2,3,4，不包含 5
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 130 )	// 定义空闲任务的栈空间大小，单位字，即 4 字节。
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 75 * 1024 ) )// 定义堆大小,FreeRTOS 内核,用户动态内存申请,任务栈,任务创建,信号量创建,消息队列创建等都需要用这个空间。
#define configMAX_TASK_NAME_LEN			( 16 )						// 定义任务名最大的字符数，末尾的结束符 '\0'也要计算在内
#define configUSE_TRACE_FACILITY		1 							// 使能此配置将添加额外的结构体成员和函数，以此来协助可视化和跟踪
#define configUSE_16_BIT_TICKS			0                           // 系统时钟节拍计数使用 TickType_t 数据类型定义的.如果用户使能了宏定义 configUSE_16_BIT_TICKS，
																	// 那么 TickType_t 定义的就是 16 位无符号数，如果没有使能，那么 TickType_t 定义的就是 32 位无符号数。
#define configIDLE_SHOULD_YIELD			1
#define configUSE_MUTEXES				1 							// 使能互斥信号量
#define configQUEUE_REGISTRY_SIZE		8 							// 通过此定义来设置可以注册的信号量和消息队列个数	
#define configCHECK_FOR_STACK_OVERFLOW	0 							// 禁止栈溢出检测
#define configUSE_RECURSIVE_MUTEXES		1 							// 失能递归互斥信号量
#define configUSE_MALLOC_FAILED_HOOK	0 							// 失能动态内存申请失败时的钩子函数.(当创建任务，信号量或者消息队列时，FreeRTOS 通过函数 pvPortMalloc()申请动态内存)
#define configUSE_APPLICATION_TASK_TAG	0
#define configUSE_COUNTING_SEMAPHORES	1 							// 使能计数信号量
#define configGENERATE_RUN_TIME_STATS	0 							// 使能任务运行状态参数统计

/* Co-routine definitions.合作式任务配置 */
#define configUSE_CO_ROUTINES 			0 							// 禁能合作式调度相关函数
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 ) 						// 定义可供用户使用的最大的合作式任务优先级数

/* Software timer definitions. 软件定时器配置*/
#define configUSE_TIMERS				1 							// 使能软件定时器
#define configTIMER_TASK_PRIORITY		( 2 ) 						// 配置软件定时器任务的优先级
#define configTIMER_QUEUE_LENGTH		10 							// 配置软件定时器命令队列的长度
#define configTIMER_TASK_STACK_DEPTH	( configMINIMAL_STACK_SIZE * 2 ) // 配置软件定时器任务的栈空间大小

/* Set the following definitions to 1 to include the API function, or zero to exclude the API function. */
#define INCLUDE_vTaskPrioritySet		1     // 使能 FreeRTOS 的任务优先级修改函数 vTaskPrioritySet 可供用户调用
#define INCLUDE_uxTaskPriorityGet		1     // 使能 FreeRTOS 的任务优先级获取函数 uxTaskPriorityGet 可供用户调用
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
	/* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4        /* 15 priority levels */
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority" function. */
// 配置 FreeRTOS 用到的 SysTick 中断和 PendSV 中断的优先级. 在 NVIC 分组设置为 4 的情况下，此宏定义的范围就是 0-15，即专门配置抢占优先级。
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			0xf

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
// 表示用户可以在抢占式优先级为 1到15的中断里面调用FreeRTOS的API函数，抢占优先级为0的中断里面是不允许被调用的。
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	0x01

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
	
/* Normal assert() semantics without relying on the provision of an assert.h header file. */
// 断言配置
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }	
	
/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */

