/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:27:13
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-08 21:06:42
 */
#include "comm/cpu_instr.h"
#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "os_cfg.h"

#define IDT_TABLE_NR            128

void exception_handler_unknown (void);

static gate_desc_t idt_table[IDT_TABLE_NR];

void do_default_handler (exception_frame_t *frame, const char *message) {
    for (;;) {}
}

// 死机处理函数
void do_handler_unknown (exception_frame_t *frame) {
    do_default_handler(frame, "unkown exception");
}

// 处理除零
void do_handler_divider (exception_frame_t *frame) {
    do_default_handler(frame, "Divider exception");
}

void irq_init (void) {
    for (uint32_t i = 0; i < IDT_TABLE_NR; i++) {
    	gate_desc_set(idt_table + i, KERNEL_SELECTOR_CS, (uint32_t) exception_handler_unknown,
                  GATE_P_PRESENT | GATE_DPL0 | GATE_TYPE_IDT);
	}

    irq_install(IRQ0_DE);
     
    lidt((uint32_t)idt_table, sizeof(idt_table));
}

/**
 * @brief 安装中断或异常处理程序
 */
int irq_install(int irq_num, irq_handler_t handler) {
	if (irq_num >= IDT_TABLE_NR) {
		return -1;
	}

    gate_desc_set(idt_table + irq_num, KERNEL_SELECTOR_CS, (uint32_t) handler,
                  GATE_P_PRESENT | GATE_DPL0 | GATE_TYPE_IDT);
	return 0;
}