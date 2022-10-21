/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */
#include "imprimirTablas.h"
#include <stdio.h>

#include "algoritmosOrdenacion.h"
#include "generacionNumeros.h"

#define INICIAL_SIZE 500
#define MAX_SIZE 512000
#define MAX_TIME 500000

int main() {
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios

    printf("Test de ordenación por inserción\n");
    test(ord_ins);
    printf("Test de ordenación con Quicksort\n");
    test(ordRapida);

    printf("\n*************************************************************\n");
    printf("N: Cantidad de números a ordenar.\n");
    printf("I: Numero de veces que se repite el algoritmo.\n");
    printf("T: Tiempo medio de ejecución en microsegundos (us).\n");
    printf("T/CSub: Tiempo medio entre la Cota Subestimada.\n");
    printf("T/CAjus: Tiempo medio entre la Cota Ajustada.\n");
    printf("T/CSobre: Tiempo medio entre la Cota Sobreestimada.\n");
    printf("\n*************************************************************\n");

    // Medición de tiempos con el algoritmo de ORDENACIÓN POR INSERCIÓN

    tablaInsercionAl(INICIAL_SIZE, MAX_SIZE, MAX_TIME);
    tablaInsercionAs(INICIAL_SIZE, MAX_SIZE, MAX_TIME);
    tablaInsercionDes(INICIAL_SIZE, MAX_SIZE, MAX_TIME);

    printf("\n***************************************************************");
    printf("\n***************************************************************");

    // Medición de tiempos con el algoritmo de ORDENACIÓN POR QUICKSORT

    tablaOrdRapidaAl(INICIAL_SIZE, MAX_SIZE, MAX_TIME);
    tablaOrdRapidaAs(INICIAL_SIZE, MAX_SIZE, MAX_TIME);
    tablaOrdRapidaDes(INICIAL_SIZE, MAX_SIZE, MAX_TIME);

    return 0;
}
