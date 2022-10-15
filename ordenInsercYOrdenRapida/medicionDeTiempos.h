/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef ORDENINSERCYORDENRAPIDA_MEDICIONDETIEMPOS_H
#define ORDENINSERCYORDENRAPIDA_MEDICIONDETIEMPOS_H

#include <stdlib.h>
#include <sys/time.h>
#include "algoritmosOrdenacion.h"

typedef struct chrono {
    int count;
    double tiempoMedio;
}chrono;

double microsegundos();
chrono tardanza(int array[], int size, void (*tipoArray)(int v [], int n), void (*tipoOrd)(int v [], int n));

#endif //ORDENINSERCYORDENRAPIDA_MEDICIONDETIEMPOS_H
