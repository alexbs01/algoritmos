EXECUTABLE = p4_monticulos

all:main

monticulo.o : monticulo.c monticulo.h
	gcc -Wall -c monticulo.c

funcionesAuxiliares.o: funcionesAuxiliares.h funcionesAuxiliares.c monticulo.h
	gcc -Wall -c funcionesAuxiliares.c

main.o: main.c funcionesAuxiliares.h monticulo.h
	gcc -Wall -c main.c

main: monticulo.o funcionesAuxiliares.o main.o
	gcc -o $(EXECUTABLE) -Wall monticulo.o funcionesAuxiliares.o main.o -lm

clean:
	rm -f monticulo.o funcionesAuxiliares.o main.o $(EXECUTABLE)