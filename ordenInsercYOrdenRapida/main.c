#include <stdio.h>
#include "algoritmosOrdenacion.h"
#include "generacionNumeros.h"

int main() {
    inicializar_semilla();
    int numeroElementos;

    printf("Escribe cuantos elementos quieres en el array: ");
    scanf("%d", &numeroElementos);

    int arrayNumeros[numeroElementos];

    aleatorio(arrayNumeros, numeroElementos);

    test(arrayNumeros);

    ord_ins(arrayNumeros, numeroElementos);

    return 0;
}

