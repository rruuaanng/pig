#include <stdio.h>
#include <string.h>
#include "inc/memory.h"

// 内存资源表
static msize_t mtable[MEM_TABLESIZE];

// 资源名称表
static const char *resources[] = {
    "MemTotal",
    "MemFree",
    "MemAvailable",
    "Buffers",
    "Cached",
    "Active",
    "Inactive",
    "Mlocked",
    "SwapTotal",
    "SwapFree",
    "Dirty",
    "Writeback",
    "AnonPages",
    "Mapped",
    "Shmem",
    "Slab"
};

/**
 * @brief 读取内存使用情况
 * @param m 内存类型
 * @return msize_t 占用字节(KB) 
 */
msize_t read_mem(mem_type m)
{
    __refresh();
    return mtable[m];
}

/**
 * @brief 刷新内存资源表
 * @param void
 * @return int 是否执行
 */
static int __refresh()
{
    int i = 0;
    char *c;
    msize_t value;
    char buf[64],name[32];
    FILE *fp = fopen("/proc/meminfo","r");
    if (fp == NULL)
        return 1;
    
    // 解析/proc/meminfo
    while (i < MEM_TABLESIZE && fgets(buf, sizeof(buf), fp)) {
        sscanf(buf, "%s %lld", name, &value);
        // 去掉字符串中的冒号
        if (c = strchr(name, ':'))
            *c = '\0';
        if (__is_exists(name))
            mtable[i++] = value;
    }
    
    fclose(fp);
    return 0;
}

/**
 * @brief 查看资源表中是否存在该项
 * @param _s 资源名
 * @return int 是否存在
 */
static int __is_exists(const char *_s)
{
    for (int i = 0; i < MEM_TABLESIZE; i++){
        if (!strcmp(_s, resources[i]))
            return 1;
    }
    return 0;
}
