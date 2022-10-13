#include <stdio.h>
#include "algoritmosOrdenacion.h"
#include "generacionNumeros.h"
#include "medicionDeTiempos.h"

int main() {
    inicializar_semilla();
    int numeroElementos;

    printf("Escribe cuantos elementos quieres en el array: ");
    scanf("%d", &numeroElementos);

    int arrayNumeros[numeroElementos];

    printf("Numeros aleatorio\n");
    aleatorio(arrayNumeros, numeroElementos);
    // test(arrayNumeros, numeroElementos);
    // ord_ins(arrayNumeros, numeroElementos);
    tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);
    aleatorio(arrayNumeros, numeroElementos);
    tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

    printf("\nNumeros ascendentes\n");
    ascendente(arrayNumeros, numeroElementos);
    // test(arrayNumeros, numeroElementos);
    // ord_ins(arrayNumeros, numeroElementos);
    tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);
    ascendente(arrayNumeros, numeroElementos);
    tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

    printf("\nNumeros descendentes\n");
    descendente(arrayNumeros, numeroElementos);
    // test(arrayNumeros, numeroElementos);
    // ord_ins(arrayNumeros, numeroElementos);
    tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);
    descendente(arrayNumeros, numeroElementos);
    tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

    return 0;
}

