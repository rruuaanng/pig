#ifndef _CGO_DEVICE_H
#define _CGO_DEVICE_H


enum {
    SYSTEM_RANDOM = 0,
    USER_RANDOM
};
typedef long long int randn_t;

randn_t read_random_num();


#endif // _CGO_DEVICE_H