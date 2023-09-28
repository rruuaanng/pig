#ifndef _CGO_DEVICE_H
#define _CGO_DEVICE_H


enum {
    CHARACTER_DEVICES = 0,
    BLOCK_DEVICES
};
typedef char* dev_name;

dev_name read_dev_info();

static int __refresh();


#endif // _CGO_DEVICE_H