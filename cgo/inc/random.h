#ifndef _CGO_DEVICE_H
#define _CGO_DEVICE_H


enum {
    SYSTEM_RANDOM = 0,
    USER_RANDOM
};
typedef unsigned int rand_type;


int read_random_num(rand_type r, int lim);


#endif // _CGO_DEVICE_H