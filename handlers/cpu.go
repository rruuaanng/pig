package handlers

import (
	"net/http"
	"pig/cgo"

	"github.com/gin-gonic/gin"
)

func linuxCpuHandler(ctx *gin.Context){
	v := ctx.Param("args")

	ctx.JSON(http.StatusOK,gin.H{
		v : cgo.Cpu(v),
		"note": "unit: MS",
	})
}