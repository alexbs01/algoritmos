# Práctica 3, Algoritmos de inserción y búsqueda en árboles binarios de búsqueda

## Autores, grupo 3.1
- Alejandro Becerra Suárez, a.becerra
- Adrián Rego Criado, adrian.rego
- Miguel Cortón Debén, m.cortond

## Características de la máquina

- **Hardware**:  11th Gen Intel i7-1165G7 (8) @ 2.80 GHz (16 Gb RAM)
- **OS**: Ubuntu 22.04.1 LTS x86_64
- **Kernel**: 5.15.0-47-generic

## Introducción
El objetivo de esta práctica es calcular la complejidad computacional, de forma 
empírica, de la inserción y búsqueda de números enteros (aleatorios) en un 
árbol vacío. Esto se realiza partir de la medición de tiempos.

Los **tiempos** de inserción y búsqueda según el tamaño del árbol generado
aleatoriamente de las siguientes tablas estarán en **microsegundo (us)**,
además también se dará una cota subestimada, ajustada y sobreestimada para
cada tiempo calculado.

Cuando **un tiempo es inferior a 500 microsegundos**, no se mostrará en
la tabla. En el enunciado se empieza a partir de N = 8000, ya que es a partir
de ese N cuando el tiempo da mayor que 500 us, pero en la máquina empleada por
este grupo a veces para n = 2000 o para n = 4000 hay tiempos mayores que 500 us. 
Esto significa que las tablas que hay en el informe empiezan en n = 8000, pero 
algunas veces se imprimen las filas de n = 2000 y n = 4000 al ejecutar el 
código.


El **tamaño** de las entradas (los arrays) será de **razón 2** comenzando
en 500 (500, 1000, 2000, ...) y terminando 256000.

## Nomenclatura de las tablas
- **N**: Cantidad de números que se insertan y buscan en un árbol.
- **T_ins**: Tiempo medio de inserción en microsegundos (us).
- **T_bus**: Tiempo medio de búsqueda en microsegundos (us).
- **T**: Tiempo medio de inserción o búsqueda en microsegundos (us).
- **T/CSub**: Tiempo medio entre la Cota Subestimada.
- **T/CAjus**: Tiempo medio entre la Cota Ajustada.
- **T/CSobre**: Tiempo medio entre la Cota Sobreestimada.

## Tiempos en insertar y buscar n números enteros aleatorios:

|     [N] |       [T_ins] |       [T_bus] |
|--------:|--------------:|--------------:|
|    8000 |   1094.000000 |   1216.000000 |
|   16000 |   2514.000000 |   2852.000000 |
|   32000 |   6242.000000 |   6788.000000 |
|   64000 |  18595.000000 |  15255.000000 |
|  128000 |  36353.000000 |  37311.000000 |
|  256000 |  83593.000000 |  85713.000000 |

Con esta primera tabla podemos ver los tiempos que se tardan N números
aleatorios en insertarse en un árbol vacío y los tiempos respectivamente
de búsqueda de N números aleatorios sobre esos árboles previamente creados.

-----

## Inserción de n elementos:

|     [N] |           [T] |  [T/CSub] | [T/CAjus] | [T/CSobre] |
|--------:|--------------:|----------:|:---------:|-----------:|
|    8000 |   1094.000000 |  0.136750 |  0.011042 |   0.001529 |
|   16000 |   2514.000000 |  0.157125 |  0.010449 |   0.001242 |
|   32000 |   6242.000000 |  0.195062 |  0.010684 |   0.001090 |
|   64000 |  18595.000000 |  0.290547 |  0.013106 |   0.001148 |
|  128000 |  36353.000000 |  0.284008 |  0.010551 |   0.000794 |
|  256000 |  83593.000000 |  0.326535 |  0.009991 |   0.000645 |

- **CSub**: N
- **CAjus**: pow(N, 1.28)
- **CSobre**: pow(N, 1.5)

Con esta tabla vemos que la cota ajustada está tendiendo entre 0.01 y 0.03.

#No hay anomolías.

-----

## Búsqueda de n elementos:

|    [N] |          [T] | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|-------------:|---------:|----------:|-----------:|
|   8000 |  1216.000000 | 0.152000 |  0.016072 |   0.001699 |
|  16000 |  2852.000000 | 0.178250 |  0.015849 |   0.001409 |
|  32000 |  6788.000000 | 0.212125 |  0.015860 |   0.001186 |
|  64000 | 15255.000000 | 0.238359 |  0.014986 |   0.000942 |
| 128000 | 37311.000000 | 0.291492 |  0.015411 |   0.000815 |
| 256000 | 85713.000000 | 0.334816 |  0.014885 |   0.000662 |

- **CSub**: N
- **CAjus**: pow(N, 1.25)
- **CSobre**: pow(N, 1.5)

Con esta tabla vemos que la cota ajustada está tendiendo entre 0.015 y 0.016.

(* ERRORES P2 *)

