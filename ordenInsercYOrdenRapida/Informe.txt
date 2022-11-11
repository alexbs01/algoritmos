# Práctica 2, Algoritmos de ordenación

## Autores, grupo 3.1
- Alejandro Becerra Suárez, a.becerra  
- Adrián Rego Criado, adrian.rego  
- Miguel Cortón Debén, m.cortond  

## Características de la máquina

- **Hardware**:  11th Gen Intel i7-1165G7 (8) @ 2.80 GHz (16 Gb RAM)  
- **OS**: Ubuntu 22.04.1 LTS x86_64  
- **Kernel**: 5.15.0-47-generic  

## Introducción
El objetivo de esta práctica es la medición de los tiempos de ordenación de dos 
algoritmos distintos. El primero es la ordenación por inserción, y el segundo 
es Quicksort. Pero este último tiene la peculiaridad de que se ejecutará de 
tres formas debido al caracter recursivo que tiene, utilizando un umbral a 
partir del cual se usará la ordenación por inserción para terminar la 
ordenación.  

Los **tiempos** de las siguientes tablas estarán en **microsegundo (us)**, 
además también se dará una cota subestimada, ajustada y sobreestimada para 
cada tiempo calculado. También cuando **un tiempo es inferior a 500 
microsegundos**, se ejecutará varias veces para calcular bien la media del 
tiempo.  

El **tamaño** de las entradas (los arrays) será de **razón 2** comenzando 
en 500 (500, 1000, 2000, ...) y terminando 128000.  

## Nomenclatura de las tablas
- **N**: Cantidad de números a ordenar.  
- **I**: Número de veces que se repite el algoritmo.  
- **T**: Tiempo medio de ejecución del algoritmo en microsegundos (us).  
- **T/CSub**: Tiempo medio entre la Cota Subestimada.  
- **T/CAjus**: Tiempo medio entre la Cota Ajustada.  
- **T/CSobre**: Tiempo medio entre la Cota Sobreestimada.  

## Mediciones de Ordenación por Inserción

### Prueba con elementos aleatorios

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 |   1 |     986.000000 | 0.013669 |  0.004197 |   0.001138 |
|   1000 |   1 |    3912.000000 | 0.015574 |  0.004192 |   0.000983 |
|   2000 |   1 |    6019.000000 | 0.006881 |  0.001624 |   0.000329 |
|   4000 |   1 |   23460.000000 | 0.007702 |  0.001593 |   0.000279 |
|   8000 |   1 |   91298.000000 | 0.008608 |  0.001561 |   0.000236 |
|  16000 |   1 |  365817.000000 | 0.009905 |  0.001574 |   0.000206 |
|  32000 |   1 | 1572026.000000 | 0.012223 |  0.001703 |   0.000193 |

- **CSub**: pow(N, 1.8)  
- **CAjus**: pow(N, 1.99)  
- **CSobre**: pow(N, 2.2) 

Con esta primera tabla podemos ver que el tiempo dividido por la cota ajustada 
está entre 0.001561 y 0.001703.  
  
-----
  
### Prueba con elementos ordenados de forma ascendente
  
|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |       8.380000 | 0.031201 |  0.008253 |   0.000403 |
|   1000 | 100 |      19.160000 | 0.038229 |  0.008718 |   0.000304 |
|   2000 |  10 |      56.400000 | 0.060305 |  0.011856 |   0.000295 |
|   4000 |  10 |     125.100000 | 0.071681 |  0.012150 |   0.000216 |
|   8000 |  10 |     212.400000 | 0.065219 |  0.009530 |   0.000121 |
|  16000 |   1 |     976.000000 | 0.160599 |  0.020233 |   0.000183 |
|  32000 |   1 |    2295.000000 | 0.202371 |  0.021981 |   0.000142 |
|  64000 |   1 |    5375.000000 | 0.253990 |  0.023784 |   0.000110 |
| 128000 |   1 |   11533.000000 | 0.292047 |  0.023578 |   0.000078 |
| 256000 |   1 |   25609.000000 | 0.347517 |  0.024189 |   0.000057 |
| 512000 |   1 |   55248.000000 | 0.401766 |  0.024110 |   0.000041 |

