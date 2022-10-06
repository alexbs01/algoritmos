#include "algoritmosOrdenacion.h"

/*
procedimiento ordenacionPorInsercion (var v[1..n])
    para i := 2 hasta n hacer
        x := v[i] ;
        j := i-1 ;
        mientras j > 0 y v[j] > x hacer
            v[j+1] := v[j] ;
            j := j-1
        fin mientras ;
        v[j+1] := x
    fin para
fin procedimiento
 */

int arraySize(int array[]) {
    return (sizeof(&array) / sizeof(array[0]));
}

bool isOrd(int array[]) {
    int j = 1;
    int i;
    int tam = arraySize(array);

    for (i = 0; j < tam; i++) {
        if (array[i] > array[j]) {
            return false;
        }
        j++;
    }
    return true;
}

void test(int array[]) {
    int i;
    int size = arraySize(array);

    printf("Ordenacion por insercion con inicializacion aleatoria\n");
    for(i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf("\n");

    printf("ordenado? %d", isOrd(array));
    printf("\n");

    if(!isOrd(array)) {
        printf("ordenando...\n");

        ord_ins(array, size);

        for(i = 0; i < size; i++) {
            printf("%d, ", array[i]);
        }
        if(isOrd(array)) {
            printf("Esta ordenado.");
        } else {
            printf("No se ordenó.");
        }
    }
}

void ord_ins(int v [], int n) {

    int i, x, j;

    for (i = 1; i <= (n - 1); i++) {
        x = v[i];
        j = i - 1;

        while((j >= 0) && (v[j] > x)) {
            v[j+1] = v[j];
            j = j-1;
        }

        v[j+1] = x;
    }
}
