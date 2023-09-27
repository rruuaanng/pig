#ifndef _CGO_NET_H
#define _CGO_NET_H

enum {
    BYTES = 0,
    PACKETS,
    ERRS,
    DROP,
    NET_TABLESIZE
};

typedef unsigned int net_byte;
typedef long long int byte_t;

struct net_dev{
    char name[16];
    byte_t receive[NET_TABLESIZE];
    byte_t transmit[NET_TABLESIZE];
};

byte_t read_net_byte(net_byte n);

static int __refresh();


#endif // _CGO_NET_H