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

#define INICIAL_SIZE 500
#define MAX_SIZE 256000

void test();

void inicializar_semilla();
void aleatorio(int v [], int n);

double microsegundos();
double tardanzaI(int array[], int size, arbol *T);
double tardanzaB(int array[], int size, arbol *T);

void tablaIB(int inicialSize, int maxSize);

void tablaI(int inicialSize, int maxSize, const double arrayI[],
            const double arrayB[]);
void tablaB(int inicialSize, int maxSize, const double arrayI[],
            const double arrayB[]);

#endif //P3_ARBOLESBINARIOSDEBUSQUEDA_FUNCIONESAUXILIARES_H
