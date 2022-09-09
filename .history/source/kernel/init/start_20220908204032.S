/**
 *
 * 
 */
 #include "os_cfg.h"
	.text
	.extern kernel_init
	.global _start
	.extern init_main
_start:
	push %ebp
	mov %esp, %ebp
	mov 0x8(%ebp), %eax
	# kernel_init (boot_info)
	push %eax
	call kernel_init

	jmp $KERNEL_SELECTOR_CS, $gdt_reload
gdt_reload:
	mov $KERNEL_SELECTOR_DS, %ax
	mov %ax, %ds
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

	mov $(stack + KERNEL_STACK_SIZE), %esp
	jmp init_main

	.bss
.comm stack, KERNEL_STACK_SIZE


.macro exception_handler name num with_err_code
	.text
	.extern do_handler_\name
	.global exception_handler_\name
exception_handler_\name:
	// 保存寄存器
	.if \with_err_code == 0
		push $0
	.endif

	push $\num
	pushal
	push %ds
	push %es
	push %fs
	push %gs

	push %esp

	call do_handler_\name

	add $(1 * 4), %esp

	pop %gs
	pop %fs
	pop %es
	pop %ds
	popal

	add $(2*4), %esp
	iret
.endm

exception_handler unknown, -1, 0