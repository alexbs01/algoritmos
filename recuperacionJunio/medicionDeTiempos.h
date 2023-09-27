/*
 * AUTOR 1: Alejandro Becerra Suárez
 * */

#ifndef ORDENINSERCYORDENRAPIDA_MEDICIONDETIEMPOS_H
#define ORDENINSERCYORDENRAPIDA_MEDICIONDETIEMPOS_H

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "algoritmosOrdenacion.h"
#include <math.h>

typedef struct chrono {
    int count;
    double tiempoMedio;
}chrono;
void inicializar_semilla();
void aleatorio(int v[], int n); // Se generan número pseudo aleatorios entre -n y +n.
void ascendente(int v[], int n);
void descendente(int v[], int n);
double microsegundos();
chrono tardanza(int array[], int size, void (*tipoArray)(int v [], int n), void (*tipoOrd)(int v [], int n));
void calentarProcesador(int inicialSize, int totalSize, int maxTime);
#endif //ORDENINSERCYORDENRAPIDA_MEDICIONDETIEMPOS_H
