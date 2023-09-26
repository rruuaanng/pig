package cgo

/*
#include "inc/memory.h"
#include "inc/cpu.h"
*/
import "C"

// 内存类型

const (
    MemTotal int = iota
    MemFree
    MemAvailable
    Buffers
    Cached
    Active
    Inactive
	Mlocked
    SwapTotal
    SwapFree
    Dirty
    Writeback
    AnonPages
    Mapped
    Shmem
    Slab
)

// 读取内存使用情况
func Memory(m string) int64 {
	C.refresh()
	// 若未指定内存类型
	if len(m) == 0 {
		return -1
	}

	// 获取对应内存资源使用情况
	switch m {
	case "memtotal":
		return int64(C.read_mem(C.MemTotal))
	case "memfree":
		return int64(C.read_mem(C.MemFree))
	case "memavailable":
		return int64(C.read_mem(C.MemAvailable))
	case "buffers":
		return int64(C.read_mem(C.Buffers))
	case "cached":
		return int64(C.read_mem(C.Cached))
	case "active":
		return int64(C.read_mem(C.Active))
	case "inactive":
		return int64(C.read_mem(C.Inactive))
	case "mlocked":
		return int64(C.read_mem(C.Mlocked))
	case "swaptotal":
		return int64(C.read_mem(C.SwapTotal))
	case "swapfree":
		return int64(C.read_mem(C.SwapFree))
	case "dirty":
		return int64(C.read_mem(C.Dirty))
	case "writeback":
		return int64(C.read_mem(C.Writeback))
	case "anonpages":
		return int64(C.read_mem(C.AnonPages))
	case "mapped":
		return int64(C.read_mem(C.Mapped))
	case "shmem":
		return int64(C.read_mem(C.Shmem))
	case "slab":
		return int64(C.read_mem(C.Slab))
	}
	

	return -1
}
