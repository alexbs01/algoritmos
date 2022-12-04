
/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "funcionesAuxiliares.h"
#include "monticulo.h"

#define INICIAL_SIZE 500
#define MAX_SIZE 256000

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

    for(i = 0; i < n; i++) {
        v[i] = i;
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

void hijosYpadre(monticulo m) {
    int i;

    for(i = 0; i <= m.ultimo; i++) {
        printf("\nNodo %d: %d", i, m.vector[i]);

        if(0 != m.vector[2 * i + 1] && (2 * i + 1) <= m.ultimo) {
            printf("\n\tHijo Izquierdo: %d", m.vector[2 * i + 1]);
        } else {
            printf("\n\tNo tiene hijo izquierdo.");
        }

        if(0 != m.vector[2 * i + 2] && (2 * i + 2) <= m.ultimo) {
            printf("\n\tHijo Derecho: %d", m.vector[2 * i + 2]);
        } else {
            printf("\n\tNo tiene hijo derecho.");
        }
    }
}

void test() {
    //int nodosAInsertar[] = {1, 5, 3, 7, 9, 2};   //nodosAInsertar[] = {3, 1 ,2, 5, 4, 5}; Preguntar a Kike, dos 5 bb
    int nodosAInsertar[] = {1, 1, 1, 1, 1, 1, 10};   //nodosAInsertar[] = {3, 1 ,2, 5, 4, 5}; Preguntar a Kike, dos 5 bb
    int i, j, size = sizeof(nodosAInsertar) / sizeof(nodosAInsertar[0]) - 1;
    monticulo m;

    printf("Array a insertar en el monticulo: ");
    for(i = 0; i <= size; i++){
        printf("%d ", nodosAInsertar[i]);
    }

    crear_monticulo(nodosAInsertar, size, &m);
    printf("\nNodos del monticulo ordenado: "); visualizar(m);
    printf("\nNúmero de nodos (Empezamos a contar en cero): %d", m.ultimo);

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

double tardanza(int array[], int size, monticulo *m) {
    double tInicial, tFinal, Tiempo;
    int cnt;

    ascendente(array, size);
    tInicial = microsegundos();
    //// El problema de que tarde mucho creo que está aquí
    /* Para insertar 512000 elementos en el montículo, los inserta 512000 veces,
     * y el tiempo calculado es el tiempo resultante de insertar 512000 elementos
     * 512000 veces*/
    for(cnt = 0; cnt < size; cnt++) {
        crear_monticulo(array, size, m);
    }
    tFinal = microsegundos();
    Tiempo = tFinal - tInicial;

    return Tiempo;
}

void calentarProcesador(int inicialSize, int maxSize) {
    int actualSize = inicialSize, cnt = 0;
    int arrayNumbers[maxSize];
    monticulo m;

    do{
        tardanza(arrayNumbers, actualSize, &m);

        cnt++;
        actualSize *= 2;
    } while(actualSize <= maxSize); //&& dato.tiempoMedio <= maxTime
}

void tabla(int inicialSize, int maxSize) {
    int actualSize = inicialSize, cnt = 0;
    int arrayNumbers[maxSize];
    double array[MAX_SIZE];
    monticulo m;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Inserción de n elementos.\n\n");
    printf("   [N]\t\t\t [T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        array[cnt] = tardanza(arrayNumbers, actualSize, &m);

        TSu = array[cnt] / pow(actualSize, 0.5);  // Tiempo / CotaSubestimada
        TA = array[cnt] / actualSize; // Tiempo/CotaAjustada
        TSo = array[cnt] /  pow(actualSize, 1.5); // Tiempo/CotaSobreestimada

        printf("%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, array[cnt], TSu, TA, TSo);

        cnt++;
        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime
}




/**
 * Pasándole un array v, se rellenará con una cantidad n de elementos aleatorios
 * @param v - Un array de enteros
 * @param n - Tamaño del array
 */
/*
void aleatorio(int v [], int n) {
    int i, m = 2 * n + 1;

    for(i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}
*/
/**
 * Pasándole un array v, se rellenará con una cantidad n de elementos ordenados
 * de forma descendente
 * @param v - Un array de enteros
 * @param n - Tamaño del array
 */
/*
void descendente(int v[], int n) {
    int i;

    for(i = 0; i < n; i++) {
        v[i] = n - i;
    }
}
*/