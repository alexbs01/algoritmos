/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include <stdio.h>
#include "algoritmosOrdenacion.h"
#include "generacionNumeros.h"
#include "medicionDeTiempos.h"

int main() {
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios
    int numeroElementosInicial = 1, numeroElementos = numeroElementosInicial, elementosTotales = 1000;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumeros[elementosTotales];

    // Medición de tiempos con el algoritmo de ORDENACIÓN POR INSERCIÓN
    printf("Medición de tiempos con ordenación por inserción");
    do {
        printf("\n\nTiempos para un array de %d elementos\n", numeroElementos);

        // Calculamos los tiempos con ambos algoritmos con un array de números aleatorios
        printf("Numeros aleatorios\n");
        aleatorio(arrayNumeros, numeroElementos);
        tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);

        // Calculamos los tiempos utilizando un array ya ordenado de menor a mayor
        printf("\nNumeros ascendentes\n");
        ascendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);

        // Volvemos a calcular los tiempos, pero esta vez con un array ordenado de mayor a menor
        printf("\nNumeros descendentes\n");
        descendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);

        printf("\n***************************************************");

        numeroElementos *= 10;

    } while(numeroElementos <= elementosTotales);

    numeroElementos = numeroElementosInicial; // Restablecemos el número de elementos

    // Medición de tiempos con QUICKSORT
    printf("\n***************************************************");
    printf("\n\nMedición de tiempos con Quicksort\n");

    do {
        printf("\nTiempos para un array de %d elementos\n", numeroElementos);

        // Calculamos los tiempos con ambos algoritmos con un array de números aleatorios
        printf("Numeros aleatorios\n");
        aleatorio(arrayNumeros, numeroElementos);
        tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        // Calculamos los tiempos utilizando un array ya ordenado de menor a mayor
        printf("\nNumeros ascendentes\n");
        ascendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        // Volvemos a calcular los tiempos, pero esta vez con un array ordenado de mayor a menor
        printf("\nNumeros descendentes\n");
        descendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        printf("\n***************************************************\n");

        numeroElementos *= 10;
    } while(numeroElementos <= elementosTotales);


    return 0;
}

