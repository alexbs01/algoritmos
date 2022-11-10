/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */
#include <stdio.h>
#include "funcionesAuxiliares.h"

#define INICIAL_SIZE 500
#define MAX_SIZE 256000

int main() {
    test();

    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios.

    printf("\n*************************************************************\n");
    printf("N: Cantidad de números que se insertan y buscan en un árbol.\n");
    printf("T_ins: Tiempo medio de inserción en microsegundos (us).\n");
    printf("T_bus: Tiempo medio de búsqueda en microsegundos (us).\n");
    printf("T: Tiempo medio de inserción o búsqueda en microsegundos (us).\n");
    printf("T/CSub: Tiempo medio entre la Cota Subestimada.\n");
    printf("T/CAjus: Tiempo medio entre la Cota Ajustada.\n");
    printf("T/CSobre: Tiempo medio entre la Cota Sobreestimada.\n");
    printf("\n*************************************************************\n");

    calentarProcesador(INICIAL_SIZE, MAX_SIZE);



    
    tablaIB(INICIAL_SIZE, MAX_SIZE);

    return 0;
}
