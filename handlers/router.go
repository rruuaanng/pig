package handlers

import "github.com/gin-gonic/gin"

// 全局路由
var router *gin.Engine

// 注册路由
func Register() {
	router = gin.Default()
	// memory
	router.GET("/api/memory/:type", linuxMemHandler)
	// cpu
}

// 启动服务
func Start(port ...string) {
	if len(port) == 0 {
		router.Run(":8080")
	}
	router.Run(port[0])
}
