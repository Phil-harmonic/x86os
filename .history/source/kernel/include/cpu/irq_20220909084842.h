/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:25:56
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-09 08:48:42
 */
#ifndef IRQ_H
#define IRQ_H

#include "comm/types.h"

// 中断号码
#define IRQ0_DE             0
#define IRQ1_DB             1
#define IRQ2_NMI            2
#define IRQ3_BP             3
#define IRQ4_OF             4
#define IRQ5_BR             5
#define IRQ6_UD             6
#define IRQ7_NM             7
#define IRQ8_DF             8
#define IRQ10_TS            10
#define IRQ11_NP            11
#define IRQ12_SS            12
#define IRQ13_GP            13
#define IRQ14_PF            14
#define IRQ16_MF            16
#define IRQ17_AC            17
#define IRQ18_MC            18
#define IRQ19_XM            19
#define IRQ20_VE            20

#define IRQ0_TIMER          0x20
#define IRQ1_KEYBOARD		0x21				// 按键中断
#define IRQ14_HARDDISK_PRIMARY		0x2E		// 主总线上的ATA磁盘中断

#define ERR_PAGE_P          (1 << 0)
#define ERR_PAGE_WR          (1 << 1)
#define ERR_PAGE_US          (1 << 1)

#define ERR_EXT             (1 << 0)
#define ERR_IDT             (1 << 1)


typedef struct _exception_frame_t {
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t eip, cs, eflags;
} exception_frame_t;

typedef void (*irq_handler_t) (exception_frame_t *frame);

void irq_init(void);
void do_handler_divider(exception_frame_t *frame);
int irq_install(int irq_num, irq_handler_t handler);

#endif