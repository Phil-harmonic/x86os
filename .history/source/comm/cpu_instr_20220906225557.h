/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 22:44:17
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 22:55:57
 */
#ifndef CPU_INSTR_H
#define CPU_INSTR_H

#include "types.h"

static inline uint8_t inb (uint16_t port) {
    // inb al, dx
    __asm__ __volatile__("inb %[p], %[v]" : [v]="a"(rv) : [p]"d"(port));
    return rv;
}

static inline void outb (uint16_t port, uint8_t data) {
    // outb al, dx
    __asm__ __volatile__("outb %[v], %[p]" :: [p]"d"(port), [v]"a"(data));
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