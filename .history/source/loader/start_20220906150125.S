/**
 *
 * 系统引导部分，启动时由硬件加载运行，然后完成对二级引导程序loader的加载
 * 该部分程序存储于磁盘的第1个扇区，在计算机启动时将会由BIOS加载到0x7c00处
 * 之后，将由BIOS跳转至0x7c00处开始运行
 * 
 */
	#include "boot.h"

  	// 16位代码, 务必加上
  	.code16
 	.text
	.global _start
	.extern boot_entry
_start:
	mov $0, %ax
	mov %ax, %ds
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

	mov $_start, %esp
	// BIOS int 10 show charactors
	mov $0xe, %ah
	mov $'L', %al
	int $0x10

read_loader:
	/**
	* 从磁盘的扇区1读取指定大小的指令到内存的0x8000处
	* BIOS提供了磁盘操作的服务中断, 其具体使用方法如下：
	* ● AH=02H
	* ● AL=扇区数
	* ● CH=柱面 cx = ch: cl
	* ● CL=扇区
	* ● DH=磁头
	* ● DL=驱动器, 00H~7FH:软盘, 80H~0FFH:硬盘
	* ● ES:BX=缓冲区的地址
	* ● 出口参数:CF=0——操作成功, AH=00H, AL=传输的扇区数, 否则, AH=状态代码, 
	  参见功能号01H中的说明。CF标志见EFLAS寄存器中的CF位。
	**/
	mov $0x8000, %bx
	mov $0x2, %ah
	mov $0x2, %cx
	mov $64, %al
	mov $0x0080, %dx
	int $0x13
	jc read_loader

	jmp boot_entry

	jmp .
	
	// 引导结束段
	.section boot_end, "ax"
boot_sig: .byte 0x55, 0xaa
