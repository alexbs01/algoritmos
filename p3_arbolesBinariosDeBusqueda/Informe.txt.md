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
El objetivo de esta práctica es **calcular la complejidad computacional**, de 
forma empírica, de la inserción y búsqueda de números enteros (aleatorios) en 
un árbol vacío. Esto se realizará a partir de la medición de tiempos.  

La **reserva** y **liberado** de memoria se comprobó con **valgrind** para 
verificar que toda la memoria reservada para los nodos tiene su posterior free.  

Los **tiempos** de inserción y búsqueda según el tamaño del árbol generado 
aleatoriamente de las siguientes tablas estarán en **microsegundos (us)**, 
además también se dará una cota subestimada, ajustada y sobreestimada para 
cada tiempo calculado. 

Cuando **un tiempo es inferior a 500 microsegundos, no se mostrará en 
la tabla**. En el enunciado se empieza a partir de N = 8000, ya que es a partir
de ese N cuando el tiempo da mayor que 500 us, pero en la máquina empleada por 
este grupo a veces para n = 2000 o para n = 4000 hay tiempos mayores que 500 us. 
Esto significa que las tablas que hay en el informe empiezan en n = 8000, pero 
algunas veces se imprimen las filas de n = 2000 y n = 4000 al ejecutar el 
código. Como en las tablas solo hay tiempos superiores a 500 us, ningún dato 
mostrado fue obtenido a partir de la repetición de un bucle, si no que fue 
medido de forma directa.  

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
aleatorios en insertarse en un árbol vacío y los tiempos respectivamente de 
búsqueda de N números aleatorios sobre esos árboles previamente creados.  

-----

## Inserción de n elementos:

|     [N] |           [T] |  [T/CSub] | [T/CAjus] | [T/CSobre] |
|--------:|--------------:|----------:|----------:|-----------:|
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

**No hay anomalías**.  

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

Con esta tabla vemos que la cota ajustada está tendiendo a 0.015.  

**No hay anomalías**.  

## Conclusiones

### Complejidades

Se calcularon a través de hacer una **nube de puntos** con las coordenadas 
de *(N, Tiempo)* múltiples veces, y calcular una **función exponencial** que 
pase lo más cerca posible por todos los puntos.  

#### Inserción
- **Caso medio**: O(pow(n, 1.28))

#### Búsqueda
- **Caso medio**: O(pow(n, 1.25))

Tras el análisis de los tiempos de inserción y búsqueda, podemos concluir que 
por lo general, **la inserción es más rápida**.  

La inserción de n elementos en un árbol vacío, lleva consigo hacer una reserva 
de memoria para la creación de los nodos, esta reserva es relativamente 
costosa. Pero no es lo suficientemente lenta como para ser más lento que la 
búsqueda.

La búsqueda de n elementos sobre un árbol de n elementos, se realiza con un 
array de n números aleatorios, que pueden coincidir con los que hay en el árbol 
o no. El caso en el que un elemento del array no esté en el árbol, hará que se 
tenga que bajar hasta una hoja, lo cual tiene un coste de tiempo superior al de
reservar memoria y crear nodos para después insertarlos.  
