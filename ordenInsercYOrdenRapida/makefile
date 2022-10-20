all:main

medicionDeTiempos.o: medicionDeTiempos.c medicionDeTiempos.h
	gcc -c medicionDeTiempos.c

generacionNumeros.o: generacionNumeros.c generacionNumeros.h
	gcc -c generacionNumeros.c

algoritmosOrdenacion.o: algoritmosOrdenacion.c algoritmosOrdenacion.h
	gcc -c algoritmosOrdenacion.c

imprimirTablas.o: medicionDeTiempos.o generacionNumeros.o algoritmosOrdenacion.o imprimirTablas.c
	gcc -c imprimirTablas.c -lm

main.o: main.c generacionNumeros.h algoritmosOrdenacion.h imprimirTablas.h
	gcc -c main.c

main: medicionDeTiempos.o generacionNumeros.o algoritmosOrdenacion.o main.o imprimirTablas.o
	gcc -Wall -o p2_ordenacionInsercionYRapida medicionDeTiempos.o generacionNumeros.o algoritmosOrdenacion.o imprimirTablas.o main.o -lm

clean:
	rm -f medicionDeTiempos.o generacionNumeros.o algoritmosOrdenacion.o main.o
