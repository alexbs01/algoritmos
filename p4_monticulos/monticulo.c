/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "monticulo.h"

void crear_monticulo(int array[], int size, monticulo *M) {
    int i;

    for(i = 0; i <= size - 1; i++){
        M->vector[i] = array[i];
    }

    M->ultimo = size - 1;

    for(i = M->ultimo / 2; i >= 0; i--){
        hundir(M, i);
    }
}

void hundir(monticulo *M, int n) {
    int j = -1, hijoizq, hijoder;

    while(j != n) {
        hijoizq = 2 * n + 1;
        hijoder = 2 * n + 2;
        j = n;

        if((hijoder <= M->ultimo) && (M->vector[hijoder] > M->vector[n])) {
            n = hijoder;
        }

        if((hijoizq <= M->ultimo) && (M->vector[hijoizq] > M->vector[n])) {
            n = hijoizq;
        }

        intercambiar(&M->vector[j], &M->vector[n]);
    }
}

void intercambiar(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

bool monticulo_vacio(monticulo M){
    return (M.ultimo == -1);
}

int eliminar_mayor(monticulo *M) {
    int x;

    if(M->ultimo == -1) {
        printf("Error: montículo vacío");
        return -1;

    } else {
        x = M->vector[0];
        M->vector[0] = M->vector[M->ultimo];
        M->ultimo = M->ultimo - 1; // [2 7 3 1 5] 2

        if(M->ultimo > -1) {
            hundir(M, 0);
        }

        return x;
    }
}

void inicializarMonticulo(monticulo* M) {
    M->ultimo = -1;
}

void ord_monticulo(int array[], int n) {
    int i;
    monticulo M;

    inicializarMonticulo(&M);
    crear_monticulo(array, n, &M);

    for(i = n-1; i >= 0; i--){
        array[i] = eliminar_mayor(&M);
    }
}