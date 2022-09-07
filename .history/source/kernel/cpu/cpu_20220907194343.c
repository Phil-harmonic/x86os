/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-07 19:40:22
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 19:43:18
 */
#include "cpu/cpu.h"
#include "os_cfg.h"

static segment_desc_t gdt_table[GDT_TABLE_SIZE];