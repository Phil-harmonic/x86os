/**
 *
 * 
 */
	.text
	.extern kernel_init
	.global start

# 从SYS_KERNEL_LOAD_ADDR跳转过来
# SYS_KERNEL_LOAD_ADDR (1024 * 1024)
_start:
	push %ebp
	mov %esp, %ebp
	mov 0x8(%ebp), %eax

	mov 4(%esp), %eax

	# kernel_init (boot_info)
	push %eax
	call kernel_init
	jmp .