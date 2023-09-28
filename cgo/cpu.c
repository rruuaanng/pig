#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inc/cpu.h"

// CPU使用向量
static ms_t cpu_vector[CPU_TABLESIZE];

/**
 * @brief 读取CPU使用状态
 * @param c CPU状态
 * @return ms_t 占用时间(毫秒)
 */
ms_t read_cpu_stat(cpu_stat c)
{
    __refresh();
    return cpu_vector[c];
}

/**
 * @brief 刷新CPU使用状态
 * @return int 是否执行
 */
static int __refresh()
{
    int i = 0;
    ms_t ms = 0;
    char buf[64];
    FILE *fp = fopen("/proc/stat","r");
    if (!fp)
        return 1;

    // 读取CPU运行状态(所有核心和)
    if (!fgets(buf,sizeof(buf),fp))
        return 1;
    char *state = strtok(buf," ");
    
    while ((state = strtok(NULL," ")) && i < CPU_TABLESIZE){
        ms = __str_to_ms(state);
        cpu_vector[i++] = ms;
    }

    fclose(fp);
    return 0;
}

/**
 * @brief 将字符串数字转换为整数
 * @param s 字符串
 * @return ms_t 占用时间(毫秒)
 */
static ms_t __str_to_ms(char *_s)
{
    char *p;

    ms_t value = strtol(_s, &p, 10); // 10 表示按照十进制转换

    if (*p != '\0' && *p != '\n'){
        return -1;
    }

    return value;
}