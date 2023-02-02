/*
 * AUTOR 1: Alejandro Becerra Suárez
 * */

#include "imprimirTablas.h"

void tablaInsercionAl(int inicialSize, int totalSize, int maxTime) {
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    printf("\n*********************************************************\n");
    printf("Tiempos de ordenación con array ALEATORIO:\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, aleatorio, ordenar);

        TSu = dato.tiempoMedio / pow(actualSize, 1);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / pow(actualSize, 1.149);      // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 1.6);   // Tiempo/ CotaSobreestimada

        printf("%8d\t%8d\t%15lf\t %14lf\t%14lf\t%14lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}

void tablaInsercionAs(int inicialSize, int totalSize, int maxTime){
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Tiempos de ordenación con array ASCENDENTE:\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, ascendente, ordenar);

        TSu = dato.tiempoMedio / pow(actualSize, 1.6);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / pow(actualSize, 2);   // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 2.1);   // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}

void tablaInsercionDes(int inicialSize, int totalSize, int maxTime) {
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Tiempos de ordenación con array DESCENDENTE\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, descendente, ordenar);

        TSu = dato.tiempoMedio / pow(actualSize, 1.9);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / pow(actualSize, 2.2);  // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 2.4);   // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}