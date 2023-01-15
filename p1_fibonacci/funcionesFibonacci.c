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
chrono tiempoFib(int n, int (*tipoFib)(int n)) {
    chrono c;
    double tInicial, tFinal, tiempoTotal;
    int cnt = 1, i;

    tInicial = microsegundos();
    tipoFib(n);
    tFinal = microsegundos();
    tiempoTotal = tFinal - tInicial;

    while(tiempoTotal <= 500) {
        cnt *= 10;

        tInicial = microsegundos();
        for(i = 0; i < cnt; i++) {
            tipoFib(n);
        }
        tFinal = microsegundos();
        tiempoTotal = tFinal - tInicial;
    }

    c.count = cnt;
    c.temp = tiempoTotal / cnt;

    return c; // Devolvemos la media de lo que tardo y el número de veces que repetimos
}

/*--------------------------------------------------------------------------------------------------------------------*/

/* Función para mostrar la tabla de las cotas de Fib1 */

void cotasFib1(int n) {
    chrono c;

    c = tiempoFib(n, fib1);

    double tiempoFib = c.temp;
    int iteraciones = c.count;
    double cotaSubestimada = c.temp / pow(1.1, n);
    double cotaAjustada = c.temp / pow(((1+sqrt(5)) / 2), n);
    double cotaSobreestimada = c.temp / pow(2, n);

    printf("%11d|%15d|%15lf|%23lf|%23lf|%23lf|\n",
           n, iteraciones, tiempoFib, cotaSubestimada, cotaAjustada, cotaSobreestimada);
}

/* Función para mostrar la tabla de las cotas de Fib2 */

void cotasFib2(int n) {
    chrono c;

    c = tiempoFib(n, fib2);

    double tiempoFib = c.temp;
    int iteraciones = c.count;
    double cotaSubestimada = c.temp / pow(n, 0.8);
    double cotaAjustada = c.temp / n;
    double cotaSobreestimada = c.temp / (n * log10(n));

    printf("%11d|%15d|%15lf|%23lf|%23lf|%23lf|\n",
           n, iteraciones, tiempoFib, cotaSubestimada, cotaAjustada, cotaSobreestimada);
}

/* Función para mostrar la tabla de las cotas de Fib3 */

void cotasFib3(int n) {
    chrono c;

    c = tiempoFib(n, fib3);

    double tiempoFib = c.temp;
    int iteraciones = c.count;
    double cotaSubestimada = c.temp / sqrt(log10(n));
    double cotaAjustada = c.temp / log10(n);
    double cotaSobreestimada = c.temp / pow(n, 0.5);

    printf("%11d|%15d|%15lf|%23lf|%23lf|%23lf|\n",
           n, iteraciones, tiempoFib, cotaSubestimada, cotaAjustada, cotaSobreestimada);
}

/*--------------------------------------------------------------------------------------------------------------------*/

/* Función que imprime una tabla con el último número de la sucesión de fibonacci según una entrada. */

/* Muestra las tablas de las cotas subestimadas, ajustadas y sobreestimadas */
void tablaCotas() {
    int valoresParaFib1[] = {2, 4, 8, 16, 32};
    int valoresParaFib2y3[] = {1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    printf("   [N]\t\t[I]\t\t[T]\t\t   [T/CSub]\t\t[T/CAjus]\t"
           "\t[T/CSobre]\t\n\n");

    for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        cotasFib1(valoresParaFib1[i]);
    }

    printf("\n");

    printf("   [N]\t\t[I]\t\t[T]\t\t   [T/CSub]\t\t[T/CAjus]\t"
           "\t[T/CSobre]\t\n\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        cotasFib2(valoresParaFib2y3[i]);
    }

    printf("\n");

    printf("   [N]\t\t[I]\t\t[T]\t\t   [T/CSub]\t\t[T/CAjus]\t"
           "\t[T/CSobre]\t\n\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        cotasFib3(valoresParaFib2y3[i]);
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

void test(int n) {
    printf("\n\tn|\tfib1(n)|\tfib2(n)|\tfib3(n)|\n");
    printf("---------|-------------|---------------|---------------|\n");

    for(int i = 0; i <= n; i++) {
        printf("%9d|%13d|%15d|%15d|\n", i, fib1( i), fib2(i), fib3( i));
    }
}