- **CSub**: pow(N, 0.8)  
- **CAjus**: N  
- **CSobre**: pow(N, 1.1)  

Con esta forma de ordenación, el algoritmo presenta unos tiempos muy bajos ya 
que esta es la mejor situación para la ordenación por inserción, por ello la 
cota ajusta de es lineal O(n), y el valor está entre 0.023578 y 0.024189.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 |   1 |     727.000000 | 0.010078 |  0.002908 |   0.000839 |
|   1000 |   1 |    2885.000000 | 0.011485 |  0.002885 |   0.000725 |
|   2000 |   1 |   11464.000000 | 0.013106 |  0.002866 |   0.000627 |
|   4000 |   1 |   45943.000000 | 0.015084 |  0.002871 |   0.000547 |
|   8000 |   1 |  180460.000000 | 0.017014 |  0.002820 |   0.000467 |
|  16000 |   1 |  725516.000000 | 0.019644 |  0.002834 |   0.000409 |

- **CSub**: pow(N, 1.8)  
- **CAjus**: pow(N, 2)  
- **CSobre**: pow(N, 2.2)  

Con esta prueba, se puede ver simplemente viendo los tiempos que tiene un 
tiempo de ejecución muy grande, esto es debida a que una array ordenado de 
mayor a menor es el peor caso posible para este algoritmo.  
La cota ajustada se aproxima en este algoritmo con esta ordenación entre 
0.002820 y 0.002834.  

-----

## Mediciones de Quicksort con un umbral de 1

### Prueba con elementos de aleatorios 


|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |    33.820000 | 0.092289 |  0.039354 |   0.019517 |
|   1000 |  10 |    77.600000 | 0.109613 |  0.042502 |   0.019492 |
|   2000 |  10 |   168.200000 | 0.122984 |  0.043362 |   0.018390 |
|   4000 |   1 |   676.000000 | 0.255853 |  0.082029 |   0.032172 |
|   8000 |   1 |   719.000000 | 0.140862 |  0.041066 |   0.014894 |
|  16000 |   1 |  1524.000000 | 0.154551 |  0.040971 |   0.013742 |
|  32000 |   1 |  3098.000000 | 0.162626 |  0.039202 |   0.012159 |
|  64000 |   1 |  6668.000000 | 0.181186 |  0.039715 |   0.011391 |
| 128000 |   1 | 13648.000000 | 0.191964 |  0.038262 |   0.010149 |
| 256000 |   1 | 28950.000000 | 0.210776 |  0.038202 |   0.009370 |
| 512000 |   1 | 62917.000000 | 0.237116 |  0.039078 |   0.008864 |

- **CSub**: pow(actualSize, 0.95)
- **CAjus**: pow(actualSize, 1.08715)
- **CSobre**: pow(actualSize, 1.2) 

Ahora entrando ya en la ordenación con Quicksort, vemos que a parte de ser más 
rápido con un array de elementos desordenados, la cota ajustada está 
situada entre 0.038 y 0.042.
Cuando n es 4000 hay una anomalía.

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |    19.740000 | 0.053867 |  0.022970 |   0.011392 |
|   1000 | 100 |    41.020000 | 0.057942 |  0.022467 |   0.010304 |
|   2000 |  10 |    93.000000 | 0.067999 |  0.023976 |   0.010168 |
|   4000 |  10 |   207.800000 | 0.078648 |  0.025215 |   0.009889 |
|   8000 |   1 |   790.000000 | 0.154772 |  0.045121 |   0.016365 |
|  16000 |   1 |   946.000000 | 0.095935 |  0.025432 |   0.008530 |
|  32000 |   1 |  1714.000000 | 0.089974 |  0.021689 |   0.006727 |
|  64000 |   1 |  3765.000000 | 0.102304 |  0.022425 |   0.006432 |
| 128000 |   1 |  7933.000000 | 0.111580 |  0.022240 |   0.005899 |
| 256000 |   1 | 15882.000000 | 0.115632 |  0.020957 |   0.005141 |
| 512000 |   1 | 33963.000000 | 0.127997 |  0.021095 |   0.004785 |

