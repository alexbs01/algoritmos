/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "monticulo.h"


void crear_monticulo(int array[], int size, monticulo *m) {
    int i;

    for(i = 0; i <= size; i++) {
        m->vector[i] = array[i];
    }
    m->ultimo = size;

    for(i = size/2; i >= 0; i--) {
        hundir(m, i);
    }
}

void hundir(monticulo *m, int n) {
    int j;

    do {
        int hijoizq = 2 * n + 1;
        int hijoder = 2 * n + 2;
        j = n;

        if((hijoder <= m->ultimo) && (m->vector[hijoder] > m->vector[n])) {
            n = hijoder;
        }
        if((hijoizq <= m->ultimo) && (m->vector[hijoizq] > m->vector[n])) {
            n = hijoizq;
        }

        intercambiar(&m->vector[j], &m->vector[n]);
    } while(j != n);
}

void intercambiar(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


int eliminar_mayor(monticulo *m) {
    if(monticulo_vacio(*m)) {
        printf("Error: monticulo vacio");

    } else {
        int x;
        x = m->vector[0];
        m->vector[0] = m->vector[m->ultimo];
        m->ultimo = m->ultimo - 1; // [2 7 3 1 5] 2

        if(m->ultimo > 0) {
            hundir(m, 0);
        }

        return x;
    }
}

bool monticulo_vacio(monticulo m){
    return (m.ultimo == -1);
}
