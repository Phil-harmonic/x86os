/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:27:13
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-08 10:28:50
 */
#include "cpu/irq.h"

#define IDE_TABLE_NR            128

static gate_desc_t idt_table[];

void irq_init(void) {

}