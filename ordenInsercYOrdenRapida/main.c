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
    int numeroElementosInicial = 10, elementosTotales = 10000;
    int numeroElementos = numeroElementosInicial;

    // Inicializamos el array con el número de elementos que tendrá al final de la última prueba
    int arrayNumeros[elementosTotales];
    chrono dato;
    double TSu, TA, TSo;

    // Medición de tiempos con el algoritmo de ORDENACIÓN POR INSERCIÓN
    printf("Medición de tiempos con ordenación por inserción con array ALEATORIO\n");
    printf("Nº Elemen.\tNº Itera.\t\tTiempo\t\tT(n)/CSub\tT(n)/CAjus\tT(n)/CSobre \n");
    do{
        aleatorio(arrayNumeros, numeroElementos);
        dato = tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);

        TSu = dato.tiempoMedio / pow(numeroElementos, 1.9);   //tiempo/cotaSubestimada
        TA= dato.tiempoMedio / pow(numeroElementos, 2)/2;     //tiempo/cotaAjustada
        TSo= dato.tiempoMedio / pow(numeroElementos, 2.1);    //Alomejor pow(n, 2.2); tiempo/cotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               numeroElementos, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        numeroElementos *= 10;
    } while(numeroElementos <= elementosTotales);

    numeroElementos = numeroElementosInicial; // Restablecemos el número de elementos

    printf("\n\nMedición de tiempos con Quicksort con array ALEATORIO\n");
    printf("Nº Elemen.\tNº Itera.\t\tTiempo\t\tT(n)/CSub\tT(n)/CAjus\tT(n)/CSobre \n");
    do{
        aleatorio(arrayNumeros, numeroElementos);
        dato = tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        //double cotaSubestimada = tiempoFib1(n).temp / pow(1.1, n);
        //double cotaAjustada = tiempoFib1(n).temp / pow(((1+sqrt(5)) / 2), n);
        //double cotaSobreestimada = tiempoFib1(n).temp / pow(2, n);

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               numeroElementos, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        numeroElementos *= 10;
    } while(numeroElementos <= elementosTotales);

    numeroElementos = numeroElementosInicial; // Restablecemos el número de elementos

    printf("\n\n\n***************************************************\n");
    printf("Medición de tiempos con ordenación por inserción con array ASCENDENTE\n");

    printf("Nº Elemen.\tNº Itera.\t\tTiempo\t\tT(n)/CSub\tT(n)/CAjus\tT(n)/CSobre \n");
    do{
        ascendente(arrayNumeros, numeroElementos);
        dato = tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);

        TSu = dato.tiempoMedio / pow(numeroElementos, 1.9);   //tiempo/cotaSubestimada
        TA= dato.tiempoMedio / pow(numeroElementos, 2)/2;     //tiempo/cotaAjustada
        TSo= dato.tiempoMedio / pow(numeroElementos, 2.1);    //Alomejor pow(n, 2.2); tiempo/cotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               numeroElementos, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        numeroElementos *= 10;
    } while(numeroElementos <= elementosTotales);

    numeroElementos = numeroElementosInicial; // Restablecemos el número de elementos

    printf("\n\nMedición de tiempos con Quicksort con array ASCENDENTE\n");
    printf("Nº Elemen.\tNº Itera.\t\tTiempo\t\tT(n)/CSub\tT(n)/CAjus\tT(n)/CSobre \n");
    do{
        ascendente(arrayNumeros, numeroElementos);
        dato = tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        //double cotaSubestimada = tiempoFib1(n).temp / pow(1.1, n);
        //double cotaAjustada = tiempoFib1(n).temp / pow(((1+sqrt(5)) / 2), n);
        //double cotaSobreestimada = tiempoFib1(n).temp / pow(2, n);

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               numeroElementos, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        numeroElementos *= 10;
    } while(numeroElementos <= elementosTotales);

    numeroElementos = numeroElementosInicial; // Restablecemos el número de elementos

    printf("\n\n\n***************************************************\n");
    printf("Medición de tiempos con ordenación por inserción con array DESCENDENTE\n");

    printf("Nº Elemen.\tNº Itera.\t\tTiempo\t\tT(n)/CSub\tT(n)/CAjus\tT(n)/CSobre \n");
    do{
        descendente(arrayNumeros, numeroElementos);
        dato = tiempoOrdenacionInsercion(arrayNumeros, numeroElementos);

        TSu = dato.tiempoMedio / pow(numeroElementos, 1.9);   //tiempo/cotaSubestimada
        TA= dato.tiempoMedio / pow(numeroElementos, 2)/2;     //tiempo/cotaAjustada
        TSo= dato.tiempoMedio / pow(numeroElementos, 2.1);    //Alomejor pow(n, 2.2); tiempo/cotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               numeroElementos, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        numeroElementos *= 10;
    } while(numeroElementos <= elementosTotales);

    numeroElementos = numeroElementosInicial; // Restablecemos el número de elementos

    printf("\n\nMedición de tiempos con Quicksort con array DESCENDENTE\n");
    printf("Nº Elemen.\tNº Itera.\t\tTiempo\t\tT(n)/CSub\tT(n)/CAjus\tT(n)/CSobre \n");
    do{
        descendente(arrayNumeros, numeroElementos);
        dato = tiempoOrdenacionQuicksort(arrayNumeros, numeroElementos);

        //double cotaSubestimada = tiempoFib1(n).temp / pow(1.1, n);
        //double cotaAjustada = tiempoFib1(n).temp / pow(((1+sqrt(5)) / 2), n);
        //double cotaSobreestimada = tiempoFib1(n).temp / pow(2, n);

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               numeroElementos, dato.count, dato.tiempoMedio, TSu, TA, TSo);

        numeroElementos *= 10;
    } while(numeroElementos <= elementosTotales);

    return 0;
}

