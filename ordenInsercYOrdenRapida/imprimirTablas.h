/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef ORDENINSERCYORDENRAPIDA_IMPRIMIRTABLAS_H
#define ORDENINSERCYORDENRAPIDA_IMPRIMIRTABLAS_H

#include "medicionDeTiempos.h"
#include "generacionNumeros.h"
#include "math.h"
#include "algoritmosOrdenacion.h"

void tablaInsercionAl(int inicialSize, int totalSize, int maxTime);
void tablaInsercionAs(int inicialSize, int totalSize, int maxTime);
void tablaInsercionDes(int inicialSize, int totalSize, int maxTime);

void tablaOrdRapidaAl(int inicialSize, int totalSize, int maxTime);
void tablaOrdRapidaAs(int inicialSize, int totalSize, int maxTime);
void tablaOrdRapidaDes(int inicialSize, int totalSize, int maxTime);


#endif //ORDENINSERCYORDENRAPIDA_IMPRIMIRTABLAS_H
