#ifndef _CGO_CPU_H
#define _CGO_CPU_H


enum cpu_info{
    VENDOR_ID = 0,
    CPU_MHZ,
    CACHE_SIZE,
    SIBLINGS,
    CPU_CORES,
    CLFLUSH_SIZE,
    CACHE_ALIGNMENT,
    ADDRESS_SIZES,
    CPU_TABLESIZE
};
typedef const char* info_t;

info_t read_cpu_info(enum cpu_info m);

static int __refresh();

static int __is_exists(const char *_s);


#endif // _CGO_CPU_H