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
    int numeroElementos = 100;


    //printf("Escribe cuantos elementos quieres en el array: ");
    //scanf("%d", &numeroElementos);
    int arrayNumeros[numeroElementos];

    do {
        printf("\n\nTiempos para un array de %d elementos\n", numeroElementos);
        // Calculamos los tiempos con ambos algoritmos con un array de números aleatorios
        printf("Numeros aleatorios\n");
        aleatorio(arrayNumeros, numeroElementos);
        tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);
        aleatorio(arrayNumeros, numeroElementos);
        tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        // Calculamos los tiempos utilizando un array ya ordenado de menor a mayor
        printf("\nNumeros ascendentes\n");
        ascendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);
        ascendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        // Volvemos a calcular los tiempos, pero esta vez con un array ordenado de mayor a menor
        printf("\nNumeros descendentes\n");
        descendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);
        descendente(arrayNumeros, numeroElementos);
        tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        printf("\n***************************************************");

        numeroElementos *= 10;
    } while(numeroElementos <= 100000);


    return 0;
}

