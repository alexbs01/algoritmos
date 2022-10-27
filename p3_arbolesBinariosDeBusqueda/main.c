/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */
#include <stdio.h>
#include "funcionesAuxiliares.h"

#define INICIAL_SIZE 8000
#define MAX_SIZE 256000

int main() {
    test();
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios.

    printf("\n*************************************************************\n");
    printf("N: Cantidad de números que se insertan al arbol.\n");
    printf("II: Numero de veces que se repite una inserción.\n");
    printf("IB: Numero de veces que se repite una búsqueda.\n");
    printf("T: Tiempo medio de inserción en microsegundos (us).\n");
    printf("T/CSub: Tiempo medio entre la Cota Subestimada.\n");
    printf("T/CAjus: Tiempo medio entre la Cota Ajustada.\n");
    printf("T/CSobre: Tiempo medio entre la Cota Sobreestimada.\n");
    printf("\n*************************************************************\n");

    tablaIB(INICIAL_SIZE, MAX_SIZE);
    tablaI(INICIAL_SIZE, MAX_SIZE);
    tablaB(INICIAL_SIZE, MAX_SIZE);

    return 0;
}
