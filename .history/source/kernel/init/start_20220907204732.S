/**
 *
 * 
 */
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

	jmp $KERNEL_SELECTOT_CS, $gdt_reload
gdt_reload:

	jmp .