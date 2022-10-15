/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include <stdio.h>
#include <math.h>

#include "algoritmosOrdenacion.h"
#include "generacionNumeros.h"
#include "medicionDeTiempos.h"

int main() {
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios
    int inicialSize = 500, totalSize = 32000;
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    // Medición de tiempos con el algoritmo de ORDENACIÓN POR INSERCIÓN
    printf("\n*************************************************************\n");
    printf("N: Cantidad de numeros a ordenar.\n");
    printf("I: Numero de veces que se repite el algoritmo.\n");
    printf("T: Tiempo medio de ejecucion del algoritmo.\n");
    printf("T/CSub: Tiempo medio entre la Cota Subestimada.\n");
    printf("T/CAjus: Tiempo medio entre la Cota Ajustada.\n");
    printf("T/CSobre: Tiempo medio entre la Cota Sobreestimada.\n");
    printf("\n*************************************************************\n");

    printf("Tiempos con Ordenacion por Insercion con array ALEATORIO:\n\n");
    printf("   [N]\t\t[I]\t\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, aleatorio, ord_ins);

        TSu = dato.tiempoMedio / pow(actualSize, 1.8);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / pow(actualSize, 2);      // Tiempo/ CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 2.2);   // Tiempo/ CotaSobreestimada

        printf("%8d\t%8d\t%15lf\t %14lf\t%14lf\t%14lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize);

    actualSize = inicialSize; // Restablecemos el número de elementos

    printf("\n\n\n*********************************************************\n");
    printf("Tiempos con Ordenacion por Insercion con array ASCENDENTE:\n\n");
    printf("   [N]\t\t[I]\t\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, ascendente, ord_ins);

        TSu = dato.tiempoMedio / pow(actualSize, 0.8);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / actualSize;              // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 1.2);   // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize);

    actualSize = inicialSize; // Restablecemos el número de elementos

    printf("\n\n\n*********************************************************\n");
    printf("Tiempos con Ordenacion por Insercion con array DESCENDENTE\n\n");
    printf("   [N]\t\t[I]\t\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, descendente, ord_ins);

        TSu = dato.tiempoMedio / pow(actualSize, 1.8);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / pow(actualSize, 2);      // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 2.2);   // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize);

/**********************************************************************************************************************/
/**********************************************************************************************************************/

    printf("\n***************************************************************");
    printf("\n*-------------------------------------------------------------*");
    printf("\n***************************************************************");

    actualSize = inicialSize; // Restablecemos el número de elementos

    printf("\n\n\n*********************************************************\n");
    printf("Tiempos con Ordenacion por Quicksort con array ALEATORIO:\n\n");
    printf("   [N]\t\t[I]\t\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, aleatorio, ordRapida);

        TSu = dato.tiempoMedio / actualSize;                    // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / (actualSize * log(actualSize));    // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / (actualSize * log2(actualSize));  // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize);

    actualSize = inicialSize; // Restablecemos el número de elementos

    printf("\n\n\n*********************************************************\n");
    printf("Tiempos con Ordenacion por Quicksort con array ASCENDENTE:\n\n");
    printf("   [N]\t\t[I]\t\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, ascendente, ordRapida);

        TSu = dato.tiempoMedio / actualSize;                    // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / (actualSize * log(actualSize));    // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / (actualSize * log2(actualSize));  // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize);


            actualSize = inicialSize; // Restablecemos el número de elementos

    printf("\n\n\n*********************************************************\n");
    printf("Tiempos con Ordenacion por Quicksort con array DESCENDENTE\n\n");
    printf("   [N]\t\t[I]\t\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, descendente, ordRapida);

        TSu = dato.tiempoMedio / actualSize;                    // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / (actualSize * log(actualSize));    // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / (actualSize * log2(actualSize));  // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize);


    return 0;
}

