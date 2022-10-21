/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "medicionDeTiempos.h"


void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int v [], int n) {
    int i, m = 2 * n + 1;

    for(i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}

void ascendente(int v [], int n) {
    int i;

    for(i = 0; i < n; i++) {
        v[i] = i;
    }
}

void descendente(int v[], int n) {
    int i;

    for(i = 0; i < n; i++) {
        v[i] = n - i;
    }
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

chrono tardanza(int array[], int size,
                void (*tipoArray)(int v [], int n),void (*tipoOrd)(int v [], int n)) {
    double tInicial, tFinal, ta, tb, Tiempo;
    int count = 1, i;
    chrono c = {count, (Tiempo / count)};

    tipoArray(array, size);
    tInicial = microsegundos();
    tipoOrd(array, size);
    tFinal = microsegundos();
    Tiempo = tFinal - tInicial;

    while(Tiempo <= 500) {
        tInicial = microsegundos();
        for(i = 0; i <= count; i++) {
            tipoArray(array, size);
            tipoOrd(array, size);
        }
        tFinal = microsegundos();
        ta = tFinal - tInicial;

        tInicial = microsegundos();
        for(i = 0; i <= count; i++) {
            tipoArray(array, size);
        }
        tFinal = microsegundos();
        tb = tFinal - tInicial;

        Tiempo = ta - tb;

       if(Tiempo <= 500) count *= 10;
    }

    c.count = count;
    c.tiempoMedio = Tiempo / count;
    return c;
}
