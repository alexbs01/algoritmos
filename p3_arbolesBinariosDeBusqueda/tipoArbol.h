/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#ifndef P3_ARBOLESBINARIOSDEBUSQUEDA_TIPOARBOL_H
#define P3_ARBOLESBINARIOSDEBUSQUEDA_TIPOARBOL_H

#include <stdlib.h>
#include <stdio.h>

typedef struct nodo *posicion;
typedef struct nodo *arbol;


arbol insertar(int e, arbol T); // Inserta una clave.

arbol crearArbol(); // Inicializa un árbol binario.
int esArbolVacio(arbol T); // Comprueba si el árbol está vació.
posicion buscar(int pos, arbol T); // Busca un elemento.
arbol eliminarArbol(arbol T); // Elimina de forma recursiva el árbol.

posicion hijoIzquierdo(arbol T); // Retorna el hijo izquierdo.
posicion hijoDerecho(arbol T); // Devuelve el hijo derecho.
int elemento(posicion pos); // Devuelve el dato de la posición introducida.
int numeroRepeticiones(posicion pos); // Retorna cuantas veces se repite el elemento dado para para.

int comp(int a, int b); // Aux. de altura(): Retorna cuál de las dos entradas es superior a la otra para.

int altura(arbol); // Retorna la altura del árbol.
void visualizar(arbol T);

#endif //P3_ARBOLESBINARIOSDEBUSQUEDA_TIPOARBOL_H
