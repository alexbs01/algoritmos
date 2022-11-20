/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "monticulo.h"

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

        for(n = 0; n < TAM; n++) {
            m->vector[j] = m->vector[n];
        }

    } while(j != n);
}

void crear_monticulo(int array[], int size, monticulo *m) {
    int i;

    for(i = 0; i < TAM; i++) {
        m->vector[i] = array[i];
    }

    m->ultimo = size;

    for(i = m->ultimo / 2; i <= 1; i--) {
        hundir(m, i);
    }
}

int eliminar_mayor(monticulo *m) {
    if(m->ultimo==0) {
        printf("Error: monticulo vacio");

    } else {
        int x;
        x = m->vector[1];
        m->vector[1] = m->vector[m->ultimo];
        m->ultimo = m->ultimo - 1;

        if(m->ultimo > 0) {
            hundir(m, 1);
        }

        return x;
    }
}

