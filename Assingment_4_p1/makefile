CC = gcc
INC = ./inc
SRC = ./src
LIB = ./lib

all: run clean

run: main
	./main

main: gemtek_mathlib.o gemtek_mahlib.a main.c
	$(CC) main.c -l:gemtek_mahlib.a -o main -I$(INC) -L$(LIB) -lm

gemtek_mahlib.a: gemtek_mathlib.o
	ar cr $(LIB)/gemtek_mahlib.a gemtek_mathlib.o
	ranlib $(LIB)/gemtek_mahlib.a

gemtek_mathlib.o: $(SRC)/gemtek_mathlib.c
	$(CC) -c $(SRC)/gemtek_mathlib.c

clean:
	rm -rf main *.o