CC=gcc
FLAGS=-Wall -Wextra -pedantic -Ofast -lpthread
BIN=tim-server tim

.PHONY: clean

default: build

wrapper: src/wrapper.c
	$(CC) -c src/wrapper.c $(FLAGS)

server: src/server.c
	$(CC) -c src/server.c $(FLAGS)

client: src/client.c
	$(CC) -c src/client.c $(FLAGS)

build: wrapper.o server.o client.o
	$(CC) wrapper.o server.o -o tim-server $(FLAGS)
	$(CC) wrapper.o client.o -o tim $(FLAGS)
	mkdir -p build/
	mv $(BIN) build/
	rm -rf *.o

clean:
	rm -rf build/
