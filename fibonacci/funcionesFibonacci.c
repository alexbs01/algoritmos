//
// Created by alexb on 15/09/2022.
//

#include "funcionesFibonacci.h"
#include <math.h>

/* Algoritmo fib1: O(Φ^n), Φ = (1+√5)/2 */
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
countTemp tiempoFib1(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 1;

    do {
        tiempoInicial = microsegundos();
        for(int i = 0; i < count; i++) {
            fib1(numero);
        }
        tiempoFinal = microsegundos();

        if(tiempoFinal - tiempoInicial <= 500) { // Comprobamos si tardó menos de 500 us en ejecutarse
            count *= 10;    // Si es el caso se vuelve a ejecutar multiplicando el número de iteraciones por 10
        }
    } while(tiempoFinal - tiempoInicial <= 500);

    struct chrono c = {count, ((tiempoFinal - tiempoInicial) / count)};

    return c; // Retornamos la media de lo que tardó
}

/* Función para calcular cuanto tarda Fib2 */
countTemp tiempoFib2(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 1;

    do {
        tiempoInicial = microsegundos();
        for(int i = 0; i < count; i++) {
            fib2(numero);
        }
        tiempoFinal = microsegundos();

        if(tiempoFinal - tiempoInicial <= 500) {
            count *= 10;
        }
    } while(tiempoFinal - tiempoInicial <= 500);

    struct chrono c = {count, ((tiempoFinal - tiempoInicial) / count)};

    return c; // Retornamos la media de lo que tardó
}

/* Función para calcular cuanto tarda Fib3 */
countTemp tiempoFib3(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 1;

    do {
        tiempoInicial = microsegundos();
        for(int i = 0; i < count; i++) {
            fib3(numero);
        }
        tiempoFinal = microsegundos();

        if(tiempoFinal - tiempoInicial <= 500) {
            count *= 10;
        }
    } while(tiempoFinal - tiempoInicial <= 500);

    struct chrono c = {count, ((tiempoFinal - tiempoInicial) / count)};

    return c; // Retornamos la media de lo que tardó
}

/*--------------------------------------------------------------------------------------------------------------------*/

/* Función para mostrar la tabla de las cotas de Fib1 */

void cotasFib1(int n) {

    double tiempoFib = tiempoFib1(n).temp;
    int iteraciones = tiempoFib1(n).count;
    double cotaSubestimada = tiempoFib1(n).temp / pow(1.1, n);
    double cotaAjustada = tiempoFib1(n).temp / pow(((1+sqrt(5)) / 2), n);
    double cotaSobreestimada = tiempoFib1(n).temp / pow(2, n);

    printf("%10d| \t\t%6d\t   |\t %15lf|    %22lf|  %17lf|\t  %22lf|\n", n, iteraciones, tiempoFib, cotaSubestimada, cotaAjustada, cotaSobreestimada);
}

/* Función para mostrar la tabla de las cotas de Fib2 */

void cotasFib2(int n) {
    double tiempoFib = tiempoFib2(n).temp;
    int iteraciones = tiempoFib2(n).count;
    double cotaSubestimada = tiempoFib2(n).temp / pow(n, 0.8);
    double cotaAjustada = tiempoFib2(n).temp / n;
    double cotaSobreestimada = tiempoFib2(n).temp / (n * log10(n));

    printf("%10d| \t\t%6d\t   |\t %15lf|    %22lf|  %17lf|\t  %22lf|\n", n, iteraciones, tiempoFib, cotaSubestimada, cotaAjustada , cotaSobreestimada);
}

/* Función para mostrar la tabla de las cotas de Fib3 */

void cotasFib3(int n) {
    double tiempoFib = tiempoFib3(n).temp;
    int iteraciones = tiempoFib3(n).count;
    double cotaSubestimada = tiempoFib3(n).temp / sqrt(log10(n));
    double cotaAjustada = tiempoFib3(n).temp / log10(n);
    double cotaSobreestimada = tiempoFib3(n).temp / pow(n, 0.5);

    printf("%10d| \t\t%6d\t   |\t %15lf|    %22lf|  %17lf|\t  %22lf|\n", n, iteraciones, tiempoFib, cotaSubestimada, cotaAjustada, cotaSobreestimada);
}

/*--------------------------------------------------------------------------------------------------------------------*/

/* Función que imprime una tabla con el último número de la sucesión de fibonacci según una entrada. */

/* Muestra las tablas de las cotas subestimadas, ajustadas y sobreestimadas */
void tablaCotas() {
    int valoresParaFib1[] = {2, 4, 8, 16, 32};
    int valoresParaFib2y3[] = {1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};


    printf("\n    n\t  | Media de x iteraciones |\t  TiempoFib1(n)\t|\tCota subestimada   |   Cota Ajustada   |\tCota Sobreestimada\t|\n");
    printf("----------|------------------------|--------------------|--------------------------|-------------------|--------------------------------|\n");

    for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        cotasFib1(valoresParaFib1[i]);
    }

    printf("\n");

    printf("\n    n\t  | Media de x iteraciones |\t  TiempoFib1(n)\t|\tCota subestimada   |   Cota Ajustada   |\tCota Sobreestimada\t|\n");
    printf("----------|------------------------|--------------------|--------------------------|-------------------|--------------------------------|\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        cotasFib2(valoresParaFib2y3[i]);
    }

    printf("\n");

    printf("\n    n\t  | Media de x iteraciones |\t  TiempoFib1(n)\t|\tCota subestimada   |   Cota Ajustada   |\tCota Sobreestimada\t|\n");
    printf("----------|------------------------|--------------------|--------------------------|-------------------|--------------------------------|\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        cotasFib3(valoresParaFib2y3[i]);
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

void test(int n) {
    printf("\n\tn\t|\t fib1(n) \t|\t fib2(n) \t|\t fib3(n) \t|\n");        // ESTO ESTA NO TOCAR
    printf("----------------|-----------------------|-----------------------|-----------------------|\n"); // ESTO ESTA NO TOCAR

    for(int i = 1; i <= n; i++) {
        printf("\t%8d|\t %15d|\t %15d|\t %15d|\n", i, fib1( i - 1), fib2(i - 1), fib3( i - 1)); // ESTO ESTA NO TOCAR
    }
    printf("\n");

   // medicionDeTiempos();
    tablaCotas();
}