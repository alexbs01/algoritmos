/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef P3_ARBOLESBINARIOSDEBUSQUEDA_FUNCIONESAUXILIARES_H
#define P3_ARBOLESBINARIOSDEBUSQUEDA_FUNCIONESAUXILIARES_H

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include "tipoArbol.h"

#define INICIAL_SIZE 8000
#define MAX_SIZE 256000

typedef struct chrono {
    int count;
    double tiempoMedio;
}chrono;

void test();

void inicializar_semilla();
void aleatorio(int v [], int n);

double microsegundos();
chrono tardanzaI(int array[], int size);
chrono tardanzaB(int array[], int size);

void tablaIB(int inicialSize, int maxSize);
void tablaI(int inicialSize, int maxSize, double arrayI[]);
void tablaB(int inicialSize, int maxSize, double arrayB[]);

#endif //P3_ARBOLESBINARIOSDEBUSQUEDA_FUNCIONESAUXILIARES_H
