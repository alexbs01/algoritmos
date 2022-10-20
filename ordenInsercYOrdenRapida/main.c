/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */
#include "imprimirTablas.h"
#include <stdio.h>

#include "algoritmosOrdenacion.h"
#include "generacionNumeros.h"

#define inicialSize 500

int main() {
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios
    int /*inicialSize = 500,*/ totalSize = 512000, maxTime = 10000000;
    int array[20];
    printf("Test de ordenación por inserción\n");
    test(ord_ins);
    printf("Test de ordenación con Quicksort\n");
    test(ordRapida);

    // Medición de tiempos con el algoritmo de ORDENACIÓN POR INSERCIÓN
    printf("\n*************************************************************\n");
    printf("N: Cantidad de números a ordenar.\n");
    printf("I: Numero de veces que se repite el algoritmo.\n");
    printf("T: Tiempo medio de ejecución del algoritmo en microsegundos (us).\n");
    printf("T/CSub: Tiempo medio entre la Cota Subestimada.\n");
    printf("T/CAjus: Tiempo medio entre la Cota Ajustada.\n");
    printf("T/CSobre: Tiempo medio entre la Cota Sobreestimada.\n");
    //printf("\n*************************************************************\n");

    tablaInsercionAl(inicialSize, totalSize, maxTime);

    printf("\n\n*********************************************************\n");
    tablaInsercionAs(inicialSize, totalSize, maxTime);

    printf("\n\n*********************************************************\n");
    tablaInsercionDes(inicialSize, totalSize, maxTime);

    printf("\n***************************************************************");
    printf("\n***************************************************************");

    printf("\n\n*********************************************************\n");
    tablaOrdRapidaAl(inicialSize, totalSize, maxTime);

    printf("\n\n*********************************************************\n");
    tablaOrdRapidaAs(inicialSize, totalSize, maxTime);

    printf("\n\n*********************************************************\n");
    tablaOrdRapidaDes(inicialSize, totalSize, maxTime);

    return 0;
}
