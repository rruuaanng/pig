#include <stdio.h>
#include <stdlib.h>
#include "inc/random.h"


/**
 * @brief 读取(硬件或系统)的随机数
 * @param r 随机数生成类型
 * @param lim 范围在[-n,n]以内
 * @return int 随机数
 */
int read_random_num(rand_type r, int lim) {
    int value;
    FILE *fp;

    switch (r){
    case SYSTEM_RANDOM:
        fp = fopen("/dev/random", "rb");
        break;
    case USER_RANDOM:
        fp = fopen("/dev/urandom", "rb");
        break;
    default: 
        return 1;
    }
    
    if (!fp) 
        return 1; // 返回负数表示失败

    if (!fread(&value, sizeof(int), 1, fp)) {
        fclose(fp);
        return 1; // 返回负数表示失败
    }

    fclose(fp);
    return value % lim; 
}
