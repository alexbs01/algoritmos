EXECUTABLE = p4_monticulos

all:main

monticulo.o : monticulo.c monticulo.h
	gcc -c monticulo.c -g

funcionesAuxiliares.o: funcionesAuxiliares.h funcionesAuxiliares.c monticulo.h
	gcc -c funcionesAuxiliares.c -g

main.o: main.c funcionesAuxiliares.h monticulo.h
	gcc -c main.c -g

main: monticulo.o funcionesAuxiliares.o main.o
	gcc -o $(EXECUTABLE) -Wall monticulo.o funcionesAuxiliares.o main.o -lm -g

clean:
	rm -f monticulo.o funcionesAuxiliares.o main.o $(EXECUTABLE)