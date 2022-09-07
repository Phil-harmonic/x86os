/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-06 21:38:26
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 10:42:42
 */
#ifndef BOOT_INFO_H
#define BOOT_INFO_H

#include "types.h"

#define BOOT_RAM_REGION_MAX	10		// RAM区最大数量
#define SECTOR_SIZE 512

/**
 * 启动信息参数
 */
typedef struct _boot_info_t {
    // RAM区信息
    struct {
        uint32_t start;
        uint32_t size;
    }ram_region_cfg[BOOT_RAM_REGION_MAX];
    int ram_region_count;
}boot_info_t;

#endif