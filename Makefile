CC=gcc
FLAGS=-Wall -Wextra -pedantic -Ofast -pthread -lrt
BIN=tim-server tim

.PHONY: clean

default: build

wrapper.o: src/wrapper.c
	$(CC) -c src/wrapper.c $(FLAGS)

server.o: src/server.c
	$(CC) -c src/server.c $(FLAGS)

client.o: src/client.c
	$(CC) -c src/client.c $(FLAGS)

build: wrapper.o server.o client.o
	$(CC) wrapper.o server.o -o tim-server $(FLAGS)
	$(CC) wrapper.o client.o -o tim $(FLAGS)
	mkdir -p build/
	mv $(BIN) build/

clean:
	rm -rf build/
	rm -rf *.o
