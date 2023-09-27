#ifndef _CGO_NET_H
#define _CGO_NET_H


typedef unsigned int net_byte;
typedef long long int byte_t;

byte_t read_net_byte(net_byte n);

static int __refresh();


#endif // _CGO_NET_H