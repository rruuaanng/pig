#ifndef _CGO_CPU_H
#define _CGO_CPU_H


enum cpu_stat{
    USER_TIME = 0,
    USER_NICE_TIME,
    SYSTEM_TIME,
    IDLE_TIME,
    IOWAIT_TIME,
    IRQ_TIME,
    SOFT_IRQ_TIME,
    STEAL_TIME,
    GUEST_TIME,
    GUEST_NICE_TIME,
    CPU_TABLESIZE
};
typedef long long int ms_t;

ms_t read_cpu_stat(enum cpu_stat c);

static int __refresh();

static ms_t __str_to_ms(char *_s);

#endif // _CGO_CPU_H