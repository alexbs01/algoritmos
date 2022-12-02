/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef P4_MONTICULOS_MONTICULO_H
#define P4_MONTICULOS_MONTICULO_H

#include <stdio.h>
#include <stdlib.h>
#define TAM 512000

typedef struct monticulo {
    int vector[TAM];
    int ultimo;
} monticulo;

void crear_monticulo(int array[], int size, monticulo *m);
int eliminar_mayor(monticulo *m);
void inicializar_semilla();
void aleatorio(int v [], int n);
void hundir(monticulo *m, int n);
void ord_monticulos(int array[], int n);
void intercambiar(int *a, int *b);

#endif //P4_MONTICULOS_MONTICULO_H
