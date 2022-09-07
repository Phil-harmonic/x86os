/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:04:56
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 10:53:30
 */

#include "loader.h"

static void read_disk (int sector, int sector_count, uint8_t buffer) {
    outb(0x1F6, 0xE0); // 选择硬盘，主盘或从盘
    outb(0x1F2, (uint8_t)(sector_count >> 8));
    outb(0x1F3, (uint8_t)(sector >> 24));
    outb(0x1F4, 0);
    outb(0x1F5, 0);

    outb(0x1F2, (uint8_t)sector_count);
    outb(0x1F2, (uint8_t)sector);
    outb(0x1F2, (uint8_t)(sector >> 8));
    outb(0x1F2, (uint8_t)(sector >> 16));

    outb(0x1F7, 0x24);

    uint16_t *data_buf = (uint16_t*)buffer;

    while (sector_count--) {
        while ((inb(0x1F7) & 0x88) != 0x8) {}

        for (int i = 0; i < SECTOR_SIZE / 2; i++) {
            *data_buf++ = inw(0x1F0);
        }
    }
}

void load_kernel (void) {
    read_disk(100, 500, (uint8_t*)SYS_KERNEL_LOAD_ADDR);
    for (;;) {}
}