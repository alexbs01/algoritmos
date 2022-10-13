/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "generacionNumeros.h"

void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int v [], int n) {
    int i, m = 2 * n + 1;

    for(i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}

void ascendente(int v [], int n) {
    int i;

    for(i = 0; i < n; i++) {
        v[i] = i;
    }
}

void descendente(int v[], int n) {
    int i;

    for(i = 0; i < n; i++) {
        v[i] = n - i;
    }
}