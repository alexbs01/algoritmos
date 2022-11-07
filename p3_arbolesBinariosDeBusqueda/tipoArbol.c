/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

struct nodo {
    int elem;
    int num_repeticiones;
    struct nodo *izq, *der;
};
typedef struct nodo *posicion;
typedef struct nodo *arbol;

#include "tipoArbol.h"

static struct nodo *crearNodo(int e) {
    struct nodo *p = malloc(sizeof(struct nodo));
    if (p == NULL) {
        printf("memoria agotada\n"); exit(EXIT_FAILURE);
    }
    p->elem = e;
    p->num_repeticiones = 1;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

arbol insertar(int e, arbol T) {
    if (T == NULL)
        return crearNodo(e);
    else if (e < T->elem)
        T->izq = insertar(e, T->izq);
    else if (e > T->elem)
        T->der = insertar(e, T->der);
    else
        T->num_repeticiones++;
    return T;
}

arbol crearArbol() {
    return NULL;
}

int esArbolVacio(arbol T) {
    return (T == NULL);
}

posicion buscar(int pos, arbol T) {
    if(!esArbolVacio(T)) {
        if(pos == T->elem) {
            return T;
        } else if(pos < T->elem) {
            return buscar(pos, T->izq);
        } else if (pos > T->elem) {
            return buscar(pos, T->der);
        }
    } else return NULL;
}

arbol eliminarArbol(arbol T) {
    if(!esArbolVacio(T)) {
        eliminarArbol(T->izq);
        eliminarArbol(T->der);

        free(T);
        T = NULL;

        return T;
    }
}

posicion hijoIzquierdo(arbol T) {
    return T->izq;
}
posicion hijoDerecho(arbol T) {
    return T->der;
}
int elemento(posicion p) {
    return p->elem;
}
int numeroRepeticiones(posicion p) {
    return p->num_repeticiones;
}

int comp(int a, int b) {
    if(a >= b) {
        return a;
    } else {
        return b;
    }
}

int altura(arbol T) {
    if(esArbolVacio(T)) {
        return -1;
    } else {
        return 1 + comp(altura(hijoIzquierdo(T)), altura(hijoDerecho(T)));
    }
}

void visualizar(arbol T) {

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