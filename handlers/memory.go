package handlers

import (
	"net/http"
	"pig/cgo"
	"github.com/gin-gonic/gin"
)

// 内存信息响应函数
func linuxMemHandler(ctx *gin.Context) {
	m := ctx.Param("type")
	ctx.JSON(http.StatusOK, gin.H{
		m: cgo.Memory(m),
		"note": "unit: KB(mlocked is n locks)",
	})
}

