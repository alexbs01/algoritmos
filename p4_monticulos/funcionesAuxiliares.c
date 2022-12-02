
/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "funcionesAuxiliares.h"
#include "monticulo.h"
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

/**
 * Pasándole un array v, se rellenará con una cantidad n de elementos ordenados
 * de forma descendente
 * @param v - Un array de enteros
 * @param n - Tamaño del array
 */
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

void visualizar(monticulo T) {
    if(!esArbolVacio(T)) {

        if(!esArbolVacio(T->izq)) {
            printf("(");
            visualizar(T->izq);
            printf(")");
        }

        printf(" %d ", T->elem);

        if(!esArbolVacio(T->der)) {
            printf("(");
            visualizar(T->der);
            printf(")");
        }

    } else {
        printf("().");
    }
}

void test() {
    int i, nodosAInsertar[] = {3, 1 ,2, 5, 4}; //Preguntar a Kike, dos 5 bb
    monticulo M = crearArbol();
    printf("Árbol vacío: "); visualizar(T);

    printf("\n");
    printf("Altura del árbol: %d\n", altura(T));

    printf("Insertamos por este orden 3 1 2 5 4 5 al árbol vacío\n");
    for(i = 0; i < sizeof(nodosAInsertar)/ sizeof(nodosAInsertar[0]); i++) {
        M = insertar(nodosAInsertar[i], M);
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
