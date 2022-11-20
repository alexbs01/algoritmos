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

        if(UMBRAL == 1) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.95);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.08715);    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.2);       // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 10) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.95);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.08715);    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.2);       // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 100) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.91);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.085);      // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.23);      // Tiempo / CotaSobreestimada
        }

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
            TSu = dato.tiempoMedio / pow(actualSize, 0.95);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.08715);    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.2);       // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 10) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.95);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.08715);    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.2);       // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 100) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.91);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.085);      // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.23);      // Tiempo / CotaSobreestimada
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
            TSu = dato.tiempoMedio / pow(actualSize, 0.95);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.08715);    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.2);       // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 10) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.95);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.08715);    // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.2);       // Tiempo / CotaSobreestimada
        } else if(UMBRAL == 100) {
            TSu = dato.tiempoMedio / pow(actualSize, 0.91);     // Tiempo / CotaSubestimada
            TA= dato.tiempoMedio / pow(actualSize, 1.085);      // Tiempo / CotaAjustada
            TSo= dato.tiempoMedio / pow(actualSize, 1.23);      // Tiempo / CotaSobreestimada
        }

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while(actualSize <= totalSize && dato.tiempoMedio <= maxTime);
}