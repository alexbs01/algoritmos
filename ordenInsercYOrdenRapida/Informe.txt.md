# Práctica 2, Algoritmos de ordenación

## Autores, grupo 3.1
- Alejandro Becerra Suárez, a.becerra  
- Adrián Rego Criado, adrian.rego  
- Miguel Cortón Debén, m.cortond  

## Características de la máquina
- **Hardware**: AMD 9620P 3.2 GHz (16 GB RAM)  
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
- **I**: Numero de veces que se repite el algoritmo.  
- **T**: Tiempo medio de ejecución del algoritmo en microsegundos (us).  
- **T/CSub**: Tiempo medio entre la Cota Subestimada.  
- **T/CAjus**: Tiempo medio entre la Cota Ajustada.  
- **T/CSobre**: Tiempo medio entre la Cota Sobreestimada.  

## Mediciones de Ordenación por Inserción

### Prueba con elementos aleatorios

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|   500  |  10 |      253.500000 | 0.003514 |  0.001079 |  0.000293  |
| 1000   |   1 |      831.000000 | 0.003308 | 0.000890  | 0.000209   |
| 2000   |   1 |     3448.000000 | 0.003942 | 0.000930  | 0.000188   |
| 4000   |   1 |    18623.000000 | 0.006114 | 0.001265  | 0.000222   |
| 8000   |   1 |    72083.000000 | 0.006796 | 0.001232  | 0.000187   |
| 16000  |   1 |   257491.000000 | 0.006972 | 0.001108  | 0.000145   |
| 32000  |   1 |  1061693.000000 | 0.008255 | 0.001150  | 0.000130   |
| 64000  |   1 |  4027408.000000 | 0.008993 | 0.001098  | 0.000108   |
| 128000 |   1 | 16656883.000000 | 0.010681 | 0.001144  | 0.000097   |

- **CSub**: pow(N, 1.8)  
- **CAjus**: pow(N, 1.99)  
- **CSobre**: pow(N, 2.2) 

Con esta primera tabla podemos ver que el tiempo dividido por la cota ajustada 
se aproxima a 0.001144.  
  
-----
  
### Prueba con elementos ordenados de forma ascendente
  
|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 |1000 |        3.979000 | 0.027580 |  0.007958 |  0.002296  |
|   1000 | 100 |        6.890000 | 0.027430 |  0.006890 |  0.001731  |
|   2000 | 100 |       13.560000 | 0.031005 |  0.006780 |  0.001483  |
|   4000 | 100 |       44.300000 | 0.058178 |  0.011075 |  0.002108  |
|   8000 |  10 |       80.500000 | 0.060719 |  0.010063 |  0.001668  |
|  16000 |  10 |       78.300000 | 0.033921 |  0.004894 |  0.000706  |
|  32000 |  10 |      226.200000 | 0.056282 |  0.007069 |  0.000888  |
|  64000 |  10 |      732.900000 | 0.104737 |  0.011452 |  0.001252  |
| 128000 |   1 |     1403.000000 | 0.115157 |  0.010961 |  0.001043  |

- **CSub**: pow(N, 0.8)  
- **CAjus**: N  
- **CSobre**: pow(N, 1.2)  

Con esta forma de ordenación, el algoritmo presenta unos tiempos muy bajos ya 
que esta es la mejor situación para la ordenación por inserción, por ello la 
cota ajusta de es lineal O(n), y el valor está entre 0.010000 y 0.011000.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 |   1 |      563.000000 | 0.007805 |  0.002252 |   0.000650 |
|   1000 |   1 |     2120.000000 | 0.008440 |  0.002120 |   0.000533 |
|   2000 |   1 |     8373.000000 | 0.009573 |  0.002093 |   0.000458 |
|   4000 |   1 |    33901.000000 | 0.011130 |  0.002119 |   0.000403 |
|   8000 |   1 |   133047.000000 | 0.012544 |  0.002079 |   0.000345 |
|  16000 |   1 |   521156.000000 | 0.014111 |  0.002036 |   0.000294 |
|  32000 |   1 |  2071145.000000 | 0.016104 |  0.002023 |   0.000254 |
|  64000 |   1 |  8264373.000000 | 0.018454 |  0.002018 |   0.000221 |
| 128000 |   1 | 33224844.000000 | 0.021305 |  0.002028 |   0.000193 |

- **CSub**: pow(N, 1.8)  
- **CAjus**: pow(N, 2)  
- **CSobre**: pow(N, 2.2)  

Con esta prueba, se puede ver simplemente viendo los tiempos que tiene un 
tiempo de ejecución muy grande, esto es debida a que una array ordenado de 
mayor a menor es el peor caso posible para este algoritmo.  
La cota ajustada se aproxima en este algoritmo con esta ordenación entre 
0.002018 y 0.002036.  

-----

