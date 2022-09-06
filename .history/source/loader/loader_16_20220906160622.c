/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:03:43
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 16:05:22
 */

/*
*asm (汇编语句
*    : 输出操作数（可选）
*    : 输入操作数（可选）
*    : 被破坏的寄存器列表（可选）
*    );
*
*有输入操作数
*char c;
*	asm("mov $3, %[out]":[out]"=r"(c));
*
*有输出操作数
*char c = 'a';
*asm (
*	"mov $0xe, %%ah\n\t"
*	"mov %[ch], %%al\n\t"
*	"int $0x10"::[ch]"r"(c));
*/


__asm__(".code16gcc");

static void show_msg (const char *msg) {
    char c;
    while ((c = *msg++) != '\0') {
        __asm__ __volatile__ (
            "mov $0xe, %%ah\n\t"
            "mov %[ch], %%al\n\t"
            "int $0x10"::[ch]"r"(c)
        );
    }
}

void loader_entry (void) {
    show_msg(".....loading.....\n\r");
    for (;;) {}
}