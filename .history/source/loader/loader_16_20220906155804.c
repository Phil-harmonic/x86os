/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:03:43
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 15:58:04
 */

/*
*asm (汇编语句
*    : 输出操作数（可选）
*    : 输入操作数（可选）
*    : 被破坏的寄存器列表（可选）
*    );
*/


__asm__(".code16gcc");

static void show_msg (const char *msg) {
    char c;
    while ((c == *msg++)) {
        asm (
            "mov $0xe, %%ah\n\t"
            "mov %[ch], %%al\n\t"
            "int $0x10"::[ch]"r"(c)
        );
    }
}

void loader_entry (void) {
    for (;;) {}
}