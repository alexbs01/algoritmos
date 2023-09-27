/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

/**
 * Estructura básica del nodo:\n
 * - elem: Almacena el valor del nodo\n
 * - num_repeticiones: Lleva el recuento de cuantas veces se insertó el mismo
 * nodo\n
 * - nodo *izq, *der: Son los hijos izquierdo y derecho del árbol
 */
struct nodo {
    int elem;
    int num_repeticiones;
    struct nodo *izq, *der;
};
typedef struct nodo *posicion;
typedef struct nodo *arbol;

#include "tipoArbol.h"

/**
 * Es una función auxiliar que se usará para facilitar la inserción de nodos
 * en los árboles
 * @param e - Crea un nodo con el elemento 'e'
 * @return Retorna un struct nodo
 */
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

/**
 * Para insertar un elemento en un árbol, se crea un árbol nuevo, idéntico
 * al T pero con un nodo extra 'e'
 * @param e - Elemento a insertar
 * @param T - Árbol en el que queremos insertar
 * @return Retorna otro árbol idéntico al T, pero con un nodo más
 */
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

/**
 * Inicializa un árbol
 * @return Para crear un arbol se inicializa con NULL
 */
arbol crearArbol() {
    return NULL;
}

/**
 * Comprueba que un árbol esté vacío
 * @param T - Árbol a comprobar
 * @return 1 si está vacío, 0 si no lo está
 */
int esArbolVacio(arbol T) {
    return (T == NULL);
}

/**
 * Busca el entero indicado en los parámetros en el árbol
 * @param pos - Entero a buscar
 * @param T - Árbol sobre el que queremos buscar
 * @return Retorna la posición del entero pos en el árbol
 */
posicion buscar(int pos, arbol T) {
    if(esArbolVacio(T)) {
        return NULL;
    } else {
        if(pos < T->elem) {
            return buscar(pos, T->izq);
        } else if (pos > T->elem) {
            return buscar(pos, T->der);
        }else {
            return T;
        }
    }
}

/**
 * Elimina todos los nodos de un árbol de forma recursiva
 * @param T - Árbol a eliminar
 * @return Deja un árbol sin nodos
 */
arbol eliminarArbol(arbol T) {
    if(!esArbolVacio(T)) {
        eliminarArbol(T->izq);
        eliminarArbol(T->der);

        free(T);
        T = NULL;
    }
    return T;
}

/**
 * Permite obtener la posición del hijo izquierdo de un árbol
 * @param T - Árbol introducido
 * @return Su hijo izquierdo
 */
posicion hijoIzquierdo(arbol T) {
    if(T != NULL) {
        return T->izq;
    }

    return NULL;
}

/**
 * Permite obtener la posición del hijo derecho de un árbol
 * @param T - Árbol introducido
 * @return Su hijo derecho
 */
posicion hijoDerecho(arbol T) {
    if(T != NULL) {
        return T->der;
    }

    return NULL;
}

/**
 * Se utiliza para saber que elemento está almacenado en el nodo p
 * @param p - Nodo de un árbol
 * @return Retorna el valor del nodo (en este caso su número)
 */
int elemento(posicion p) {
    return p->elem;
}

/**
 * Cuando se introduce varias veces el mismo nodo en el árbol, para indicar
 * que se introdujo más de una vez, existe el campo num_repeticiones que lleva
 * la cuenta de cuantas veces se introdujo cada nodo
 * @param p - Nodo de un árbol
 * @return Retorna el campo num_repeticiones del nodo indicado
 */
int numeroRepeticiones(posicion p) {
    return p->num_repeticiones;
}

/**
 * Compara 'a' con 'b' y retorna el mayor de los dos
 * @param a - Un entero a
 * @param b - Un entero b
 * @return Retorna cual de los dos números es mayor
 */
int comp(int a, int b) {
    if(a >= b) {
        return a;
    } else {
        return b;
    }
}

/**
 * Calcula la altura del árbol T, es la mayor distancia entre el nodo padre
 * y su hoja más lejana
 * @param T - Árbol del que queremos calcular la altura
 * @return Altura del árbol T, si el árbol no tienen nodos retorna -1
 */
int altura(arbol T) {
    if(esArbolVacio(T)) {
        return -1;
    } else {
        return 1 + comp(altura(hijoIzquierdo(T)), altura(hijoDerecho(T)));
    }
}

/**
 * Muestra el árbol introducido como parámetro para con un formato con
 * paréntesis que permiten diferenciar ramas y alturas fácilmente
 * @param T - Arbol para visualizar
 */
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