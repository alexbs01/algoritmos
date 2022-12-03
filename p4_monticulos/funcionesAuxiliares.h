
/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef P4_MONTICULOS_FUNCIONESAUXILIARES_H
#define P4_MONTICULOS_FUNCIONESAUXILIARES_H

#include "monticulo.h"

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>


void inicializar_semilla();
void ascendente(int v [], int n);
double microsegundos();

void visualizar(monticulo m);
void hijosYpadre(monticulo m);
void test();

double tardanza(int array[], int size, monticulo *m);
void calentarProcesador(int inicialSize, int maxSize);
void tabla(int inicialSize, int maxSize);

//void aleatorio(int v [], int n);
//void descendente(int v[], int n);

#endif //P4_MONTICULOS_FUNCIONESAUXILIARES_H