## Mediciones de Quicksort con un umbral de 1

### Prueba con elementos de aleatorios 

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 |  10 |       76.700000 | 0.153400 |  0.024684 |   0.003685 |
|   1000 |  10 |      165.700000 | 0.165700 |  0.023988 |   0.002626 |
|   2000 |  10 |      345.400000 | 0.172700 |  0.022721 |   0.001806 |
|   4000 |   1 |      693.000000 | 0.173250 |  0.020888 |   0.001195 |
|   8000 |   1 |     1492.000000 | 0.186500 |  0.020752 |   0.000849 |
|  16000 |   1 |     3118.000000 | 0.194875 |  0.020131 |   0.000585 |
|  32000 |   1 |     6653.000000 | 0.207906 |  0.020042 |   0.000412 |
|  64000 |   1 |    15416.000000 | 0.240875 |  0.021766 |   0.000315 |
| 128000 |   1 |    34378.000000 | 0.268578 |  0.022839 |   0.000232 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Ahora entrando ya en la ordenación con Quicksort, vemos que a parte de ser más 
rápido con un array de elementos desordenados, la cota ajustada está 
situada entre 0.021766 y 0.022839.  

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 |  10 |       50.200000 | 0.100400 |  0.016155 |   0.002412 |
|   1000 |  10 |      103.300000 | 0.103300 |  0.014954 |   0.001637 |
|   2000 |  10 |      202.300000 | 0.101150 |  0.013308 |   0.001058 |
|   4000 |  10 |      633.100000 | 0.158275 |  0.019083 |   0.001092 |
|   8000 |   1 |     1235.000000 | 0.154375 |  0.017177 |   0.000703 |
|  16000 |   1 |     1847.000000 | 0.115437 |  0.011925 |   0.000347 |
|  32000 |   1 |     3589.000000 | 0.112156 |  0.010812 |   0.000222 |
|  64000 |   1 |     7610.000000 | 0.118906 |  0.010745 |   0.000155 |
| 128000 |   1 |    13790.000000 | 0.107734 |  0.009161 |   0.000093 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Así de primeras, los tiempos son mejores que si están puestos de forma 
aleatoria, pero aun así es más lento que el de ordenación por inserción.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 | 100 |       42.800000 | 0.085600 |  0.009547 |   0.002056 |
|   1000 |  10 |       99.500000 | 0.099500 |  0.009984 |   0.001577 |
|   2000 |  10 |      211.500000 | 0.105750 |  0.009644 |   0.001106 |
|   4000 |  10 |      428.100000 | 0.107025 |  0.008944 |   0.000738 |
|   8000 |   1 |      818.000000 | 0.102250 |  0.007886 |   0.000465 |
|  16000 |   1 |     1724.000000 | 0.107750 |  0.007715 |   0.000324 |
|  32000 |   1 |     4153.000000 | 0.129781 |  0.008672 |   0.000257 |
|  64000 |   1 |     8567.000000 | 0.133859 |  0.008384 |   0.000175 |
| 128000 |   1 |    18707.000000 | 0.146148 |  0.008614 |   0.000126 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Y con esta tabla vemos que la cota ajustada está entre 0.008384 y 0.008614.  

-----

## Mediciones de Quicksort con un umbral de 10

### Prueba con elementos aleatorios

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 | 100 |       43.440000 | 0.086880 |  0.013980 |   0.002087 |
|   1000 |  10 |      120.300000 | 0.120300 |  0.017415 |   0.001907 |
|   2000 |  10 |      250.900000 | 0.125450 |  0.016505 |   0.001312 |
|   4000 |  10 |      521.700000 | 0.130425 |  0.015725 |   0.000900 |
|   8000 |   1 |     1067.000000 | 0.133375 |  0.014841 |   0.000607 |
|  16000 |   1 |     2376.000000 | 0.148500 |  0.015340 |   0.000446 |
|  32000 |   1 |     5155.000000 | 0.161094 |  0.015529 |   0.000319 |
|  64000 |   1 |    10584.000000 | 0.165375 |  0.014944 |   0.000216 |
| 128000 |   1 |    23451.000000 | 0.183211 |  0.015579 |   0.000158 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Ahora con un umbral de 10, vemos que los tiempos mejoraron y también que la
cota ajustada está entre 0.014944 y 0.015579.  

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 | 100 |       21.500000 | 0.043000 |  0.006919 |   0.001033 |
|   1000 | 100 |       42.860000 | 0.042860 |  0.006205 |   0.000679 |
|   2000 |  10 |       95.900000 | 0.047950 |  0.006308 |   0.000501 |
|   4000 |  10 |      252.500000 | 0.063125 |  0.007611 |   0.000435 |
|   8000 |   1 |      674.000000 | 0.084250 |  0.009374 |   0.000383 |
|  16000 |   1 |     1276.000000 | 0.079750 |  0.008238 |   0.000239 |
|  32000 |   1 |     2008.000000 | 0.062750 |  0.006049 |   0.000124 |
|  64000 |   1 |     3704.000000 | 0.057875 |  0.005230 |   0.000076 |
| 128000 |   1 |     8603.000000 | 0.067211 |  0.005715 |   0.000058 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Para cuando está ordenados de forma ascendente podemos observar que las cota 
ajustada se sitúa entre 0.005715 y 0.006049.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 | 100 |       31.940000 | 0.063880 |  0.007125 |   0.001535 |
|   1000 | 100 |       44.520000 | 0.044520 |  0.004467 |   0.000706 |
|   2000 |  10 |      109.800000 | 0.054900 |  0.005006 |   0.000574 |
|   4000 |  10 |      274.600000 | 0.068650 |  0.005737 |   0.000474 |
|   8000 |   1 |      612.000000 | 0.076500 |  0.005900 |   0.000348 |
|  16000 |   1 |     1074.000000 | 0.067125 |  0.004806 |   0.000202 |
|  32000 |   1 |     2248.000000 | 0.070250 |  0.004694 |   0.000139 |
|  64000 |   1 |     4466.000000 | 0.069781 |  0.004371 |   0.000091 |
| 128000 |   1 |     8883.000000 | 0.069398 |  0.004090 |   0.000060 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Y para esta última forma de ordenación, vemos que la cota ajustada está
entre 0.004090 y 0.004371.  

