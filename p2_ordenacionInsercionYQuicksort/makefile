all:main

medicionDeTiempos.o: medicionDeTiempos.c medicionDeTiempos.h
	gcc -Wall -c medicionDeTiempos.c

algoritmosOrdenacion.o: algoritmosOrdenacion.c algoritmosOrdenacion.h
	gcc -Wall -c algoritmosOrdenacion.c

imprimirTablas.o: medicionDeTiempos.o  algoritmosOrdenacion.o imprimirTablas.c
	gcc -Wall -c imprimirTablas.c -lm

main.o: main.c algoritmosOrdenacion.h imprimirTablas.h
	gcc -Wall -c main.c

main: medicionDeTiempos.o algoritmosOrdenacion.o main.o imprimirTablas.o
	gcc -Wall -o p2_ordenacionInsercionYRapida medicionDeTiempos.o algoritmosOrdenacion.o imprimirTablas.o main.o -lm

clean:
	rm -f medicionDeTiempos.o algoritmosOrdenacion.o main.o
