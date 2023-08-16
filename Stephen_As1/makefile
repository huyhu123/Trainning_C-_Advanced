CC = gcc
INC = -I./inc
SRC = ./src/*.c

all: run clean

run: main
	./main

main: main.c $(SRC)
	$(CC) $(INC) main.c $(SRC) -o main

clean:
	rm -rf main