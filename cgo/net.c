#include <stdio.h>
#include "inc/net.h"


// 读取网络已交换字节数
byte_t read_net_byte(net_byte n)
{
    __refresh();
    return 0;
}

// 刷新网络字节表
static int __refresh()
{
    int i = 0;
    char buf[64];
    FILE *fp = fopen("/proc/net/dev","r");

    fgets(buf,sizeof(buf),fp);

    return 0;
}