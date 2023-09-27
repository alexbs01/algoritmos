/*
 * AUTOR 1: Alejandro Becerra Suárez
 * */

#include "algoritmosOrdenacion.h"
#include "medicionDeTiempos.h"

   //1 10 100

bool isOrd(int array[], int size) {
    int j = 1, i;

    for (i = 0; j < size; i++) {
        if (array[i] > array[j]) {
            return false;
        }
        j++;
    }
    return true;
}

void testAleatorio(void (*tipoOrd)(int a[], int v)) {
    int i, size = 20, array[size];
    aleatorio(array, 20);

    printf("Array inicial:\n");
    for(i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf("\nOrdenado? %d\n", isOrd(array, size));

    if(!isOrd(array, size)) {
        tipoOrd(array, size);

        for (i = 0; i < size; i++) {
            printf("%d, ", array[i]);
        }

        if(isOrd(array, size)) {
            printf("\nEsta ordenado.\n");
        } else {
            printf("\nNo se ordenó.\n");
        }
    }
    printf("\n*********************************************\n");
}

void testAscendente(void (*tipoOrd)(int a[], int v)) {
    int i, size = 20, array[size];
    ascendente(array, 20);

    printf("Array inicial:\n");
    for(i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf("\nOrdenado? %d\n", isOrd(array, size));

    if(!isOrd(array, size)) {
        tipoOrd(array, size);

        for (i = 0; i < size; i++) {
            printf("%d, ", array[i]);
        }

        if(isOrd(array, size)) {
            printf("\nEsta ordenado.\n");
        } else {
            printf("\nNo se ordenó.\n");
        }
    }
    printf("\n*********************************************\n");
}

void testDescendente(void (*tipoOrd)(int a[], int v)) {
    int i, size = 20, array[size];
    descendente(array, 20);

    printf("Array inicial:\n");
    for(i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf("\nOrdenado? %d\n", isOrd(array, size));

    if(!isOrd(array, size)) {
        tipoOrd(array, size);

        for (i = 0; i < size; i++) {
            printf("%d, ", array[i]);
        }

        if(isOrd(array, size)) {
            printf("\nEsta ordenado.\n");
        } else {
            printf("\nNo se ordenó.\n");
        }
    }
    printf("\n*********************************************\n");
}

void intercambiar(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/********************************/

void ordenar(int v[], int n) {
    int i, k, j;

    for(i = n - 1; i >= 1; i--) {
        k = i;
        for(j = i - 1; j >= 0; j--) {
            if(v[k] < v[j]) {
                k = j;
            }
        }
        intercambiar(&v[k], &v[i]);
    }
}