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

static struct nodo *crearNodo(int e); // Crea un nodo para
arbol insertar(int e, arbol T); // Inserta una clave
arbol crearArbol(); // Inicializa un árbol binario
int esArbolVacio(arbol T); // Comprueba si el árbol está vació
posicion buscar(int pos, arbol T); // Busca un elemento
arbol eliminarArbol(arbol T); // Elminad de forma recursiva el árbol

posicion hijoIzquierdo(arbol T); // Retorna el hijo izquierdo
posicion hijoDerecho(arbol T); // Devuelve el hijo derecho
int elemento(posicion pos); // Devuelve el dato de la poscición introducida
int numeroRepeticiones(posicion pos); // Retorna cuantas veces se repite el elemento dado
int comp(int a, int b); // Aux. de altura(): Retorna cual de las dos entradas es superior a la otra
int altura(arbol); // Retona la altura del arbol

void visualizar(arbol T);
#endif //P3_ARBOLESBINARIOSDEBUSQUEDA_TIPOARBOL_H
