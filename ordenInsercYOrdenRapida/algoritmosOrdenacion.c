#include "algoritmosOrdenacion.h"
#include "generacionNumeros.h"

#define UMBRAL 1

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

void test(int array[], int size) {
    int i;

    printf("Array inicial\n");
    for(i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf("\n");

    printf("ordenado? %d", isOrd(array, size));
    printf("\n");

    if(!isOrd(array, size)) {
        printf("ordenando...\n");

        ord_ins(array, size);

        for (i = 0; i < size; i++) {
            printf("%d, ", array[i]);
        }

        isOrd(array, size)? printf("\nEsta ordenado.\n") : printf("\nNo se ordenó.\n");
    }
    printf("\n***************************************************");
}

void ord_ins(int v [], int n) {
    int i, x, j;

    for(i = 1; i <= (n - 1); i++) {
        x = v[i];
        j = i - 1;

        while((j >= 0) && (v[j] > x)) {
            v[j + 1] = v[j];
            j = j - 1;
        }

        v[j + 1] = x;
    }
}

void intercambiar(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenarAux(int V[], int first, int last) {
    int size = last + 1;                            //sizeof(V)/sizeof(V[0]);
    int x, i , j, pivote;

    if(V[first] + UMBRAL <= size) {
        x = rand() % (last - first + 1) + first;
        pivote = V[x];

        intercambiar(&V[first], &V[x]);

        i = V[first] + 1;
        j = V[last];

        while(i <= j) {
            while((i <= V[size]) && (V[i] < pivote)) {
                i++;
            }
            while(V[j] > pivote) {
                j--;
            }
            if(i <= j) {
                intercambiar(&V[i], &V[j]);
                i++;
                j--;
            }
        }

        intercambiar(&V[first], &V[j]);

        ordenarAux(V, first, j - 1);
        ordenarAux(V, j + 1, size - 1);
    }
}

void ordenacionRapida(int V[], int size) {
    ordenarAux(V, 0, size - 1);
    if(UMBRAL > 1) {
        ord_ins(V, size);
    }

}