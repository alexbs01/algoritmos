/*
 * Login:
 *
 *
 * */

#include <stdio.h>
#include "funcionesFibonacci.h"

int main() {
    int n; // Número de elementos de la sucesión de Fibonacci que se verán como una tabla.

    printf("Introduzca hasta que numero n quiere ver la sucesion de fibonacci: ");
    scanf("%d", &n);

    test(n);
    return 0;
}
