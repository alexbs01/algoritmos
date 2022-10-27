EXECUTABLE = p3_arbolesBinariosDeBusqueda

all:main

tipoArbol.o : tipoArbol.c tipoArbol.h
	gcc -c tipoArbol.c -g

funcionesAuxiliares.o: funcionesAuxiliares.h funcionesAuxiliares.c tipoArbol.h
	gcc -c funcionesAuxiliares.c -g

main.o: main.c funcionesAuxiliares.h tipoArbol.h
	gcc -c main.c -g

main: tipoArbol.o funcionesAuxiliares.o main.o
	gcc -o $(EXECUTABLE) tipoArbol.o funcionesAuxiliares.o main.o -lm -g

clean:
	rm -f tipoArbol.o funcionesAuxiliares.o main.o $(EXECUTABLE)