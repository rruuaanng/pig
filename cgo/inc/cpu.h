#ifndef _CGO_CPU_H
#define _CGO_CPU_H


enum cpu_stat{
    USER_TIME,
    USER_NICE_TIME,
    KERNEL_TIME,
    IDLE_TIME,
    IOWAIT_TIME,
    IRQ_TIME,
    SOFT_IRQ_TIME,
    STEAL_TIME,
    GUEST_TIME,
    GUEST_NICE_TIME
};
typedef long long int ms_t;



#endif // _CGO_CPU_H