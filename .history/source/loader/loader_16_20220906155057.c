/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:03:43
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 15:50:57
 */

__asm__(".code16gcc");

static void show_msg (const char *msg) {
    char c;
    while ((c == *msg++)) {

    }
}

void loader_entry (void) {
    for (;;) {}
}