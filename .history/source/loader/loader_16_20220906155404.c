/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:03:43
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 15:54:04
 */

__asm__(".code16gcc");

static void show_msg (const char *msg) {
    char c;
    while ((c == *msg++)) {
        asm (
            "mov $0xe, %ah\n\t"
            "mov $'L', %al\n\t"
            "int $0x10"
        )
    }
    mov $0xe, %ah
	mov $'L', %al
	int $0x10
}

void loader_entry (void) {
    for (;;) {}
}