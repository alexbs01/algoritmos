/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "funcionesAuxiliares.h"

void test() {
    int i;
    arbol T = crearArbol();
    printf("\nEsta vacío: %d\n", esArbolVacio(T));

    printf("Arbol vacio: ");

    visualizar(T);

    printf("\n");
    printf("Altura: %d\n", altura(T));
    T = insertar(3, T);
    T = insertar(1, T);
    T = insertar(2, T);
    T = insertar(5, T);
    T = insertar(4, T);
    T = insertar(5, T);

    visualizar(T);

    printf("\n");
    printf("Altura: %d\n", altura(T));

    for(i = 1; i <= 6; i++) {
        printf("Busco %d y ", i);
        if(buscar(i, T) != NULL) {
            printf("encuentro %d repetido: %d veces\n", i, numeroRepeticiones(buscar(i, T)));
        } else {
            printf("no encuentro nada\n");
        }
    }

    printf("Elimino el arbol\n");
    T = eliminarArbol(T);

    printf("Arbol vacío\n");

    visualizar(T);

    printf("Altura del arbol: %d\n", altura(T));

    /*
     * arbol vacio: ()
altura del arbol: -1
inserto un 3
inserto un 1
inserto un 2
inserto un 5
inserto un 4
inserto un 5
arbol: ( 1 ( 2 )) 3 (( 4 ) 5 )
altura del arbol: 2
busco 1 y encuentro 1 repetido: 1 veces
busco 2 y encuentro 2 repetido: 1 veces
busco 3 y encuentro 3 repetido: 1 veces
busco 4 y encuentro 4 repetido: 1 veces
busco 5 y encuentro 5 repetido: 2 veces
busco 6 y no encuentro nada
borro todos nodos liberando la memoria:
arbol vacio: ()
altura del arbol: -1*/
}
