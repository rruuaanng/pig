#ifndef _CGO_MEMORY_H
#define _CGO_MEMORY_H


enum mem_type{
    MEMTOTAL = 0,
    MEMFREE,
    MEMAVAILABLE,
    BUFFERS,
    CACHED,
    ACTIVE,
    INACTIVE,
    MLOCKED,
    SWAPTOTAL,
    SWAPFREE,
    DIRTY,
    WRITEBACK,
    ANONPAGES,
    MAPPED,
    SHMEM,
    SLAB,
    MEM_TABLESIZE
};
typedef long long int msize_t;

msize_t read_mem(enum mem_type m);

static int __refresh();

static int __is_exists(const char *_s);

#endif // _CGO_MEMORY_H