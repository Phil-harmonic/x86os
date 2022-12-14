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


	.text
	.global exception_handler_unknown
exception_handler_unknown:
	iret