- **CSub**: pow(actualSize, 0.95)
- **CAjus**: pow(actualSize, 1.08715)
- **CSobre**: pow(actualSize, 1.2)

Así de primeras, los tiempos son mejores que si están puestos de forma 
aleatoria, pero aun así es más lento que el de ordenación por inserción. Y su 
cota ajustada se sitúa entre 0.021 y 0.024.
Cuando n es 8000 hay una anomalía.

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |    20.400000 | 0.055668 |  0.023738 |   0.011772 |
|   1000 | 100 |    41.650000 | 0.058832 |  0.022812 |   0.010462 |
|   2000 |  10 |    91.800000 | 0.067122 |  0.023666 |   0.010037 |
|   4000 |  10 |   222.700000 | 0.084288 |  0.027023 |   0.010599 |
|   8000 |   1 |   819.000000 | 0.160453 |  0.046778 |   0.016966 |
|  16000 |   1 |   842.000000 | 0.085388 |  0.022636 |   0.007592 |
|  32000 |   1 |  1749.000000 | 0.091812 |  0.022132 |   0.006865 |
|  64000 |   1 |  3671.000000 | 0.099750 |  0.021865 |   0.006271 |
| 128000 |   1 |  7737.000000 | 0.108824 |  0.021690 |   0.005753 |
| 256000 |   1 | 16202.000000 | 0.117962 |  0.021380 |   0.005244 |
| 512000 |   1 | 33193.000000 | 0.125095 |  0.020616 |   0.004677 |

- **CSub**: pow(actualSize, 0.95)
- **CAjus**: pow(actualSize, 1.08715)
- **CSobre**: pow(actualSize, 1.2)

Y con esta tabla vemos que la cota ajustada está entre 0.021 y 0.024.  
Hay dos anomalías, cuando n es 4000 y cuando n es 8000.

-----

## Mediciones de Quicksort con un umbral de 10

### Prueba con elementos aleatorios

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |    27.320000 | 0.074552 |  0.031790 |   0.015766 |
|   1000 |  10 |    59.400000 | 0.083905 |  0.032534 |   0.014921 |
|   2000 |  10 |   150.700000 | 0.110188 |  0.038851 |   0.016477 |
|   4000 |   1 |   601.000000 | 0.227467 |  0.072928 |   0.028602 |
|   8000 |   1 |   644.000000 | 0.126168 |  0.036783 |   0.013341 |
|  16000 |   1 |  1369.000000 | 0.138832 |  0.036804 |   0.012344 |
|  32000 |   1 |  2957.000000 | 0.155224 |  0.037418 |   0.011606 |
|  64000 |   1 |  6286.000000 | 0.170806 |  0.037440 |   0.010739 |
| 128000 |   1 | 13012.000000 | 0.183018 |  0.036479 |   0.009676 |
| 256000 |   1 | 27402.000000 | 0.199505 |  0.036159 |   0.008869 |
| 512000 |   1 | 57105.000000 | 0.215213 |  0.035468 |   0.008045 |

- **CSub**: pow(actualSize, 0.95)
- **CAjus**: pow(actualSize, 1.08715)
- **CSobre**: pow(actualSize, 1.2)

