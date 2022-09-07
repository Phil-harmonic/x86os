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
	mov 0x8(%ebp), %eax
	push %eax
	call kernel_init
	jmp .