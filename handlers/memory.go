package handlers

import (
	"net/http"
	"pig/cgo"

	"github.com/gin-gonic/gin"
)

// 内存信息响应函数
func linuxMemHandler(ctx *gin.Context) {
	v := ctx.Param("args")
	ctx.JSON(http.StatusOK, gin.H{
		v:      cgo.Memory(v),
		"note": "unit: KB(mlocked is n locks)",
	})
}
