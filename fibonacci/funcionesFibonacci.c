//
// Created by alexb on 15/09/2022.
//

#include "funcionesFibonacci.h"

/*
función fib1 (n);
    si n<2 entonces devolver n
    sino devolver fib1(n-1) + fib1(n-2)
    fin si
fin función
*/

int fib1(int n) { // Algoritmo recursivo, el más lento de los 3
    if(n < 2) {
        return n;
    } else {
        return fib1(n - 1) + fib1(n - 2);
    }
}

/*
función fib2 (n);
    i := 1; j := 0;
    para k := 1 hasta n hacer
        j := i + j;
        i := j - i;
    fin para;
    devolver j
fin función
*/

int fib2(int n) { // Realiza un bucle intercambiando variables
    int i, j, k;
    i = 1;
    j = 0;
    for(k = 1; k <= n; k++) {
        j = i + j;
        i = j - i;
    }
    return j;
}

/*
función fib3 (n);
    i := 1; j := 0; k := 0; h := 1; t := 0
    mientras n>0 hacer
        si n es impar entonces
            t := jh;
            j := ih + jk + t;
            i := ik + t
        fin si;
        t := h^2;
        h := 2kh + t;
        k := k^2 + t;
        n := n div 2
    fin mientras;
    devolver j
fin función
*/

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

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

double tiempoFib1(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 0;
    tiempoInicial = microsegundos();
    do {
        fib1(numero);
        tiempoFinal = microsegundos();
        count++;
    } while(tiempoFinal - tiempoInicial <= 500);
    printf("Tiempo de fib1 para n = %d: %15lf us\n", numero, (tiempoFinal - tiempoInicial)/count);
    return (tiempoFinal - tiempoInicial)/count;

}

double tiempoFib2(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 0;
    tiempoInicial = microsegundos();
    do {
        fib2(numero);
        tiempoFinal = microsegundos();
        count++;
    } while(tiempoFinal - tiempoInicial <= 500);
    printf("Tiempo de fib2 para n = %d: %15lf us\n", numero, (tiempoFinal - tiempoInicial)/count);
    return (tiempoFinal - tiempoInicial)/count;

}

double tiempoFib3(int numero) {
    double tiempoInicial, tiempoFinal;
    int count = 0;
    tiempoInicial = microsegundos();
    do {
        fib3(numero);
        tiempoFinal = microsegundos();
        count++;
    } while(tiempoFinal - tiempoInicial <= 500);
    printf("Tiempo de fib3 para n = %10d: %15lf us\n", numero, (tiempoFinal - tiempoInicial)/count);
    return (tiempoFinal - tiempoInicial)/count;

}

void medicionDeTiempos() {
    int valoresParaFib1[] = {2, 4, 8, 16, 32};
    int valoresParaFib2y3[] = {1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    /* En cada bucle se mide el tiempo antes y después de ejecutar la
     * sucesión de Fibonacci para ver cuanto tarda cada algoritmo */

    /*for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        tiempoInicial = microsegundos();
        fib1(valoresParaFib1[i]);
        tiempoFinal = microsegundos();
        printf("Tiempo de fib1 para n = %d: %15lf us\n", valoresParaFib1[i], tiempoFinal - tiempoInicial);
    }*/
    for(int i = 0; i < sizeof(valoresParaFib1)/sizeof(valoresParaFib1[0]); i++) {
        tiempoFib1(valoresParaFib1[i]);
    }
    printf("\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        tiempoFib2(valoresParaFib2y3[i]);
    }

    printf("\n");

    for(int i = 0; i < sizeof(valoresParaFib2y3)/sizeof(valoresParaFib2y3[0]); i++) {
        tiempoFib3(valoresParaFib2y3[i]);
    }
}

void test(int n) {
    printf("       n\t|\tfb1(n)\t\tfb2(n)\t\tfb3(n)\n");
    printf("----------------|------------------------------------------------\n");

    for(int i = 1; i <= n; i++) {
        printf("%8d\t|%15d%15d%15d\n", i, fib1(i - 1), fib2(i - 1), fib3(i - 1));
    }

    printf("\n");
    medicionDeTiempos();
}