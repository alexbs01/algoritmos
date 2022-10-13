#ifndef ORDENINSERCYORDENRAPIDA_ALGORITMOSORDENACION_H
#define ORDENINSERCYORDENRAPIDA_ALGORITMOSORDENACION_H
#include <stdio.h>
#include <stdbool.h>

bool isOrd(int array[], int size);  // Comprueba si el array está ordenado o no
void test(int array[], int size);   // Checkea que funcione correctamente
void ord_ins(int v[], int n);       // Algoritmo de ordenación por inserción
void intercambiar(int *a, int *b);
void ordenarAux (int V[], int first, int last);
void ordenacionRapida(int V[], int size);


#endif //ORDENINSERCYORDENRAPIDA_ALGORITMOSORDENACION_H