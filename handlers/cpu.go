package handlers

import (
	"fmt"

	"github.com/gin-gonic/gin"
)

// CPU信息响应函数
func linuxCpuHandler(ctx *gin.Context) {
	v := ctx.Param("args")
	fmt.Printf("c: %v\n", v)
}
