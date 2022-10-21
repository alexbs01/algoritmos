/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef ORDENINSERCYORDENRAPIDA_GENERACIONNUMEROS_H
#define ORDENINSERCYORDENRAPIDA_GENERACIONNUMEROS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void inicializar_semilla();
void aleatorio(int v[], int n); // Se generan número pseudo aleatorios entre -n y +n.
void ascendente(int v[], int n);
void descendente(int v[], int n);

#endif //ORDENINSERCYORDENRAPIDA_GENERACIONNUMEROS_H
