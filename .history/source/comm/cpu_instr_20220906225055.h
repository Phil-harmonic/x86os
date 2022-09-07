/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 22:44:17
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 22:50:55
 */
#ifndef CPU_INSTR_H
#define CPU_INSTR_H

// 关中断
static inline void cli (void) {
    __asm__ __volatile__("cli");
}

// 开中断
static inline void sti (void) {
    __asm__ __volatile__("sti");
}

#endif