- Mala idea hacer el test solo con aleatorio
- El objetivo de la práctica es determinar la O grande de forma empírica, para lo cual, se miden tiempos. (el objetivo no es la medición de tiempos)
- Prueba con elmentos aleatorios
    - en los 2 primeros valores el tiempo es anormalmente alto, hay 			
      una anomalia, para q eso no pase siempre eso en las 2 primeras tablas hay q hacer un 					
      precalentamiento
    - no hace falta poner tantos decimales en el tiempo de la cota
      ajustada después de la tabla

- Prueba con elementos ordenados de forma ascendente
    - los valores de la cota ajustada estan mal, valores muy malos 		
      hasta que tiende a 0.024 (q sigue siendo regular)
    - poner visualmente cuando hay anomalias (#, flecha, punto...)
      tanto en la tabla como después
- En la conclusión en la cota ajustada esta puesto que es n^2 pero en la tabla se estudia n^1.99, por lo que no es coherente, y en el caso medio lo mismo porque no se usa n·log(n)
- (CREO DIJO ESO) En el quicksort con umbral 100: había que responder que para vectores ascendentes los mejores tiempos son con umbral 100 y en ascendentes 100 y en aleatorio 10









A PARTIR DE AQUÍ HAY QUE HACER (Arriba también falta el objetivo)






























-----

## Conclusiones

### Complejidades

**Búsqueda:**
- Caso medio: O(log n)
- Caso peor: O(n)

**Inserción:**
- Caso medio: O(log n)
- Caso peor: O(n)

### Algoritmo de Ordenación por Inserción

Este algoritmo se puso a prueba con tres tipos de arrays, siendo estos con
**números al azar**, en **orden ascendente** y en **orden descendente**.

En la **ordenación** de números **al azar** obtuvo **tiempos normales**,
comparándolo con los otros dos tipos de arrays.

Sin embargo, el **mejor** de los **tiempos** se midió en la **ordenación
ascendente**. Ya que gracias al propio funcionamiento del algoritmo, es capaz
de determinar si la lista de números está ordenada o no recorriéndolo una única
vez. Este algoritmo funciona muy bien cuando es una lista de números casi
ordenados.

El **peor** de los **tiempos** se obtuvo con la colección de números en **orden
descendente**, por el mismo motivo que con el array ordenado. Por cada
iteración, solo desplaza cada número para delante o para atrás en una posición.
Por lo que, si están todos los números al revés, deberá **recorrer el
array N*N veces**.

La ordenación por inserción funciona **muy bien** con colecciones de **números
casi ordenados**, ya que en su mejor situación no existe otro algoritmo que lo
haga más rápido que este. En cambio, si se da la casualidad de que los números
estén en orden descendente este algoritmo será terriblemente lento.

-----

### Algoritmo Quicksort

Este algoritmo aparte de tener las mismas pruebas que el de ordenación por
inserción, también se le sometió con dos variantes distintas. Tener un umbral
a partir del cual se utilice la ordenación por inserción, los umbrales elegidos
fueron 1, 10 y 100. El umbral indica a partir de que tamaño de las semi-mitades,
creadas por Quicksort, se ordenarán por el anterior algoritmo aprovechando la
velocidad de ordenación de arrays casi ordenados.

#### Quicksort con umbral 1

Es Quicksort de principio a fin, no se utiliza la ordenación por inserción para
nada.

En los tres tipos de array tiene unos tiempos bastante más similares entre sí
que el anterior algoritmo. Ya que el mejor y el peor de los casos no viene
definido por el tamaño de la entrada, sino por donde cuadran los pivotes
(mejor situación en el centro del intervalo y la peor en los extremos). Con
este umbral, es más rápido con los elementos ordenados en orden ascendente,
luego en orden descendente, y por último el aleatorio.

#### Quicksort con umbral 10

Con este umbral se usará la inserción cuando las mitades tengan un tamaño de
10 elementos. De esta forma nos evitamos hacer más llamadas recursivas para tan
pocos números.

Para esta situación, los tiempos son más dispares (en especial con los
elementos de forma aleatoria), sin embargo, obtiene unos tiempos mucho mejores
que con el umbral 1. En especial para listas de elementos ordenados de menor
a mayor o viceversa.

#### Quicksort con umbral 100

De la misma forma que con las otras situaciones, se usará la ordenación por
inserción cuando las mitades tengan 100 elementos.

En vectores ordenados de forma ascendente y de forma descendente es más rápido
que con el umbral 10, pero para arrays aleatorios presenta un tiempo superior.

-----

### Conclusión final

Ambos algoritmos tienen sus ventajas y desventajas, la ordenación por inserción
es el más rápido en ordenar vectores de números ordenados o casi ordenados, y
el Quicksort con un umbral de 100 en el resto de situaciones.

Así que, si en un proyecto debemos ordenar elementos a azar, el Quicksort será
el ideal por su "propósito general" teniendo tiempos bajos y siendo más
independiente a la cantidad elementos que tiene el array. Y si hay colecciones
de elementos casi ordenados la mejor opción será el primero. Y dentro de las
tres posibilidades estudiadas del Quicksort, el mejor será con umbral 10.
