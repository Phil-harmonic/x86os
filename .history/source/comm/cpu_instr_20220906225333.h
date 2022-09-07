/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 22:44:17
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 22:52:59
 */
#ifndef CPU_INSTR_H
#define CPU_INSTR_H

#include "types.h"

static inline uint8_t inb (uint8_t port) {
    // inb al, dx
    __asm__ __volatile__("inb %[p], %[v]" : [v]="a"(rv) : [p]"d"(port));
    return rv;
}

// 关中断
static inline void cli (void) {
    __asm__ __volatile__("cli");
}

// 开中断
static inline void sti (void) {
    __asm__ __volatile__("sti");
}

#endif