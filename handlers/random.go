package handlers

import (
	"net/http"
	"pig/cgo"
	"strconv"
	"github.com/gin-gonic/gin"
)

// 随机数响应函数
func linuxRandomHandler(ctx *gin.Context){
	v1 := ctx.Param("type")
	v2,_ := strconv.Atoi(ctx.Param("lim"))
	ctx.JSON(http.StatusOK,gin.H{
		"number": cgo.Random(v1,v2),
	})
}