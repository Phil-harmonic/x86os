/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:27:13
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-08 10:30:36
 */
#include "cpu/irq.h"
#include "cpu/cpu.h"

#define IDE_TABLE_NR            128

static gate_desc_t idt_table[IDE_TABLE_NR];

void irq_init(void) {
    for (int i = 0; i < IDE_TABLE_NR; i++) {
        gate_desc_set(idt_table + i, 0, 0, 0);
    }
}