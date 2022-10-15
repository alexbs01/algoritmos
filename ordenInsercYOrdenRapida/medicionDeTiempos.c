/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "medicionDeTiempos.h"
#include "generacionNumeros.h"

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

chrono tardanza(int array[], int size, void (*tipoArray)(int v [], int n),
                void (*tipoOrd)(int v [], int n)) {

    double tInicial, tFinal, ta, tb, Tiempo;
    int count = 1, i;
    chrono c = {count, (Tiempo / count)};

    tipoArray(array, size);
    tInicial = microsegundos();
    tipoOrd(array, size);
    tFinal = microsegundos();
    Tiempo = tFinal - tInicial;

    while(Tiempo <= 500) {
        count *= 10;

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
    }

    c.count = count;
    c.tiempoMedio = Tiempo / count;

    return c;
}

/*chrono tiempoOrdenacionQuicksort(int array[], int size) {
    double tiempoInicial, tiempoFinal;
    int count = 1, i;
    chrono c = {count, ((tiempoFinal - tiempoInicial) / count)};

    do {
        tiempoInicial = microsegundos();
        for(i = 0; i <= count; i++) {
            ordenacionRapida(array, size);
        }
        tiempoFinal = microsegundos();

        if(tiempoFinal - tiempoInicial <= 500) {
            count *= 10;
        }

    } while(tiempoFinal - tiempoInicial <= 500);

    c.count = count;
    c.tiempoMedio = (tiempoFinal - tiempoInicial) / count;
   // printf("count: %d, tiempoMedio: %lf\n", c.count, c.tiempoMedio);

    return c;
}
*/