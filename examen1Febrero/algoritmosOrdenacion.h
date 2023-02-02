/*
 * AUTOR 1: Alejandro Becerra Suárez
 * */

#ifndef ORDENINSERCYORDENRAPIDA_ALGORITMOSORDENACION_H
#define ORDENINSERCYORDENRAPIDA_ALGORITMOSORDENACION_H
#include <stdio.h>
#include <stdbool.h>

#define UMBRAL 100  // 1 10 100

bool isOrd(int array[], int size);  // Comprueba si el array está ordenado o no
void testAleatorio(void (*tipoOrd)(int a[], int v));   // Checkea que funcione correctamente
void testAscendente(void (*tipoOrd)(int a[], int v));
void testDescendente(void (*tipoOrd)(int a[], int v));
void intercambiar(int *a, int *b);  // Intercambia la variable a por la b
void auxord(int v[], int iz, int dr);
void ordenar(int v[], int n);

#endif //ORDENINSERCYORDENRAPIDA_ALGORITMOSORDENACION_H
