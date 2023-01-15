#include <stdio.h>
#include "funcionesFibonacci.h"

int main() {
    int n; // Número de entrada de las funciones de Fibonacci

    printf("Introduzca un numero para ver la sucesion de fibonacci: ");
    scanf("%d", &n);

    test(n);
    printf("\n");
    tablaCotas();
    return 0;
}