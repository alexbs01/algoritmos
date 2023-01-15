/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */
#include "imprimirTablas.h"
#include <stdio.h>

#include "algoritmosOrdenacion.h"


#define INICIAL_SIZE 500
#define MAX_SIZE 512000
#define MAX_TIME 500000

int main() {
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios

    printf("Test de ordenación por inserción\n");
    test(ord_ins);//ESTE TEST TIENE QUE COMPROBAR OTRAS ORDENACIOENS DE ENTRADA APARTE DE LA ALEATORIA
    //ADEMAS TIENES QUE USAR UNA FUNCION PRECALENTAR PROCESADOR




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

/*
procedimiento Mediana 3 ( var T[i..j] )
    centro := ( i+j ) div 2 ;
    si T[i] > T[centro] entonces intercambiar ( T[i], T[centro] ) ;
    si T[i] > T[j] entonces intercambiar ( T[i], T[j] ) ;
    si T[centro] > T[j] entonces intercambiar ( T[centro], T[j] ) ;
    intercambiar ( T[centro], T[j-1] )
fin procedimiento*/



/*Ordenaci  ́on R  ́apida (3)
procedimiento Qsort ( var T[i..j] )

 si i+UMBRAL <= j entonces
    Mediana 3 ( T[i..j] ) ;
    pivote := T[j-1] ; k := i ; m := j-1 ; {s ́olo con Mediana 3}
    repetir
    repetir k := k+1 hasta T[k] >= pivote ;
        repetir m := m-1 hasta T[m] <= pivote ;
        intercambiar ( T[k], T[m] )
    hasta m <= k ;
    intercambiar ( T[k], T[m] ) ; {deshace el  ́ultimo intercambio}
    intercambiar ( T[k], T[j-1] ) ; {pivote en posici ́on k}
    Qsort ( T[i..k-1] ) ;
    Qsort ( T[k+1..j] )
fin procedimiento

procedimiento Quicksort ( var T[1..n] )
    Qsort ( T[1..n] ) ;
    Ordenaci ́on por Inserci ́on ( T[1..n] )
fin procedimiento
 */
