/**
 *
 * 
 */
	.text
	.extern kernel_init
	.global start
# 从SYS_KERNEL_LOAD_ADDR跳转过来
_start:
	push %ebp
	mov %esp, %ebp
	mov 0x8(%ebp), %eax

	# kernel_init (boot_info)
	push %eax
	call kernel_init
	jmp .