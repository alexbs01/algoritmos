/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "funcionesAuxiliares.h"
#include "monticulo.h"

#define INICIAL_SIZE 500
#define MAX_SIZE 512000

/**
 * Inicializa una seed para poder utilizar la función rand() correctamente
 */
void inicializar_semilla() {
    srand(time(NULL));
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}


/**
 * Pasándole un array v, se rellenará con una cantidad n de elementos ordenados
 * de forma ascendente
 * @param v - Un array de enteros
 * @param n - Tamaño del array
 */
void ascendente(int v [], int n) {
    int i;

    for(i = 0; i <= n; i++) {
        v[i] = i;
    }
}

/**
 * Pasándole un array v, se rellenará con una cantidad n de elementos ordenados
 * de forma descendente
 * @param v - Un array de enteros
 * @param n - Tamaño del array
 */
void descendente(int v[], int n) {
    int i;

    for(i = 0; i <= n; i++) {
        v[i] = n - i;
    }
}

/**
 * Pasándole un array v, se rellenará con una cantidad n de elementos aleatorios
 * @param v - Un array de enteros
 * @param n - Tamaño del array
 */
void aleatorio(int v [], int n) {
    int i, m = 2 * n + 1;

    for(i = 0; i <= n; i++) {
        v[i] = (rand() % m) - n;
    }
}


void visualizar(monticulo M) {
    int i;

    if(!monticulo_vacio(M)) {
        for(i = 0; i <= M.ultimo; i++){
            printf("%d ", M.vector[i]);
        }
    } else {
        printf("().");
    }
}

/**
 * Pasándole una posición de un array, calcula en que altura del montículo se
 * encuentra
 * @param a - Posición de un array
 * @return Altura del montículo en la que se encuentra el elemento del array
 */
int altura(int a) {
    return (int) log2(a) + 1;
}

/**
 * Comprueba si el elemento del array se encuentra en la última altura del árbol
 * @param a - Posición del array
 * @param M - Montúculo a comprobar
 * @return True si el nodo es una hoja, False si no lo es
 */
bool esUltimaAltura(int a, monticulo M) {
    return (altura(a) == altura(M.ultimo));
}

void hijosYpadre(monticulo M) {
    int i;

    for(i = 0; i <= M.ultimo; i++) {
        printf("\nNodo %d: %d", i, M.vector[i]);

        if(!esUltimaAltura(i, M) && (2 * i + 1) <= M.ultimo) {
            printf("\n\tHijo Izquierdo: %d", M.vector[2 * i + 1]);
        } else {
            printf("\n\tNo tiene hijo izquierdo.");
        }

        if(!esUltimaAltura(i, M) && (2 * i + 2) <= M.ultimo) {
            printf("\n\tHijo Derecho: %d", M.vector[2 * i + 2]);
        } else {
            printf("\n\tNo tiene hijo derecho.");
        }
    }
}

void test() {
    int nodosAInsertar[] = {9, -1, 0, -6, 5, 7, -3, -4, 2, 1};
    int i, j, size = sizeof(nodosAInsertar) / sizeof(nodosAInsertar[0]) - 1;
    monticulo M;

    printf("Array a insertar en el monticulo: ");
    for(i = 0; i <= size; i++){
        printf("%d ", nodosAInsertar[i]);
    }

    crear_monticulo(nodosAInsertar, size, &M);
    printf("\nNodos del monticulo ordenado: "); visualizar(M);
    printf("\nNúmero de nodos (Empezamos a contar en cero): %d", M.ultimo);
    printf("\nAltura del montículo: %d", altura((M.ultimo)));
    hijosYpadre(M);

    printf("\nEliminamos el mayor del monticulo: %d", eliminar_mayor(&M));
    printf("\nNodos del monticulo ordenado: "); visualizar(M);
    printf("\nNúmero de nodos (Empezamos a contar en cero): %d", M.ultimo);

    hijosYpadre(M);

    printf("\nBorro todos nodos liberando la memoria: ");

    j = M.ultimo;
    for(i = 0; i <= j; i++) {
        printf("%d ",eliminar_mayor(&M));
    }

    printf("\nNodo vacío: "); visualizar(M);
    printf("\nNúmero de nodos (Empezamos a contar en cero): %d", M.ultimo);
}

