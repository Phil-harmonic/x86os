/**
 *
 * 
 */
	.text
	.extern kernel_init
	.global start
_start:
	call kernel_init
	jmp .