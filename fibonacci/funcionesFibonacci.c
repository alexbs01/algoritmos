//
// Created by alexb on 15/09/2022.
//

#include "funcionesFibonacci.h"
#include <math.h>

/* Algoritmo fib1: O(φ^n), φ = (1+√5)/2 */

int fib1(int n) { // Algoritmo recursivo, el más lento de los 3.
    if(n < 2) {
        return n;
    } else {
        return fib1(n - 1) + fib1(n - 2);
    }
}

/* Algoritmo fib2: O(n) */

int fib2(int n) { // Realiza un bucle intercambiando variables.
    int i, j, k;
    i = 1;
    j = 0;
    for(k = 1; k <= n; k++) {
        j = i + j;
        i = j - i;
    }
    return j;
}

/* Algoritmo fib3: O(log n) */

int fib3(int n) {
    int i = 1, j = 0, k = 0, h = 1, t;
    while(n > 0) {
        if((n % 2) != 0) {
            t = j * h;
            j = (i * h) + (j * k) + t;
            i = (i * k) + t;
        }
        t = h * h;
        h = (2 * k * h) + t;
        k = (k * k) + t;
        n = n / 2;
    }
    return j;
}

/*--------------------------------------------------------------------------------------------------------------------*/

/* Función para calcular el tiempo que pasa. */

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

/* Función para calcular cuanto tarda Fib1 */

double tiempoFib1(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 0;
    tiempoInicial = microsegundos();
    do {
        fib1(numero);
        tiempoFinal = microsegundos();
        count++;
    } while(tiempoFinal - tiempoInicial <= 500);

    return((tiempoFinal - tiempoInicial)/count);
}

/* Función para calcular cuanto tarda Fib2 */

double tiempoFib2(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 0;
    tiempoInicial = microsegundos();
    do {
        fib2(numero);
        tiempoFinal = microsegundos();
        count++;
    } while(tiempoFinal - tiempoInicial <= 500);
    return((tiempoFinal - tiempoInicial)/count);
}

/* Función para calcular cuanto tarda Fib3 */

double tiempoFib3(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 0;
    tiempoInicial = microsegundos();
    do {
        fib3(numero);
        tiempoFinal = microsegundos();
        count++;
    } while(tiempoFinal - tiempoInicial <= 500);
    return((tiempoFinal - tiempoInicial)/count);
}

/*--------------------------------------------------------------------------------------------------------------------*/

/* Función para mostrar la tabla de las cotas de Fib1 */

void cotasFib1(int numero) {
    printf("%8d|%15lf|%22lf|                 |%22lf|\n", numero, tiempoFib1(numero - 1), tiempoFib1(numero - 1) /pow(1.1, numero), tiempoFib1(numero - 1) / pow(2, numero));
}

/* Función para mostrar la tabla de las cotas de Fib2 */

void cotasFib2(int numero) {
    printf("%8d|%15lf|%22lf|                 |%22lf|\n", numero, tiempoFib2(numero - 1), tiempoFib2(numero - 1) / pow(numero, 0.8), tiempoFib2(numero - 1) / (numero * log10(numero)));
}

/* Función para mostrar la tabla de las cotas de Fib3 */

void cotasFib3(int numero) {
    printf("%8d|%15lf|%22lf|                 |%22lf|\n", numero, tiempoFib3(numero - 1), tiempoFib3(numero - 1) / sqrt(log10(numero)), tiempoFib3(numero - 1) / pow(numero, 0.5));
}

/*--------------------------------------------------------------------------------------------------------------------*/

/* Función que imprime una tabla con el último número de la sucesión de fibonacci según una entrada. */

void medicionDeTiempos() {
    int valoresParaFib1[] = {2, 4, 8, 16, 32};
    int valoresParaFib2y3[] = {1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    /* En cada bucle se mide el tiempo antes y después de ejecutar la sucesión de Fibonacci para ver cuanto tarda cada algoritmo */

    for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        printf("Tiempo de fib1 para n = %10d: %15lf us\n", valoresParaFib1[i], tiempoFib1(valoresParaFib1[i]));
    }

    printf("\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        printf("Tiempo de fib2 para n = %10d: %15lf us\n", valoresParaFib2y3[i], tiempoFib2(valoresParaFib2y3[i]));
    }

    printf("\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        printf("Tiempo de fib3 para n = %10d: %15lf us\n", valoresParaFib2y3[i], tiempoFib3(valoresParaFib2y3[i]));
    }
}

void tablaCotas() {
    int valoresParaFib1[] = {2, 4, 8, 16, 32};
    int valoresParaFib2y3[] = {1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};


    printf("\n    n\t|\t  fb1(n)\t|\tCota subestimada   |   Cote Exacta   |\tCota Sobreestimada\t|\n");
    printf("--------|---------------|----------------------|-----------------|----------------------|\n");

    for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        cotasFib1(valoresParaFib1[i]);
    }

    printf("\n");

    printf("\n    n\t|\t  fb1(n)\t|\tCota subestimada   |   Cote Exacta   |\tCota Sobreestimada\t|\n");
    printf("--------|---------------|----------------------|-----------------|----------------------|\n");


    for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        cotasFib2(valoresParaFib2y3[i]);
    }

    printf("\n");

    printf("\n    n\t|\t  fb1(n)\t|\tCota subestimada   |   Cote Exacta   |\tCota Sobreestimada\t|\n");
    printf("--------|---------------|----------------------|-----------------|----------------------|\n");


    for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        cotasFib3(valoresParaFib2y3[i]);
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

void test(int n) {
    printf("\n    n\t|\t  fb1(n)\t|\t fb2(n) \t|  \t fb3(n) \t|\n");
    printf("--------|---------------|---------------|---------------|\n");

    for(int i = 1; i <= n; i++) {
        printf("%8d|%15d|%15d|%15d|\n", i, fib1(i - 1), fib2(i - 1), fib3(i - 1));
    }

    printf("\n");
    medicionDeTiempos();
    tablaCotas();
}