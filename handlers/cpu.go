package handlers

import (
	"net/http"
	"pig/cgo"
	"github.com/gin-gonic/gin"
)

// CPU状态响应函数
func linuxCpuHandler(ctx *gin.Context){
	v := ctx.Param("args")

	if v == "all"{
		cpuAll := make(map[string]int64)

		for cpuStat,_ := range cgo.CpuStatMap{
			cpuAll[cpuStat] = cgo.Cpu(cpuStat)
		}
		ctx.JSON(http.StatusOK,gin.H{
			"all": cpuAll,
		})
	} else{
		ctx.JSON(http.StatusOK,gin.H{
			v : cgo.Cpu(v),
			"note": "unit: MS(all core sum)",
		})
	}
}