-----

## Mediciones de Quicksort con un umbral de 100

### Prueba con elementos aleatorios

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 |  10 |       54.700000 | 0.109400 |  0.017604 |   0.002628 |
|   1000 |  10 |       99.900000 | 0.099900 |  0.014462 |   0.001583 |
|   2000 |  10 |      280.600000 | 0.140300 |  0.018458 |   0.001467 |
|   4000 |   1 |      522.000000 | 0.130500 |  0.015734 |   0.000900 |
|   8000 |   1 |     1145.000000 | 0.143125 |  0.015925 |   0.000651 |
|  16000 |   1 |     2434.000000 | 0.152125 |  0.015715 |   0.000457 |
|  32000 |   1 |     4998.000000 | 0.156188 |  0.015056 |   0.000309 |
|  64000 |   1 |    11063.000000 | 0.172859 |  0.015620 |   0.000226 |
| 128000 |   1 |    23301.000000 | 0.182039 |  0.015480 |   0.000157 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Ahora ya con el umbral de 100, vemos algo interesante sobre como afecta el 
umbral a los tiempos que se mencionará en la conclusión. Y la cota ajustada 
de esta prueba está entre 0.015056 y 0.015480.  

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 | 100 |        9.380000 | 0.018760 |  0.003019 |   0.000451 |
|   1000 | 100 |       21.950000 | 0.021950 |  0.003178 |   0.000348 |
|   2000 |  10 |       52.100000 | 0.026050 |  0.003427 |   0.000272 |
|   4000 |  10 |      117.000000 | 0.029250 |  0.003527 |   0.000202 |
|   8000 |  10 |      234.600000 | 0.029325 |  0.003263 |   0.000133 |
|  16000 |   1 |      516.000000 | 0.032250 |  0.003331 |   0.000097 |
|  32000 |   1 |     1079.000000 | 0.033719 |  0.003250 |   0.000067 |
|  64000 |   1 |     2274.000000 | 0.035531 |  0.003211 |   0.000046 |
| 128000 |   1 |     5036.000000 | 0.039344 |  0.003346 |   0.000034 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Con una ordenación ascendente vemos unos tiempos muy buenos, que la cota 
ajustada parece estar entre 0.003211 y 0.003346.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]       | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|----------------:|---------:|----------:|-----------:|
|    500 | 100 |       14.680000 | 0.029360 |  0.003275 |   0.000705 |
|   1000 | 100 |       24.750000 | 0.024750 |  0.002483 |   0.000392 |
|   2000 |  10 |       62.100000 | 0.031050 |  0.002832 |   0.000325 |
|   4000 |  10 |      143.600000 | 0.035900 |  0.003000 |   0.000248 |
|   8000 |  10 |      318.100000 | 0.039763 |  0.003067 |   0.000181 |
|  16000 |   1 |      594.000000 | 0.037125 |  0.002658 |   0.000111 |
|  32000 |   1 |     1420.000000 | 0.044375 |  0.002965 |   0.000088 |
|  64000 |   1 |     2708.000000 | 0.042313 |  0.002650 |   0.000055 |
| 128000 |   1 |     6716.000000 | 0.052469 |  0.003093 |   0.000045 |

- **CSub**: N  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Y con esta última prueba vemos que también tiene tiempos buenos y que la cota 
ajustada se sitúa entre 0.002650 y 0.003093.  














