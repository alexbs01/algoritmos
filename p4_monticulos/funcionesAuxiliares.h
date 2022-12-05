
/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef P4_MONTICULOS_FUNCIONESAUXILIARES_H
#define P4_MONTICULOS_FUNCIONESAUXILIARES_H

#include "monticulo.h"

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

typedef struct chrono {
    int count;
    double tiempoMedio;
}chrono;

void inicializar_semilla();
double microsegundos();

void ascendente(int v [], int n);
void aleatorio(int v [], int n);
void descendente(int v[], int n);

void visualizar(monticulo m);

int altura(int a);
bool esUltimaAltura(int a, monticulo M);
void hijosYpadre(monticulo m);
void test();

chrono tardanzaCrear(int array[], int size, monticulo *m,
                     void (*tipoArray)(int array[], int size));
void calentarProcesador(int inicialSize, int maxSize);
void tabla(int inicialSize, int maxSize);

void test2();

chrono tardanzaOrd(int array[], int size,
                   void (*tipoArray)(int array[], int size));
void tablaOrdAscendente(int inicialSize, int maxSize);
void tablaOrdDescendente(int inicialSize, int maxSize);
void tablaOrdAleatorio(int inicialSize, int maxSize);

#endif //P4_MONTICULOS_FUNCIONESAUXILIARES_H