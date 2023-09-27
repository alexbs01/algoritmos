/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "funcionesAuxiliares.h"
/**
 * Comprueba que el algoritmo del que vamos a realizar la medición de tiempos
 * y hacer el estudio, funcione perfectamente.
 */
void test() {
    int i, nodosAInsertar[] = {3, 1 ,2, 5, 4, 5};
    arbol T = crearArbol();
    printf("Árbol vacío: "); visualizar(T);

    printf("\n");
    printf("Altura del árbol: %d\n", altura(T));

    printf("Insertamos por este orden 3 1 2 5 4 5 al árbol vacío\n");
    for(i = 0; i < sizeof(nodosAInsertar)/ sizeof(nodosAInsertar[0]); i++) {
        T = insertar(nodosAInsertar[i], T);
    }

    printf("Árbol: "); visualizar(T);
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

    printf("Árbol vacío: "); visualizar(T);
    printf("\nAltura del árbol: %d\n", altura(T));
}

/**
 * Inicializa una seed para poder utilizar la función rand() correctamente
 */
void inicializar_semilla() {
    srand(time(NULL));
}

/**
 * Pasándole un array v, se rellenará con una cantidad n de elementos aleatorios
 * @param v - Un array de enteros
 * @param n - Tamaño del array
 */
void aleatorio(int v [], int n) {
    int i, m = 2 * n + 1;

    for(i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}

/**
 * Obtiene el tiempo en microsegundos del sistema, permitiendo calcular tiempos
 * @return Tiempo en microsegundos
 */
double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

/**
 * Cuenta cuanto tiempo tarda en insertar los elementos del array
 * @param array - Array de elementos aleatorios
 * @param size - Tamaño del array
 * @param T - Árbol en el que se insertarán los elementos del array
 * @return Retorna el tiempo en microsegundo que se tardó en insertar todos los
 * elementos del array
 */
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

/**
 * Cuenta cuanto tiempo tarda en buscar los elementos del array
 * @param array - Array de elementos aleatorios
 * @param size - Tamaño del array
 * @param T - Árbol en el que se buscarán los elementos del array
 * @return Retorna el tiempo en microsegundo que se tardó en buscar todos los
 * elementos del array
 */
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

/**
 * Genera una tabla con la medición de los tiempos para insertar y buscar
 * @param inicialSize - Tamaño inicial del árbol
 * @param maxSize - Tamaño final del árbol
 */
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

/**
 * Genera una tabla con los tiempos de tablaIB, pero haciendo un estudio un
 * poco más exhaustivo en los tiempo para la inserción.
 * @param inicialSize - Tamaño inicial del árbol
 * @param maxSize - Tamaño máximo del árbol
 * @param arrayI - Array con los elementos de inserción de la función tablaIB()
 * @param arrayB - Array con los elementos de búsqueda de la función tablaIB()
 */
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
            TA = arrayI[cnt] / pow(actualSize, 1.28); // Tiempo/CotaAjustada
            TSo = arrayI[cnt] /  pow(actualSize, 1.5); // Tiempo/CotaSobreestimada

            printf("%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
                   actualSize, arrayI[cnt], TSu, TA, TSo);
        }
        cnt++;
        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime
}

/**
 * Genera una tabla con los tiempos de tablaIB, pero haciendo un estudio un
 * poco más exhaustivo en los tiempo para la búsqueda.
 * @param inicialSize - Tamaño inicial del árbol
 * @param maxSize - Tamaño máximo del árbol
 * @param arrayI - Array con los elementos de inserción de la función tablaIB()
 * @param arrayB - Array con los elementos de búsqueda de la función tablaIB()
 */
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
            TA = arrayB[cnt] / pow(actualSize, 1.25); // Tiempo / CotaAjustada
            TSo = arrayB[cnt] / pow(actualSize, 1.5); // Tiempo / CotaSobreestimada

            printf("%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
                   actualSize, arrayB[cnt], TSu, TA, TSo);
        }
        cnt++;
        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime
}

/**
 * Hace que el procesador no esté en modo de ahorro de energía para que no haya
 * variaciones con los tiempos debido a esto (es un seguro para los portátiles).
 * @param inicialSize - Tamaño inicial del árbol
 * @param maxSize - Tamaño máximo del árbol
 */
void calentarProcesador(int inicialSize, int maxSize) {
    int actualSize = inicialSize, cnt = 0;
    int arrayNumbers[maxSize];
    double arrayI[100], arrayB[100];
    arbol T = crearArbol();

    do{
        arrayI[cnt] = tardanzaI(arrayNumbers, actualSize, &T);
        arrayB[cnt] = tardanzaB(arrayNumbers, actualSize, &T);

        cnt++;
        actualSize *= 2;
    } while(actualSize <= maxSize); //&& dato.tiempoMedio <= maxTime

    arrayI[1] = arrayI[0] + arrayB[0];
}