Ahora con un umbral de 10, vemos que los tiempos mejoraron y también que la
cota ajustada está entre 0.032 y 0.0368.  
Hay dos anomalías, cuando n es 2000 y cuando n es 4000.

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |    12.490000 | 0.034083 | 0.015534  |   0.007208 |
|   1000 | 100 |    27.270000 | 0.038520 | 0.014936  |   0.006850 |
|   2000 |  10 |    62.700000 | 0.045845 | 0.016164  |   0.006855 |
|   4000 |  10 |   144.800000 | 0.054804 | 0.017571  |   0.006891 |
|   8000 |  10 |   315.500000 | 0.061811 | 0.018020  |   0.006536 |
|  16000 |   1 |   595.000000 | 0.060340 | 0.015996  |   0.005365 |
|  32000 |   1 |  1281.000000 | 0.067244 | 0.016210  |   0.005028 |
|  64000 |   1 |  2726.000000 | 0.074072 | 0.016236  |   0.004657 |
| 128000 |   1 |  5574.000000 | 0.078400 | 0.015627  |   0.004145 |
| 256000 |   1 | 12265.000000 | 0.089298 | 0.016185  |   0.003970 |
| 512000 |   1 | 25340.000000 | 0.095499 | 0.015739  |   0.003570 |

- **CSub**: pow(actualSize, 0.95)
- **CAjus**: pow(actualSize, 1.08715)
- **CSobre**: pow(actualSize, 1.2) 

Para cuando está ordenados de forma ascendente podemos observar que las cota 
ajustada se sitúa entre 0.015 y 0.0162.  
Hay dos anomalías, cuando n es 4000 y cuando n es 8000.

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |    16.370000 | 0.044671 |  0.019049 |   0.009447 |
|   1000 | 100 |    33.620000 | 0.047490 |  0.018414 |   0.008445 |
|   2000 |  10 |    72.200000 | 0.052791 |  0.018613 |   0.007894 |
|   4000 |  10 |   155.200000 | 0.058740 |  0.018833 |   0.007386 |
|   8000 |   1 |   636.000000 | 0.124601 |  0.036326 |   0.013175 |
|  16000 |   1 |   649.000000 | 0.065816 |  0.017448 |   0.005852 |
|  32000 |   1 |  1379.000000 | 0.072389 |  0.017450 |   0.005412 |
|  64000 |   1 |  3207.000000 | 0.087142 |  0.019101 |   0.005479 |
| 128000 |   1 |  6381.000000 | 0.089751 |  0.017889 |   0.004745 |
| 256000 |   1 | 12859.000000 | 0.093622 |  0.016968 |   0.004162 |
| 512000 |   1 | 29450.000000 | 0.110989 |  0.018292 |   0.003658 |

- **CSub**: pow(actualSize, 0.95)
- **CAjus**: pow(actualSize, 1.08715)
- **CSobre**: pow(actualSize, 1.2)

Y para esta última forma de ordenación, vemos que la cota ajustada está
entre 0.017 y 0.019.  
Cuando n es 8000 hay una anomalía.

-----

## Mediciones de Quicksort con un umbral de 100

### Prueba con elementos aleatorios

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |    32.620000 | 0.114136 | 0.038468  |   0.015623 |
|   1000 |  10 |    71.100000 | 0.132394 | 0.039525  |   0.014517 |
|   2000 |  10 |   152.400000 | 0.151025 | 0.039936  |   0.013265 |
|   4000 |   1 |   689.000000 | 0.363366 | 0.085111  |   0.025567 |
|   8000 |   1 |   761.000000 | 0.213586 | 0.044313  |   0.012039 |
|  16000 |   1 |  1511.000000 | 0.225692 | 0.041476  |   0.010191 |
|  32000 |   1 |  3181.000000 | 0.252858 | 0.041160  |   0.009146 |
|  64000 |   1 |  6659.000000 | 0.281699 | 0.040617  |   0.008162 |
| 128000 |   1 | 14490.000000 | 0.326218 | 0.041663  |   0.007572 |
| 256000 |   1 | 30854.000000 | 0.369669 | 0.041519  |   0.006873 |
| 512000 |   1 | 63376.000000 | 0.404100 | 0.040492  |   0.006019 |

