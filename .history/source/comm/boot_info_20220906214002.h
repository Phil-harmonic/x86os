/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 21:38:26
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 21:40:02
 */
#ifndef BOOT_INFO_H
#define BOOT_INFO_H

#include "types.h"

typedef struct SMAP_entry {
 
	uint32_t BaseL; // base address uint64_t
	uint32_t BaseH;
	uint32_t LengthL; // length uint64_t
	uint32_t LengthH;
	uint32_t Type; // entry Type，值为1时表明为我们可用的RAM空间
	uint32_t ACPI; // extended, bit0=0时表明此条目应当被忽略
 
}__attribute__((packed)) SMAP_entry_t;

#endif