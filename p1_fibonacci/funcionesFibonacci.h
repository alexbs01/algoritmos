#ifndef FIBONACCI_FUNCIONESFIBONACCI_H
#define FIBONACCI_FUNCIONESFIBONACCI_H

#include <stdio.h>
#include <math.h>
#include <sys/time.h>


typedef struct chrono {
    int count;
    double temp;
} chrono;


//struct chrono tiempoFib3(int numero);

int fib1(int n);            // Función recursiva
int fib2(int n);            // Utiliza intercambios de variables
int fib3(int n);

chrono tiempoFib(int numero, int (*tipoFib)(int n));  // Calcula los tiempos en usando cada función de fib

void cotasFib1(int numero);     // Calcula las cotas de cada función
void cotasFib2(int numero);
void cotasFib3(int numero);

double microsegundos();     // Devuelve el tiempo en microsegundos
void tablaCotas();
void test(int n);           /* Muestra la tabla para ver que los números coincidan, y
                             * también llama la función de medición de tiempos */

#endif //FIBONACCI_FUNCIONESFIBONACCI_H
