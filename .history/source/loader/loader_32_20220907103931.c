/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:04:56
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 10:39:15
 */

#include "loader.h"

static void read_disk (int sector, int sector_count, uint8_t buffer) {
    outb(0x1F6, 0xE0); // 选择硬盘，主盘或从盘
    outb(0x1F2, (uint8_t)(sector_count >> 8));
    outb(0x1F3, (uint8_t)(sector >> 24));
    outb(0x1F4, 0);
    outb(0x1F5, 0);

    outb(ox1F2, (uint8_t)sector_count);
    outb(ox1F2, (uint8_t)sector);
    outb(ox1F2, (uint8_t)(sector >> 8));
    outb(ox1F2, (uint8_t)(sector >> 16));

    outb(0x1F7, 0x24);
}

void load_kernel (void) {
    for (;;) {}
}