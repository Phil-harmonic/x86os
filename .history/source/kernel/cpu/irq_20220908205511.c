/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:27:13
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-08 20:54:25
 */
#include "comm/cpu_instr.h"
#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "os_cfg.h"

#define IDT_TABLE_NR            128

void exception_handler_unknown (void);

static gate_desc_t idt_table[IDT_TABLE_NR];

void do_default_handler(exception_frame *frame, const char *message) {
    for (;;) {}
}

// 死机处理函数
void do_handler_unknown(exception_frame *frame) {
    do_default_handler(frame, "unkown exception");
}

// 处理除零
void do_handler_divider(exception_frame *frame) {
    do_default_handler(frame, "Divider exception");
}

void irq_init(void) {
    for (uint32_t i = 0; i < IDT_TABLE_NR; i++) {
    	gate_desc_set(idt_table + i, KERNEL_SELECTOR_CS, (uint32_t) exception_handler_unknown,
                  GATE_P_PRESENT | GATE_DPL0 | GATE_TYPE_IDT);
	}
     
    lidt((uint32_t)idt_table, sizeof(idt_table));
}