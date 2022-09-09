/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-08 10:27:13
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-09 09:11:11
 */
#include "comm/cpu_instr.h"
#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "os_cfg.h"

#define IDT_TABLE_NR            128

void exception_handler_unknown (void);

static gate_desc_t idt_table[IDT_TABLE_NR];

static void do_default_handler (exception_frame_t * frame, const char * message) {
    log_printf("--------------------------------");
    log_printf("IRQ/Exception happend: %s.", message);
    dump_core_regs(frame);
    
    // todo: 留等以后补充打印任务栈的内容

    log_printf("--------------------------------");
    if (frame->cs & 0x3) {
        sys_exit(frame->error_code);
    } else {
        for (;;) {
            hlt();
        }
    }
}

void do_handler_unknown (exception_frame_t * frame) {
	do_default_handler(frame, "Unknown exception.");
}

void do_handler_divider(exception_frame_t * frame) {
	do_default_handler(frame, "Divider Error.");
}

void do_handler_Debug(exception_frame_t * frame) {
	do_default_handler(frame, "Debug Exception");
}

void do_handler_NMI(exception_frame_t * frame) {
	do_default_handler(frame, "NMI Interrupt.");
}

void do_handler_breakpoint(exception_frame_t * frame) {
	do_default_handler(frame, "Breakpoint.");
}

void do_handler_overflow(exception_frame_t * frame) {
	do_default_handler(frame, "Overflow.");
}

void do_handler_bound_range(exception_frame_t * frame) {
	do_default_handler(frame, "BOUND Range Exceeded.");
}

void do_handler_invalid_opcode(exception_frame_t * frame) {
	do_default_handler(frame, "Invalid Opcode.");
}

void do_handler_device_unavailable(exception_frame_t * frame) {
	do_default_handler(frame, "Device Not Available.");
}

void do_handler_double_fault(exception_frame_t * frame) {
	do_default_handler(frame, "Double Fault.");
}

void do_handler_invalid_tss(exception_frame_t * frame) {
	do_default_handler(frame, "Invalid TSS");
}

void do_handler_segment_not_present(exception_frame_t * frame) {
	do_default_handler(frame, "Segment Not Present.");
}

void do_handler_stack_segment_fault(exception_frame_t * frame) {
	do_default_handler(frame, "Stack-Segment Fault.");
}


void irq_init (void) {
    for (uint32_t i = 0; i < IDT_TABLE_NR; i++) {
    	gate_desc_set(idt_table + i, KERNEL_SELECTOR_CS, (uint32_t) exception_handler_unknown,
                  GATE_P_PRESENT | GATE_DPL0 | GATE_TYPE_IDT);
	}

    // 设置异常处理接口
    irq_install(IRQ0_DE, (irq_handler_t)exception_handler_divider);
	irq_install(IRQ1_DB, (irq_handler_t)exception_handler_Debug);
	irq_install(IRQ2_NMI, (irq_handler_t)exception_handler_NMI);
	irq_install(IRQ3_BP, (irq_handler_t)exception_handler_breakpoint);
	irq_install(IRQ4_OF, (irq_handler_t)exception_handler_overflow);
	irq_install(IRQ5_BR, (irq_handler_t)exception_handler_bound_range);
	irq_install(IRQ6_UD, (irq_handler_t)exception_handler_invalid_opcode);
	irq_install(IRQ7_NM, (irq_handler_t)exception_handler_device_unavailable);
	irq_install(IRQ8_DF, (irq_handler_t)exception_handler_double_fault);
	irq_install(IRQ10_TS, (irq_handler_t)exception_handler_invalid_tss);
	irq_install(IRQ11_NP, (irq_handler_t)exception_handler_segment_not_present);
	irq_install(IRQ12_SS, (irq_handler_t)exception_handler_stack_segment_fault);
	irq_install(IRQ13_GP, (irq_handler_t)exception_handler_general_protection);
	irq_install(IRQ14_PF, (irq_handler_t)exception_handler_page_fault);
	irq_install(IRQ16_MF, (irq_handler_t)exception_handler_fpu_error);
	irq_install(IRQ17_AC, (irq_handler_t)exception_handler_alignment_check);
	irq_install(IRQ18_MC, (irq_handler_t)exception_handler_machine_check);
	irq_install(IRQ19_XM, (irq_handler_t)exception_handler_smd_exception);
	irq_install(IRQ20_VE, (irq_handler_t)exception_handler_virtual_exception);
     
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