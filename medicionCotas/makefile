all:main

main.o: main.c
	gcc -c main.c

main: main.o
	gcc -Wall -o cotas main.o -lm

clean:
	rm -f main.o