chrono tardanzaCrear(int array[], int size, monticulo *M,
                     void (*tipoArray)(int array[], int size)) {
    chrono c;
    double tInicial, tFinal, tiempo, ta, tb;
    int cnt = 1, i;

    tipoArray(array, size);

    tInicial = microsegundos();
    crear_monticulo(array, size, M);
    tFinal = microsegundos();

    tiempo = tFinal - tInicial;

    while(tiempo < 500) {
        cnt *= 10;

        tInicial = microsegundos();
        for(i = 0; i <= cnt; i++) {
            tipoArray(array, size);
            crear_monticulo(array, size, M);
        }
        tFinal = microsegundos();
        ta = tFinal - tInicial;

        tInicial = microsegundos();
        for(i = 0; i <= cnt; i++) {
            tipoArray(array, size);
        }
        tFinal = microsegundos();
        tb = tFinal - tInicial;

        tiempo = ta - tb;
    }

    c.count = cnt;
    c.tiempoMedio = tiempo/cnt;

    return c;
}

chrono tardanzaOrd(int array[], int size,
                   void (*tipoArray)(int array[], int size)) {
    chrono c;
    double tInicial, tFinal, tiempoTotal, ta, tb;
    int cnt = 1, i;

    tipoArray(array, size);

    tInicial = microsegundos();
    ord_monticulo(array, size);
    tFinal = microsegundos();

    tiempoTotal = tFinal - tInicial;

    while(tiempoTotal <= 500) {

        tInicial = microsegundos();
        for(i = 0; i <= cnt; i++) {
            tipoArray(array, size);
            ord_monticulo(array, size);
        }

        tFinal = microsegundos();

        ta = tFinal - tInicial;

        tInicial = microsegundos();
        for(i = 0; i <= cnt; i++) {
            tipoArray(array, size);
        }
        tFinal = microsegundos();
        tb = tFinal - tInicial;

        tiempoTotal = ta - tb;
        if(tiempoTotal <= 500) cnt *= 10;
    }

    c.count = cnt;
    c.tiempoMedio = tiempoTotal/cnt;

    return c;
}

void calentarProcesador(int inicialSize, int maxSize) {
    int actualSize = inicialSize, arrayNumbers[maxSize];
    monticulo M;

    do{
        tardanzaCrear(arrayNumbers, actualSize, &M, ascendente);

        actualSize *= 2;
    } while(actualSize <= maxSize); //&& dato.tiempoMedio <= maxTime
}


