/**
 *
 * 
 */
	.text
	.extern kernel_init
	.global start
_start:
	# 第一种方法
    # push %ebp
    # mov %esp, %ebp
    # mov 0x8(%ebp), %eax
    # push %eax

    # 第二种方法
    # mov 4(%esp), %eax
    # push %eax

    # 第三种方法
    push 4(%esp)
	
	# kernel_init (boot_info)
	push %eax
	call kernel_init
	jmp .