/**
 *
 * 
 */
	.text
	.extern kernel_init
	.global start
_start:
	push %ebp
	mov %esp, %ebp
	mov 0x?(%ebp), %eax
	push %eax
	call kernel_init
	jmp .