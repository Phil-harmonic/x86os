/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-07 11:08:43
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 21:07:57
 */
#include "init.h"
#include "comm/boot_info.h"
#include "cpu/cpu.h"

void kernel_init (boot_info_t *boot_info) {
    cpu_init();
}

void init_main (void) {
    for (;;) {}
}