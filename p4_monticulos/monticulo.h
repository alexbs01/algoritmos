/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef P4_MONTICULOS_MONTICULO_H
#define P4_MONTICULOS_MONTICULO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 512000

typedef struct monticulo {
    int vector[TAM];
    int ultimo;
} monticulo;

void crear_monticulo(int array[], int size, monticulo *M);
void hundir(monticulo *M, int n);
void intercambiar(int *a, int *b);

int eliminar_mayor(monticulo *M);

bool monticulo_vacio(monticulo M);

void inicializarMonticulo(monticulo* M);
void ord_monticulo(int array[], int n);

#endif //P4_MONTICULOS_MONTICULO_H
