/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:04:56
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 10:36:44
 */

#include "loader.h"

static void read_disk (int sector, int sector_count, uint8_t buffer) {
    outb(0x1F6, 0xE0); // 选择硬盘，主盘或从盘
    outb(0x1F2, (uint8_t)sector_count >> 8;)
}

void load_kernel (void) {
    for (;;) {}
}