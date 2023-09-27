package handlers

import (
	"net/http"
	"pig/cgo"

	"github.com/gin-gonic/gin"
)

// 内存信息响应函数
func linuxMemHandler(ctx *gin.Context) {
	v := ctx.Param("args")

	if v == "all"{
		memAll := make(map[string]int64)

		for mem,_ := range cgo.MemMap{
			memAll[mem] = cgo.Memory(mem)
		}
		ctx.JSON(http.StatusOK,gin.H{
			"all": memAll,
		})
	}else{
		ctx.JSON(http.StatusOK, gin.H{
			v:      cgo.Memory(v),
			"note": "unit: KB(mlocked is n locks)",
		})
	}
}
