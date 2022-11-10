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
empírica, de la inserción de números enteros en un árbol vacío a partir de la medición de tiempos

Los **tiempos** de inserción y búsqueda según el tamaño del árbol generado
aleatoriamente de las siguientes tablas estarán en **microsegundo (us)**,
además también se dará una cota subestimada, ajustada y sobreestimada para
cada tiempo calculado.

Cuando **un tiempo es inferior a 500 microsegundos**, no se mostrará en
la tabla. En el enunciado se empieza a partir de N = 8000, ya que es a partir
de ese N cuando el tiempo da mayor que 500 us, pero en la máquina empleada por
este grupo a veces para n = 4000 hay tiempos mayores que 500 us. Esto significa
que las tablas que hay en el informe tendrán la fila para n = 4000 aunque haya a
veces que al ejecutar el programa no aparezcan por dar tiempos menores a 500 us.

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

|   [N]  |    [T_ins]   |    [T_bus]   |
|-------:|-------------:|-------------:|
|   4000 |   596.000000 |   604.000000 |
|   8000 |  1292.000000 |  1001.000000 |
|  16000 |  2436.000000 |  2365.000000 |
|  32000 |  5658.000000 |  5495.000000 |
|  64000 | 13949.000000 | 13123.000000 |
| 128000 | 33799.000000 | 36803.000000 |
| 256000 | 85920.000000 | 94921.000000 |

Con esta primera tabla podemos ver los tiempos que se tardan N números
aleatorios en insertarse en un árbol vacío y los tiempos respectivamente
de búsqueda de N números aleatorios sobre esos árboles previamente creados.

-----

## Inserción de n elementos:

|   [N]  |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|-------------:|---------:|----------:|-----------:|
|   4000 |   596.000000 | 0.149000 |  0.014609 |   0.002356 |
|   8000 |  1292.000000 | 0.161500 |  0.013041 |   0.001806 |
|  16000 |  2436.000000 | 0.152250 |  0.010125 |   0.001204 |
|  32000 |  5658.000000 | 0.176813 |  0.009684 |   0.000988 |
|  64000 | 13949.000000 | 0.217953 |  0.009832 |   0.000862 |
| 128000 | 33799.000000 | 0.264055 |  0.009810 |   0.000738 |
| 256000 | 85920.000000 | 0.335625 |  0.010269 |   0.000663 |

- **CSub**: N
- **CAjus**: pow(N, 1.28)
- **CSobre**: pow(N, 1.5)

Con esta tabla vemos que la cota ajustada está tendiendo a 0.010.
Hay dos anomalías, cuando N es 4000 y cuando N es 8000.

-----

## Búsqueda de n elementos:

|   [N]  |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|-------------:|---------:|----------:|-----------:|
|   4000 |   604.000000 | 0.151000 |  0.014805 |   0.002388 |
|   8000 |  1001.000000 | 0.125125 |  0.010104 |   0.001399 |
|  16000 |  2365.000000 | 0.147813 |  0.009830 |   0.001169 |
|  32000 |  5495.000000 | 0.171719 |  0.009405 |   0.000960 |
|  64000 | 13123.000000 | 0.205047 |  0.009250 |   0.000811 |
| 128000 | 36803.000000 | 0.287523 |  0.010682 |   0.000804 |
| 256000 | 94921.000000 | 0.370785 |  0.011345 |   0.000733 |

- **CSub**: N
- **CAjus**: pow(N, 1.28)
- **CSobre**: pow(N, 1.5)

Con esta tabla vemos que la cota ajustada está tendiendo a 0.010.
Hay una anomalía, cuando N es 4000.











A PARTIR DE AQUÍ HAY QUE HACER (Arriba también falta el objetivo)






























-----

## Conclusiones

### Complejidades

**Ordenación por inserción:**
- Mejor Caso (Ascendente): O(n)
- Caso promedio (Aleatorio): O(n²)
- Peor Caso (Descendente): O(n²)

**Ordenación por QuickSort:**
- Mejor Caso (Ascendente): O(n·log(n))
- Caso promedio (Descendente):  O(n·log(n))
- Peor Caso (Aleatorio):  O(n²)

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
