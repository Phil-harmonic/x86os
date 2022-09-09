/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:25:56
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-08 21:07:00
 */
#ifndef IRQ_H
#define IRQ_H

typedef struct _exception_frame_t {
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t eip, cs, eflags;
} exception_frame_t;

typedef void (*irq_handler_t) (exception_frame_t *frame);

void irq_init(void);
void do_handler_divider(void);

#endif