- **CSub**: pow(actualSize, 0.91)
- **CAjus**: pow(actualSize, 1.085)
- **CSobre**: pow(actualSize, 1.23)  

Ahora ya con el umbral de 100, vemos algo interesante sobre como afecta el 
umbral a los tiempos que se mencionará en la conclusión. Y la cota ajustada 
de esta prueba está entre 0.0385 y 0.0415.  

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |     5.680000 | 0.019874 |  0.006698 |   0.002720 |
|   1000 | 100 |    14.280000 | 0.026591 |  0.007938 |   0.002916 |
|   2000 | 100 |    34.250000 | 0.033941 |  0.008975 |   0.002981 |
|   4000 |  10 |    85.600000 | 0.045144 |  0.010574 |   0.003176 |
|   8000 |  10 |   188.200000 | 0.052821 |  0.010959 |   0.002977 |
|  16000 |   1 |   688.000000 | 0.102764 |  0.018885 |   0.004640 |
|  32000 |   1 |   913.000000 | 0.072575 |  0.011814 |   0.002625 |
|  64000 |   1 |  1932.000000 | 0.081730 |  0.011784 |   0.002368 |
| 128000 |   1 |  4336.000000 | 0.097618 |  0.012467 |   0.002266 |
| 256000 |   1 |  9055.000000 | 0.108490 |  0.012273 |   0.002017 |
| 512000 |   1 | 18067.000000 | 0.115199 |  0.011543 |   0.001716 |

- **CSub**: pow(actualSize, 0.91)
- **CAjus**: pow(actualSize, 1.085)
- **CSobre**: pow(actualSize, 1.23)

Con una ordenación ascendente vemos unos tiempos muy buenos, esto resulta
en las tres primeras filas (n= 500, n = 1000, n = 2000) en tener un I muy
alta y esto resulta en la columna [T/CAjus] en ir tendiendo a la verdadera
cota ajustada que está entre 0.0105 y 0.0125. Además en la última columna,
[T/CSobre], las primeras tres filas no son más grande que la de abajo suya
respectivamente ya que su T es muy pequeña.
Cuando n es 16000 hay una anomalía.

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |      [T]     | [T/CSub] | [T/CAjus] | [T/CSobre] |
|:------:|:---:|:------------:|:--------:|:---------:|:----------:|
|    500 | 100 |     8.610000 | 0.030126 |  0.010154 |   0.004124 |
|   1000 | 100 |    18.270000 | 0.034020 |  0.010156 |   0.003730 |
|   2000 | 100 |    38.730000 | 0.038380 |  0.010149 |   0.003371 |
|   4000 |  10 |    91.700000 | 0.048361 |  0.011328 |   0.003403 |
|   8000 |  10 |   211.800000 | 0.059445 |  0.012333 |   0.003351 |
|  16000 |   1 |   761.000000 | 0.113667 |  0.020889 |   0.005132 |
|  32000 |   1 |   955.000000 | 0.075913 |  0.012357 |   0.002746 |
|  64000 |   1 |  2108.000000 | 0.089176 |  0.012858 |   0.002584 |
| 128000 |   1 |  4701.000000 | 0.105835 |  0.013517 |   0.002457 |
| 256000 |   1 |  9271.000000 | 0.111078 |  0.012566 |   0.002065 |
| 512000 |   1 | 19690.000000 | 0.125548 |  0.012580 |   0.001870 |

- **CSub**: pow(actualSize, 0.91)
- **CAjus**: pow(actualSize, 1.085)
- **CSobre**: pow(actualSize, 1.23)

Y con esta última prueba vemos que también tiene tiempos buenos y que la cota 
ajustada se sitúa entre 0.010 y 0.0135.  
Cuando n es 16000 hay una anomalía.

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


