#include <stdio.h>
#include <string.h>
#include "inc/cpu.h"

// CPU信息表
static info_t ctable[CPU_TABLESIZE];

// 信息名称表
static const char *infos[] = {
    "cpu MHz",
    "cache size",
    "siblings",
    "cpu cores",
    "clflush size",
    "cache alignment",
    "address sizes"
};

/**
 * @brief 读取内存使用情况
 * @param m 内存类型
 * @return msize_t 占用字节(KB) 
 */
info_t read_cpu_info(enum cpu_info m)
{
    __refresh();

    // return mtable[m];
    return 0;
}

/**
 * @brief 刷新CPU资源表
 * @param void
 * @return int 是否执行
 */
static int __refresh()
{
    int i = 0;
    char *c;
    info_t value;
    char buf[64],name[32];
    FILE *fp = fopen("/proc/cpuinfo","r");
    if (fp == NULL)
        return 1;

    while(fgets(buf,sizeof(buf),fp)){
        printf("%s",buf);
    }

    return 0;
}


/**
 * @brief 查看信息表中是否存在该项
 * @param _s 信息名
 * @return int 是否存在
 */
static int __is_exists(const char *_s)
{
    for (int i = 0; i < CPU_TABLESIZE; i++){
        if (!strcmp(_s, infos[i]))
            return 1;
    }
    return 0;
}