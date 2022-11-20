/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "monticulo.h"
#include "funcionesAuxiliares.h"

int main() {
    monticulo m;
    inicializar_semilla(); // Inicializamos la seed para obtener números aleatorios.

    int arrayNumbers[TAM];
    aleatorio(arrayNumbers, TAM);
    crear_monticulo(arrayNumbers, TAM, &m);

    return 0;
}

