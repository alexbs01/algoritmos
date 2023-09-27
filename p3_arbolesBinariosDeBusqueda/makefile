EXECUTABLE = p3_arbolesBinariosDeBusqueda

all:main

tipoArbol.o : tipoArbol.c tipoArbol.h
	gcc -Wall -c tipoArbol.c

funcionesAuxiliares.o: funcionesAuxiliares.h funcionesAuxiliares.c tipoArbol.h
	gcc -Wall -c funcionesAuxiliares.c

main.o: main.c funcionesAuxiliares.h tipoArbol.h
	gcc -Wall -c main.c

main: tipoArbol.o funcionesAuxiliares.o main.o
	gcc -o $(EXECUTABLE) -Wall tipoArbol.o funcionesAuxiliares.o main.o -lm

clean:
	rm -f tipoArbol.o funcionesAuxiliares.o main.o $(EXECUTABLE)
