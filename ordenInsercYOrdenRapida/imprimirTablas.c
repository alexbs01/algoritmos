/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "imprimirTablas.h"

void tablaInsercionAl(int inicialSize, int totalSize, int maxTime) {
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    printf("\n*********************************************************\n");
    printf("Tiempos con Ordenación por Inserción con array ALEATORIO:\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, aleatorio, ord_ins);
        for(int i = 0; i < 10; i++) {
            tardanza(arrayNumbers, actualSize, aleatorio, ord_ins);
        }
        TSu = dato.tiempoMedio / pow(actualSize, 1.8);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / pow(actualSize, 1.99);      // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 2.2);   // Tiempo/ CotaSobreestimada

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
    printf("Tiempos con Ordenación por Inserción con array ASCENDENTE:\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, ascendente, ord_ins);

        TSu = dato.tiempoMedio / pow(actualSize, 0.8);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / actualSize;                    // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 1.1);   // Tiempo / CotaSobreestimada

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
    printf("Tiempos con Ordenación por Inserción con array DESCENDENTE\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");
    do{
        dato = tardanza(arrayNumbers, actualSize, descendente, ord_ins);

        TSu = dato.tiempoMedio / pow(actualSize, 1.8);  // Tiempo / CotaSubestimada
        TA= dato.tiempoMedio / pow(actualSize, 2);      // Tiempo / CotaAjustada
        TSo= dato.tiempoMedio / pow(actualSize, 2.2);   // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}

void tablaOrdRapidaAl(int inicialSize, int totalSize, int maxTime) {
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Tiempos con Ordenación por Quicksort con array ALEATORIO:\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, aleatorio, ordRapida);
        /*for(int i = 0; i <= 10; i++) {
            tardanza(arrayNumbers, actualSize, aleatorio, ordRapida);
        }*/
        if(UMBRAL == 1) {
            TSu = dato.tiempoMedio / actualSize;                    // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / (actualSize * 0.9 * log(actualSize));    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.6); // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 10) {
            TSu = dato.tiempoMedio / pow(actualSize, 1.05);
            TA= dato.tiempoMedio / pow(actualSize, 1.112);
            TSo= dato.tiempoMedio / pow(actualSize, 1.6);
        } else if(UMBRAL == 100) {
            TSu = dato.tiempoMedio / pow(actualSize, 1.05);
            TA= dato.tiempoMedio / pow(actualSize, 1.111);
            TSo= dato.tiempoMedio / pow(actualSize, 1.6);
        }


        /*1.10920
        1.12212
        1.11066*/

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}

void tablaOrdRapidaAs(int inicialSize, int totalSize, int maxTime) {
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Tiempos con Ordenación por Quicksort con array ASCENDENTE:\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, ascendente, ordRapida);

        if(UMBRAL == 1) {
            TSu = dato.tiempoMedio / pow(actualSize, 1.05);                   // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / (actualSize * log(actualSize));    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.6);  // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 10) {
            TSu = dato.tiempoMedio / actualSize;
            TA= dato.tiempoMedio / pow(actualSize, 1.12);
            TSo= dato.tiempoMedio / pow(actualSize, 1.6);
        } else if(UMBRAL == 100) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.9);
            TA= dato.tiempoMedio / pow(actualSize, 1.114);
            TSo= dato.tiempoMedio / pow(actualSize, 1.6);
        }


        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}

void tablaOrdRapidaDes(int inicialSize, int totalSize, int maxTime) {
    int actualSize = inicialSize;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumbers[totalSize];
    chrono dato;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Tiempos con Ordenación por Quicksort con array DESCENDENTE\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do{
        dato = tardanza(arrayNumbers, actualSize, descendente, ordRapida);

        if(UMBRAL == 1) {
            TSu = dato.tiempoMedio / actualSize;               // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / (actualSize * 0.9 * log(actualSize));    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.6);  // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 10) {
            TSu = dato.tiempoMedio / actualSize;
            TA= dato.tiempoMedio / pow(actualSize, 1.12);
            TSo= dato.tiempoMedio / pow(actualSize, 1.6);
        } else if(UMBRAL == 100) {
            TSu = dato.tiempoMedio / pow(actualSize, 1);
            TA= dato.tiempoMedio / pow(actualSize, 1.11);
            TSo= dato.tiempoMedio / pow(actualSize, 1.3);
        }


        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}
