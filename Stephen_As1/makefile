run: main.o matrix.o
	gcc -o run -I./inc ./src/maxtrix.c main.c

main.o: main.c ./src/maxtrix.c
	gcc -c main.c ./src/maxtrix.c

maxtrix.o: ./src/maxtrix.c
	gcc -c -I./inc ./src/maxtrix.c