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
chrono tiempoOrdenacionInsercion(int array[], int size);
chrono tiempoOrdenacionQuicksort(int array[], int size);

#endif //ORDENINSERCYORDENRAPIDA_MEDICIONDETIEMPOS_H
