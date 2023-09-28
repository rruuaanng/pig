#include <stdio.h>
#include "inc/random.h"



randn_t read_random_num()
{
    // 打开 /dev/random 设备文件
    FILE *fp = fopen("/dev/random", "rb");
    
    if (!fp) {
        perror("无法打开 /dev/random");
        return 1;
    }

    unsigned char buffer[16];  // 用于存储随机数的缓冲区

    // 使用 fread 从 /dev/random 中读取随机数
    size_t bytesRead = fread(buffer, 1, sizeof(buffer), randomFile);

    if (bytesRead != sizeof(buffer)) {
        perror("读取 /dev/random 时发生错误");
        fclose(randomFile);
        return 1;
    }

    // 打印读取到的随机数
    printf("随机数：");

    for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%d ", buffer[i]);
    }

    printf("\n");

    // 关闭设备文件
    fclose(randomFile);

    return 0;
}