all:main

funcionesFibonacci.o: funcionesFibonacci.c funcionesFibonacci.h
	gcc -Wall -c funcionesFibonacci.c

main.o: main.c funcionesFibonacci.h
	gcc -Wall -c main.c

main: funcionesFibonacci.o main.o
	gcc -Wall  -o p1_fibonacci funcionesFibonacci.o main.o -lm

clean:
	rm -f main.o funcionesFibonacci.o p1_fibonacci
