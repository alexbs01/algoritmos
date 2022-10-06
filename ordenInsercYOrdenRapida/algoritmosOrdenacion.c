#include "algoritmosOrdenacion.h"

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

    printf("Ordenacion por insercion con inicializacion aleatoria\n");
    for(i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf("\n");

    printf("ordenado? %d", isOrd(array, size));
    printf("\n");

    if(!isOrd(array, size)) {
        printf("ordenando...\n");

        ord_ins(array, size);

        for(i = 0; i < size; i++) {
            printf("%d, ", array[i]);
        }

        isOrd(array, size)? printf("\nEsta ordenado.\n") : printf("\nNo se ordenó.\n");
    }
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
