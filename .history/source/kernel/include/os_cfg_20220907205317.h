/*
 * @Descripttion: 
 * @version: 
 * @@Company: personal
 * @Author: Liang Chen
 * @Date: 2022-09-07 19:41:37
 * @LastEditors: Liang Chen
 * @LastEditTime: 2022-09-07 20:53:17
 */
#ifndef OS_CFG_H
#define OS_CFG_H

#define GDT_TABLE_SIZE 256

#define KERNEL_SELECTOT_CS (1 * 8)
#define KERNEL_SELECTOT_DS (2 * 8)

#define KERNEL_STACK_SIZE  (8 * 1024)

#endif