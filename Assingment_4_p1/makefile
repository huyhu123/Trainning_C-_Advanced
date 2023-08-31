CC = gcc
INC = -I./inc
SRC = ./src/*.c
LIB = -L./lib

all: run clean

run: main
	./main

main: gemtek_mathlib.o gemtek_mahlib.a main.c
	$(CC) main.c -l:gemtek_mahlib.a -o main -I./inc -L./lib

gemtek_mahlib.a: gemtek_mathlib.o
	ar cr ./lib/gemtek_mahlib.a gemtek_mathlib.o
	ranlib ./lib/gemtek_mahlib.a

gemtek_mathlib.o: ./src/gemtek_mathlib.c
	$(CC) -c ./src/gemtek_mathlib.c

clean:
	rm -rf main