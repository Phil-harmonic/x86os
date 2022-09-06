/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 15:03:43
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 19:42:37
 */

#include "loader.h"

__asm__(".code16gcc");

static boot_info_t boot_info;

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

static void detect_memory (void) {
    uint32_t contID = 0;
    uint32_t signature, bytes;
    SMAP_entry_t smap_entry;

    show_msg("try to detect memory");

    boot_info.ram_region_count = 0;
    for (int i = 0; i < BOOT_RAM_REGION_MAX; i++) {
        SMAP_entry_t *entry = &smap_entry;
        __asm__ __volatile__ (
            "int $0x15"
            : "=a"(signature), "=c"(bytes), "=b"(contID)
			: "a"(0xE820), "b"(contID), "c"(24), "d"(0x534D4150), "D"(entry));
        if (signature != 0x534D4150) {
            show_msg("failed\r\n");
            return;
        }
        if (bytes > 20 && (entry->ACPI & 0x0001) == 0) {
			continue;
		}
        if (entry->Type == 1) {
            boot_info.ram_region_cfg[boot_info.ram_region_count].start = entry->BaseL;
            boot_info.ram_region_cfg[boot_info.ram_region_count].size = entry->LengthL;
            boot_info.ram_region_count++;
        }
        if (contId == 0) {
            break;
        }
    }
    show_msg("ok.\r\n");
}

void loader_entry (void) {
    show_msg(".....loading.....\n\r");
    for (;;) {}
}

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