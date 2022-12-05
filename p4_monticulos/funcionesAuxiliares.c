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


void visualizar(monticulo m) {
    int i;

    if(!monticulo_vacio(m)) {
        for(i = 0; i <= m.ultimo; i++){
            printf("%d ", m.vector[i]);
        }
    } else {
        printf("().");
    }
}

int altura(int a) {
    return (int) log2(a) + 1;
}

bool esUltimaAltura(int a, monticulo M) {
    return (altura(a) == altura(M.ultimo));
}

void hijosYpadre(monticulo m) {
    int i;

    for(i = 0; i <= m.ultimo; i++) {
        printf("\nNodo %d: %d", i, m.vector[i]);

        if(!esUltimaAltura(i, m) && (2 * i + 1) <= m.ultimo) {
            printf("\n\tHijo Izquierdo: %d", m.vector[2 * i + 1]);
        } else {
            printf("\n\tNo tiene hijo izquierdo.");
        }

        if(!esUltimaAltura(i, m) && (2 * i + 2) <= m.ultimo) {
            printf("\n\tHijo Derecho: %d", m.vector[2 * i + 2]);
        } else {
            printf("\n\tNo tiene hijo derecho.");
        }
    }
}

void test() {
    //int nodosAInsertar[] = {1, 5, 3, 7, 9, 2};   //nodosAInsertar[] = {3, 1 ,2, 5, 4, 5}; Preguntar a Kike, dos 5 bb
    int nodosAInsertar[] = {9, -1, 0, -6, 5, 7, -3, -4, 2, 1};   //nodosAInsertar[] = {3, 1 ,2, 5, 4, 5}; Preguntar a Kike, dos 5 bb
    int i, j, size = sizeof(nodosAInsertar) / sizeof(nodosAInsertar[0]) - 1;
    monticulo m;

    printf("Array a insertar en el monticulo: ");
    for(i = 0; i <= size; i++){
        printf("%d ", nodosAInsertar[i]);
    }

    crear_monticulo(nodosAInsertar, size, &m);
    printf("\nNodos del monticulo ordenado: "); visualizar(m);
    printf("\nNúmero de nodos (Empezamos a contar en cero): %d", m.ultimo);
    printf("\nAltura del montículo: %d", altura((m.ultimo)));
    hijosYpadre(m);

    printf("\nEliminamos el mayor del monticulo: %d", eliminar_mayor(&m));
    printf("\nNodos del monticulo ordenado: "); visualizar(m);
    printf("\nNúmero de nodos (Empezamos a contar en cero): %d", m.ultimo);

    hijosYpadre(m);

    printf("\nBorro todos nodos liberando la memoria: ");

    j = m.ultimo;
    for(i = 0; i <= j; i++) {
        printf("%d ",eliminar_mayor(&m));
    }

    printf("\nNodo vacío: "); visualizar(m);
    printf("\nNúmero de nodos (Empezamos a contar en cero): %d", m.ultimo);
}


chrono tardanzaCrear(int array[], int size, monticulo *m,
                     void (*tipoArray)(int array[], int size)) {
    chrono c;
    double tInicial, tFinal, tiempo, ta, tb;
    int cnt = 1, i;

    tipoArray(array, size);
    tInicial = microsegundos();
    crear_monticulo(array, size, m);
    tFinal = microsegundos();
    tiempo = tFinal - tInicial;

    while(tiempo < 500) {
        cnt *= 10;

        tInicial = microsegundos();
        for(i = 0; i <= cnt; i++) {
            tipoArray(array, size);
            crear_monticulo(array, size, m);
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
    double tInicial, tFinal, tiempo, ta, tb;
    int cnt = 1, i;

    tipoArray(array, size);

    tInicial = microsegundos();
    ord_monticulo(array, size);
    tFinal = microsegundos();

    tiempo = tFinal - tInicial;

    while(tiempo < 500) {
        cnt *= 10;

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

        tiempo = ta - tb;
    }

    c.count = cnt;
    c.tiempoMedio = tiempo/cnt;

    return c;
}

void calentarProcesador(int inicialSize, int maxSize) {
    int actualSize = inicialSize;
    int arrayNumbers[maxSize];
    monticulo m;

    do{
        tardanzaCrear(arrayNumbers, actualSize, &m, ascendente);

        actualSize *= 2;
    } while(actualSize <= maxSize); //&& dato.tiempoMedio <= maxTime
}


void tabla(int inicialSize, int maxSize) {
    int actualSize = inicialSize;
    int arrayNumbers[maxSize];
    chrono c;
    monticulo m;
    double TSu, TA, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        c = tardanzaCrear(arrayNumbers, actualSize - 1, &m, ascendente);

        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TA = c.tiempoMedio / actualSize;
        TSo = c.tiempoMedio /  pow(actualSize, 1.1);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\n",
               actualSize, c.count , c.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}


void test2() {
    int nodosAInsertar[20];// = {2, 36, 5, 3, 1, 80, 10};
    aleatorio(nodosAInsertar, 20);
    int i, size = sizeof(nodosAInsertar) / sizeof(nodosAInsertar[0]) - 1;

    printf("Array antes de ord_monticulo: ");
    for(i = 0; i <= size; i++){
        printf("%d ", nodosAInsertar[i]);
    }

    ord_monticulo(nodosAInsertar, size);

    printf("\nArray después de ord_monticulo: ");
    for(i = 0; i <= size; i++){
        printf("%d ", nodosAInsertar[i]);
    }
}


void tablaOrdAscendente(int inicialSize, int maxSize) {
    int actualSize = inicialSize;
    int arrayNumbers[maxSize];
    chrono c;
    double TSu, TA, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos ordenados ascendentemente en ");
    printf("ord_monticulo.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        c = tardanzaOrd(arrayNumbers, actualSize - 1, ascendente);

        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TA = c.tiempoMedio / actualSize;
        TSo = c.tiempoMedio /  pow(actualSize, 1.1);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\n",
               actualSize, c.count , c.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}

void tablaOrdDescendente(int inicialSize, int maxSize) {
    int actualSize = inicialSize;
    int arrayNumbers[maxSize];
    chrono c;
    double TSu, TA, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos ordenados descendentemente en ");
    printf("ord_monticulo.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        c = tardanzaOrd(arrayNumbers, actualSize - 1, descendente);

        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TA = c.tiempoMedio / actualSize;
        TSo = c.tiempoMedio /  pow(actualSize, 1.1);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\n",
               actualSize, c.count , c.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}

void tablaOrdAleatorio(int inicialSize, int maxSize) {
    int actualSize = inicialSize;
    int arrayNumbers[maxSize];
    chrono c;
    double TSu, TA, TSo;

    printf("\n\n****************************************************\n");
    printf("Inserción de n elementos ordenados aleatoriamente en ");
    printf("ord_monticulo.\n\n");
    printf("  [N]\t\t[I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        c = tardanzaOrd(arrayNumbers, actualSize - 1, aleatorio);

        TSu = c.tiempoMedio / pow(actualSize, 0.9);
        TA = c.tiempoMedio / actualSize;
        TSo = c.tiempoMedio /  pow(actualSize, 1.1);

        printf("%8d\t%4d\t%15lf\t %14lf\t%14lf\t%14lf\n",
               actualSize, c.count , c.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime

    printf("\n");
}