GO := go

BIN := pig.exe

all:
	make build

build:
	$(GO) build -o $(BIN)

clean:
	rm -rf $(BIN)
