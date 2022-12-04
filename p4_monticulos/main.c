/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include <stdio.h>
#include "funcionesAuxiliares.h"

#define INICIAL_SIZE 500
#define MAX_SIZE 512000

int main() {

    test();
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios.

    printf("\n*************************************************************\n");
    printf("N: Cantidad de números del array insertado en el monticulo.\n");
    printf("T: Tiempo medio de crear_monticulo en microsegundos (us).\n");
    printf("T/CSub: Tiempo medio entre la Cota Subestimada.\n");
    printf("T/CAjus: Tiempo medio entre la Cota Ajustada.\n");
    printf("T/CSobre: Tiempo medio entre la Cota Sobreestimada.");
    printf("\n*************************************************************\n");

    //calentarProcesador(INICIAL_SIZE, MAX_SIZE);
    tabla(INICIAL_SIZE, MAX_SIZE);

    printf("\n");
    return 0;
}

