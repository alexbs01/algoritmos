/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "funcionesAuxiliares.h"

void test() {
    int i;
    arbol T = crearArbol();
    printf("Árbol vacÍo: ");
    visualizar(T);

    printf("\n");
    printf("Altura del árbol: %d\n", altura(T));

    printf("Insertamos por este orden 3 1 2 5 4 5 al árbol vacío\n");
    T = insertar(3, T);
    T = insertar(1, T);
    T = insertar(2, T);
    T = insertar(5, T);
    T = insertar(4, T);
    T = insertar(5, T);

    printf("Árbol: ");
    visualizar(T);
    printf(".");
    printf("\nAltura del árbol: %d\n", altura(T));

    for(i = 1; i <= 6; i++) {
        printf("Busco %d y ", i);
        if(buscar(i, T) != NULL) {
            printf("encuentro %d repetido: %d veces\n", i,
                   numeroRepeticiones(buscar(i, T)));
        } else {
            printf("no encuentro nada\n");
        }
    }

    printf("Borro todos nodos liberando la memoria:\n");
    T = eliminarArbol(T);

    printf("Árbol vacío: ");
    visualizar(T);
    printf("\nAltura del árbol: %d\n", altura(T));
}


void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int v [], int n) {
    int i, m = 2 * n + 1;

    for(i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

double tardanzaI(int array[], int size, arbol *T) {
    double tInicial, tFinal, Tiempo;
    int cnt;

    aleatorio(array, size);
    tInicial = microsegundos();
    for(cnt = 0; cnt < size; cnt++) {
        *T = insertar(array[cnt], *T);
    }
    tFinal = microsegundos();
    Tiempo = tFinal - tInicial;

    return Tiempo;
}

double tardanzaB(int array[], int size, arbol *T) {
    double tInicial, tFinal, Tiempo;
    int cnt;

    aleatorio(array, size);
    tInicial = microsegundos();
    for(cnt = 0; cnt < size; cnt++) {
        buscar(array[cnt], *T);
    }
    tFinal = microsegundos();
    Tiempo = tFinal - tInicial;

    *T = eliminarArbol(*T);

    return Tiempo;
}

void tablaIB(int inicialSize, int maxSize) {
    int actualSize = inicialSize, cnt = 0;
    int arrayNumbers[maxSize];
    double arrayI[MAX_SIZE], arrayB[MAX_SIZE];
    arbol T = crearArbol();

    printf("\n*********************************************************\n");
    printf("Tiempos en insertar y buscar n números enteros aleatorios:\n\n");
    printf("    [N]\t\t      [T_ins]\t      [T_bus]\n");

    do{
        arrayI[cnt] = tardanzaI(arrayNumbers, actualSize, &T);
        arrayB[cnt] = tardanzaB(arrayNumbers, actualSize, &T);

        if(arrayI[cnt] > 500 && arrayB[cnt] > 500) {
            printf("%8d\t%15lf\t%15lf\n",
                   actualSize, arrayI[cnt], arrayB[cnt]);
        }
        cnt++;
        actualSize *= 2;
    } while(actualSize <= maxSize); //&& dato.tiempoMedio <= maxTime

    tablaI(INICIAL_SIZE, MAX_SIZE, arrayI, arrayB);
    tablaB(INICIAL_SIZE, MAX_SIZE, arrayI, arrayB);
}

void tablaI(int inicialSize, int maxSize, const double arrayI[],
            const double arrayB[]) {

    int actualSize = inicialSize;
    int cnt = 0;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Inserción de n elementos.\n\n");
    printf("   [N]\t\t\t [T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        if(arrayI[cnt] > 500 && arrayB[cnt] > 500) {

            TSu = arrayI[cnt] / actualSize;  // Tiempo / CotaSubestimada
            TA = arrayI[cnt] / pow(actualSize, 1.28);      // Tiempo / CotaAjustada
            TSo = arrayI[cnt] /  pow(actualSize, 1.5);   // Tiempo / CotaSobreestimada

            printf("%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
                   actualSize, arrayI[cnt], TSu, TA, TSo);
        }
        cnt++;
        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime
}

void tablaB(int inicialSize, int maxSize, const double arrayI[],
            const double arrayB[]) {

    int actualSize = inicialSize;
    int cnt = 0;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Búsqueda de n elementos.\n\n");
    printf("   [N]\t\t\t [T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        if(arrayI[cnt] > 500 && arrayB[cnt] > 500) {

            TSu = arrayB[cnt] / actualSize;  // Tiempo / CotaSubestimada
            TA = arrayB[cnt] / pow(actualSize, 1.28);      // Tiempo / CotaAjustada
            TSo = arrayB[cnt] / pow(actualSize, 1.5);   // Tiempo / CotaSobreestimada

            printf("%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
                   actualSize, arrayB[cnt], TSu, TA, TSo);
        }
        cnt++;
        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime
}