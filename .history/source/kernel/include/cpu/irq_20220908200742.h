/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:25:56
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-08 20:07:10
 */
#ifndef IRQ_H
#define IRQ_H

typedef struct _exception_frame_t {
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx;
} exception_frame;

void irq_init(void);

#endif