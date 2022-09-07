/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 22:44:17
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 09:08:10
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

static inline void lgdt (uint32_t start, uint32_t size) {
    __asm__ __volatile__("lgdt %[g]"::[g]"m"(gdt));
}

#endif

/*
*asm (汇编语句
*    : 输出操作数（可选）
*    : 输入操作数（可选）
*    : 被破坏的寄存器列表（可选）
*    );
*
*有输入操作数
*char c;
*	asm("mov $3, %[out]":[out]"=r"(c));
*
*有输出操作数
*char c = 'a';
*asm (
*	"mov $0xe, %%ah\n\t"
*	"mov %[ch], %%al\n\t"
*	"int $0x10"::[ch]"r"(c));
*/