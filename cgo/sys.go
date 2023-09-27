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
func Memory(v string) int64 {
	
	// 获取对应内存资源使用情况
	switch v {
	case "memtotal":
		return int64(C.read_mem(C.MEMTOTAL))
	case "memfree":
		return int64(C.read_mem(C.MEMFREE))
	case "memavailable":
		return int64(C.read_mem(C.MEMAVAILABLE))
	case "buffers":
		return int64(C.read_mem(C.BUFFERS))
	case "cached":
		return int64(C.read_mem(C.CACHED))
	case "active":
		return int64(C.read_mem(C.ACTIVE))
	case "inactive":
		return int64(C.read_mem(C.INACTIVE))
	case "mlocked":
		return int64(C.read_mem(C.MLOCKED))
	case "swaptotal":
		return int64(C.read_mem(C.SWAPTOTAL))
	case "swapfree":
		return int64(C.read_mem(C.SWAPFREE))
	case "dirty":
		return int64(C.read_mem(C.DIRTY))
	case "writeback":
		return int64(C.read_mem(C.WRITEBACK))
	case "anonpages":
		return int64(C.read_mem(C.ANONPAGES))
	case "mapped":
		return int64(C.read_mem(C.MAPPED))
	case "shmem":
		return int64(C.read_mem(C.SHMEM))
	case "slab":
		return int64(C.read_mem(C.SLAB))
	}

	return -1
}

func Cpu(v string) {

}
