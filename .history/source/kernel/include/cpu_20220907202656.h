/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-07 19:34:26
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 20:26:29
 */
#ifndef CPU_H
#define CPU_H

#include "comm/types.h"

#pragma pack(1)
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
#pragma pack()

#define SEG_G (1 << 15)
#define SEG_D (1 << 14)

void cpu_init (void); 
void segment_desc_set(int selector, uint32_t base, uint32_t limit, uint16_t attr);

#endif