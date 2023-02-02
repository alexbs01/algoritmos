all:main

medicionDeTiempos.o: medicionDeTiempos.c medicionDeTiempos.h
	gcc -c medicionDeTiempos.c

algoritmosOrdenacion.o: algoritmosOrdenacion.c algoritmosOrdenacion.h
	gcc -c algoritmosOrdenacion.c

imprimirTablas.o: medicionDeTiempos.o  algoritmosOrdenacion.o imprimirTablas.c
	gcc -c imprimirTablas.c -lm

main.o: main.c algoritmosOrdenacion.h imprimirTablas.h
	gcc -c main.c

main: medicionDeTiempos.o algoritmosOrdenacion.o main.o imprimirTablas.o
	gcc -Wall -o examen1Febrero medicionDeTiempos.o algoritmosOrdenacion.o imprimirTablas.o main.o -lm

clean:
	rm -f medicionDeTiempos.o algoritmosOrdenacion.o main.o imprimirTablas.o examen1Febrero
