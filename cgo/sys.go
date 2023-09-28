package cgo

/*
#include "inc/memory.h"
#include "inc/cpu.h"
#include "inc/device.h"
*/
import "C"

var MemMap = map[string]C.uint{
	"memtotal":     C.MEMTOTAL,
	"memfree":      C.MEMFREE,
	"memavailable": C.MEMAVAILABLE,
	"buffers":      C.BUFFERS,
	"cached":       C.CACHED,
	"active":       C.ACTIVE,
	"inactive":     C.INACTIVE,
	"mlocked":      C.MLOCKED,
	"swaptotal":    C.SWAPTOTAL,
	"swapfree":     C.SWAPFREE,
	"dirty":        C.DIRTY,
	"writeback":    C.WRITEBACK,
	"anonpages":    C.ANONPAGES,
	"mapped":       C.MAPPED,
	"shmem":        C.SHMEM,
	"slab":         C.SLAB,
}

// 读取内存使用情况
func Memory(v string) int64 {
	
	if m, ok := MemMap[v]; ok {
		return int64(C.read_mem(m))
	}

	return -1
}

var CpuStatMap = map[string]C.uint{
	"user_time":      C.USER_TIME,
	"user_nice_time": C.USER_NICE_TIME,
	"system_time":    C.SYSTEM_TIME,
	"idle_time":      C.IDLE_TIME,
	"iowait_time":    C.IOWAIT_TIME,
	"irq_time":       C.IRQ_TIME,
	"soft_irq_time":  C.SOFT_IRQ_TIME,
	"steal_time":     C.STEAL_TIME,
	"guest_time":     C.GUEST_TIME,
	"guest_nice_time": C.GUEST_NICE_TIME,
}

// 读取cpu使用状态
func Cpu(v string) int64{

	// 检查状态是否存在
	if stat, ok := CpuStatMap[v]; ok {
		return int64(C.read_cpu_stat(stat))
	}
	
	return -1
}

func Device(v string) int64{
	C.(1)
	return 0
}