void tabla(int inicialSize, int maxSize) {
    int actualSize = inicialSize, arrayNumbers[maxSize];
    chrono c;
    monticulo M;
    double TSu, TATeorica, TAReal, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos ordenados ascendentemente en ");
    printf("crear_monticulo.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CAjusTeo]\t[T/CSub]\t[T/CAjus]\t"
           "[T/CSobre]\n\n");

    do {
        c = tardanzaCrear(arrayNumbers, actualSize - 1,
                          &M, ascendente);

        TATeorica = c.tiempoMedio / actualSize;
        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TAReal = c.tiempoMedio /  pow(actualSize, 1.0);
        TSo = c.tiempoMedio /  pow(actualSize, 1.1);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\t%14lf\n",
               actualSize, c.count, c.tiempoMedio, TATeorica ,TSu, TAReal, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}


void test2() {
    int i, nodosAInsertar1[20], nodosAInsertar2[20], nodosAInsertar3[20];
    aleatorio(nodosAInsertar1, 20);
    ascendente(nodosAInsertar2, 20);
    descendente(nodosAInsertar3, 20);
    int size1 = sizeof(nodosAInsertar1) / sizeof(nodosAInsertar1[0]) - 1;
    int size2 = sizeof(nodosAInsertar2) / sizeof(nodosAInsertar2[0]) - 1;
    int size3 = sizeof(nodosAInsertar3) / sizeof(nodosAInsertar3[0]) - 1;

    printf("\nTest para comprobar el funcionamiento de ord_monticulo:");

    printf("\n\nArray aleatorio antes de ord_monticulo: ");
    for(i = 0; i <= size1; i++){
        printf("%d ", nodosAInsertar1[i]);
    }
    ord_monticulo(nodosAInsertar1, size1 + 1);
    printf("\nArray aleatorio después de ord_monticulo: ");
    for(i = 0; i <= size1; i++){
        printf("%d ", nodosAInsertar1[i]);
    }

    printf("\n\nArray ascendente antes de ord_monticulo: ");
    for(i = 0; i <= size2; i++){
        printf("%d ", nodosAInsertar2[i]);
    }
    ord_monticulo(nodosAInsertar2, size2 + 1);
    printf("\nArray ascendente después de ord_monticulo: ");
    for(i = 0; i <= size2; i++){
        printf("%d ", nodosAInsertar2[i]);
    }

    printf("\n\nArray descendente antes de ord_monticulo: ");
    for(i = 0; i <= size3; i++){
        printf("%d ", nodosAInsertar3[i]);
    }
    ord_monticulo(nodosAInsertar3, size3 + 1);
    printf("\nArray descendente después de ord_monticulo: ");
    for(i = 0; i <= size3; i++){
        printf("%d ", nodosAInsertar3[i]);
    }
}


void tablaOrdAscendente(int inicialSize, int maxSize) {
    int actualSize = inicialSize, arrayNumbers[maxSize];
    chrono c;
    double TSu, TATeorica, TAReal, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos ordenados ascendentemente en ");
    printf("ord_monticulo.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CAjusTeo]\t[T/CSub]\t[T/CAjus]\t"
           "[T/CSobre]\n\n");

    do {
        c = tardanzaOrd(arrayNumbers, actualSize, ascendente);

        TATeorica = c.tiempoMedio / actualSize;
        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TAReal = c.tiempoMedio / pow(actualSize, 1.08);
        TSo = c.tiempoMedio /  pow(actualSize, 1.2);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\t%14lf\n",
               actualSize, c.count, c.tiempoMedio, TATeorica ,TSu, TAReal, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}

void tablaOrdDescendente(int inicialSize, int maxSize) {
    int actualSize = inicialSize, arrayNumbers[maxSize];
    chrono c;
    double TSu, TATeorica, TAReal, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos ordenados descendentemente en ");
    printf("ord_monticulo.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CAjusTeo]\t[T/CSub]\t[T/CAjus]\t"
           "[T/CSobre]\n\n");

    do {
        c = tardanzaOrd(arrayNumbers, actualSize - 1,
                        descendente);

        TATeorica = c.tiempoMedio / actualSize;
        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TAReal = c.tiempoMedio / pow(actualSize, 1.08);
        TSo = c.tiempoMedio /  pow(actualSize, 1.2);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\t%14lf\n",
               actualSize, c.count, c.tiempoMedio, TATeorica ,TSu, TAReal, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}

void tablaOrdAleatorio(int inicialSize, int maxSize) {
    int actualSize = inicialSize, arrayNumbers[maxSize];
    chrono c;
    double TSu, TATeorica, TAReal, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos ordenados aleatoriamente en ");
    printf("ord_monticulo.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CAjusTeo]\t[T/CSub]\t[T/CAjus]\t"
           "[T/CSobre]\n\n");

    do {
        c = tardanzaOrd(arrayNumbers, actualSize - 1, aleatorio);

        TATeorica = c.tiempoMedio / actualSize;
        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TAReal = c.tiempoMedio / pow(actualSize, 1.08);
        TSo = c.tiempoMedio /  pow(actualSize, 1.2);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\t%14lf\n",
               actualSize, c.count, c.tiempoMedio, TATeorica ,TSu, TAReal, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}