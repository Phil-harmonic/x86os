/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 16:37:38
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-06 19:49:42
 */
#ifndef BOOT_INFO_H
#define BOTT_INFO_H

#include "types.h"

#define BOOT_RAM_REGION_MAX 10

typedef struct _boot_info_t {
    struct {
        uint32_t start;
        uint32_t size;
    } ram_region_cfg[BOOT_RAM_REGION_MAX];

    int ram_region_count;

} boot_info_t;

#endif