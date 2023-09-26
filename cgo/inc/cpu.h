#ifndef _CGO_CPU_H
#define _CGO_CPU_H


enum cpu_info{
    a = 1
};


int read_cpu(enum cpu_info m);

static int __refresh();

static int __is_exists(const char *_s);


#endif // _CGO_CPU_H