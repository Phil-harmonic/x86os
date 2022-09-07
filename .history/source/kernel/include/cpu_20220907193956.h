/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-07 19:34:26
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 19:39:52
 */
#ifndef CPU_H
#define CPU_H

#include "comm/types.h"

/**
 * GDT描述符
 */
typedef struct _segment_desc_t {
	uint16_t limit15_0;
	uint16_t base15_0;
	uint8_t base23_16;
	uint16_t attr;
	uint8_t base31_24;
} segment_desc_t;


#endif