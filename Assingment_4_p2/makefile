CC = gcc
INC = ./inc
SRC = ./src
LIB = ./lib

all: Lib main run clean 

run:
	./main

main: main.c Lib
	$(CC) main.c -l:gemtek_mathlib.so -o main -I$(INC) -L$(LIB)

Lib: $(SRC)/*.c
	$(CC) -fpic -c $(SRC)/gemtek_mathlib.c
	$(CC) -o $(LIB)/gemtek_mathlib.so gemtek_mathlib.o -shared
	LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH
	export LD_LIBRARY_PATH
	
clean:
	rm -rf *.o  main