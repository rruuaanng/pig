package main

import (
	"pig/handlers"
)

func main() {
	handlers.Register()
	
	handlers.Start()
}
