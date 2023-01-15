EXECUTABLE = p3_arbolesBinariosDeBusqueda

all:main

tipoArbol.o : tipoArbol.c tipoArbol.h
	gcc -c tipoArbol.c

funcionesAuxiliares.o: funcionesAuxiliares.h funcionesAuxiliares.c tipoArbol.h
	gcc -c funcionesAuxiliares.c

main.o: main.c funcionesAuxiliares.h tipoArbol.h
	gcc -c main.c

main: tipoArbol.o funcionesAuxiliares.o main.o
	gcc -o $(EXECUTABLE) -Wall tipoArbol.o funcionesAuxiliares.o main.o -lm

clean:
	rm -f tipoArbol.o funcionesAuxiliares.o main.o $(EXECUTABLE)