#ifndef _CGO_MEMORY_H
#define _CGO_MEMORY_H

enum mem_type{
    MemTotal = 0,
    MemFree,
    MemAvailable,
    Buffers,
    Cached,
    Active,
    Inactive,
    Mlocked,
    SwapTotal,
    SwapFree,
    Dirty,
    Writeback,
    AnonPages,
    Mapped,
    Shmem,
    Slab,
	MTableSize
};
typedef long long int msize_t;

msize_t read_mem(enum mem_type m);

static int __refresh();

static int __is_exists(const char *_s);

#endif // _CGO_MEMORY_H