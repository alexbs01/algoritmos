
/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef P4_MONTICULOS_FUNCIONESAUXILIARES_H
#define P4_MONTICULOS_FUNCIONESAUXILIARES_H

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

void inicializar_semilla();
void aleatorio(int v [], int n);
void ascendente(int v [], int n);
void descendente(int v[], int n);
double microsegundos();

#endif //P4_MONTICULOS_FUNCIONESAUXILIARES_H
