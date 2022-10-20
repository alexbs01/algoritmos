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

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 |  10 |      50.600000 | 0.101200 |  0.018094 |   0.002431 |
|   1000 |  10 |     109.600000 | 0.109600 |  0.017629 |   0.001737 |
|   2000 |  10 |     233.500000 | 0.116750 |  0.017067 |   0.001221 |
|   4000 |   1 |     997.000000 | 0.249250 |  0.033391 |   0.001719 |
|   8000 |   1 |    2076.000000 | 0.259500 |  0.032083 |   0.001181 |
|  16000 |   1 |    4826.000000 | 0.301625 |  0.034621 |   0.000906 |
|  32000 |   1 |   10314.000000 | 0.322313 |  0.034523 |   0.000639 |
|  64000 |   1 |   19362.000000 | 0.302531 |  0.030375 |   0.000395 |
| 128000 |   1 |   41208.000000 | 0.321937 |  0.030418 |   0.000278 |
| 256000 |   1 |   86000.000000 | 0.335938 |  0.029974 |   0.000191 |
| 512000 |   1 |  183030.000000 | 0.357480 |  0.030214 |   0.000134 |

- **CSub**: N  
- **CAjus**: N * 0.9 * log(N)  
- **CSobre**: pow(N, 1.6)  

Ahora entrando ya en la ordenación con Quicksort, vemos que a parte de ser más 
rápido con un array de elementos desordenados, la cota ajustada está 
situada entre 0.029974 y 0.030214.  

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |      29.420000 | 0.043125 |  0.009468 |   0.001413 |
|   1000 |  10 |      66.000000 | 0.046724 |  0.009554 |   0.001046 |
|   2000 |  10 |     139.100000 | 0.047560 |  0.009150 |   0.000727 |
|   4000 |   1 |     535.000000 | 0.088347 |  0.016126 |   0.000923 |
|   8000 |   1 |    1161.000000 | 0.092595 |  0.016148 |   0.000661 |
|  16000 |   1 |    2351.000000 | 0.090558 |  0.015179 |   0.000441 |
|  32000 |   1 |    4852.000000 | 0.090264 |  0.014617 |   0.000300 |
|  64000 |   1 |    9707.000000 | 0.087216 |  0.013705 |   0.000198 |
| 128000 |   1 |   20308.000000 | 0.088125 |  0.013491 |   0.000137 |
| 256000 |   1 |   42602.000000 | 0.089285 |  0.013363 |   0.000095 |
| 512000 |   1 |   88250.000000 | 0.089327 |  0.013111 |   0.000065 |

- **CSub**: pow(N, 1.05)  
- **CAjus**: N * log(N)  
- **CSobre**: pow(N, 1.6)  

Así de primeras, los tiempos son mejores que si están puestos de forma 
aleatoria, pero aun así es más lento que el de ordenación por inserción. Y su 
cota ajustada se sitúa entre 0.013111 y 0.013705.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |      31.990000 | 0.063980 |  0.011439 |   0.001537 |
|   1000 |  10 |      71.500000 | 0.071500 |  0.011501 |   0.001133 |
|   2000 |  10 |     142.300000 | 0.071150 |  0.010401 |   0.000744 |
|   4000 |   1 |     543.000000 | 0.135750 |  0.018186 |   0.000936 |
|   8000 |   1 |    1128.000000 | 0.141000 |  0.017432 |   0.000642 |
|  16000 |   1 |    2515.000000 | 0.157188 |  0.018042 |   0.000472 |
|  32000 |   1 |    4885.000000 | 0.152656 |  0.016351 |   0.000302 |
|  64000 |   1 |   10261.000000 | 0.160328 |  0.016097 |   0.000210 |
| 128000 |   1 |   21505.000000 | 0.168008 |  0.015874 |   0.000145 |
| 256000 |   1 |   43482.000000 | 0.169852 |  0.015155 |   0.000097 |
| 512000 |   1 |   93218.000000 | 0.182066 |  0.015388 |   0.000068 |

- **CSub**: N  
- **CAjus**: N * 0.9 * log(N)  
- **CSobre**: pow(N, 1.6)  

Y con esta tabla vemos que la cota ajustada está entre 0.015155 y 0.015388.  

-----

## Mediciones de Quicksort con un umbral de 10

### Prueba con elementos aleatorios

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |      35.770000 | 0.052432 |  0.035667 |   0.001719 |
|   1000 |  10 |      85.200000 | 0.060317 |  0.039304 |   0.001350 |
|   2000 |  10 |     199.400000 | 0.068178 |  0.042558 |   0.001043 |
|   4000 |   1 |     733.000000 | 0.121043 |  0.072379 |   0.001264 |
|   8000 |   1 |    1619.000000 | 0.129123 |  0.073962 |   0.000921 |
|  16000 |   1 |    3558.000000 | 0.137050 |  0.075201 |   0.000668 |
|  32000 |   1 |    7830.000000 | 0.145665 |  0.076566 |   0.000485 |
|  64000 |   1 |   16286.000000 | 0.146327 |  0.073679 |   0.000333 |
| 128000 |   1 |   34221.000000 | 0.148499 |  0.071627 |   0.000231 |
| 256000 |   1 |   73195.000000 | 0.153401 |  0.070879 |   0.000163 |
| 512000 |   1 |  156111.000000 | 0.158016 |  0.069940 |   0.000114 |

- **CSub**: pow(N, 1.05)  
- **CAjus**: pow(N, 1.112)  
- **CSobre**: pow(N, 1.6)  

Ahora con un umbral de 10, vemos que los tiempos mejoraron y también que la
cota ajustada está entre 0.069940 y 0.071627.  

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |      16.490000 | 0.032980 |  0.015645 |   0.000792 |
|   1000 | 100 |      33.930000 | 0.033930 |  0.014811 |   0.000538 |
|   2000 |  10 |      79.500000 | 0.039750 |  0.015967 |   0.000416 |
|   4000 |  10 |     159.200000 | 0.039800 |  0.014711 |   0.000275 |
|   8000 |   1 |     605.000000 | 0.075625 |  0.025721 |   0.000344 |
|  16000 |   1 |    1313.000000 | 0.082062 |  0.025683 |   0.000246 |
|  32000 |   1 |    2671.000000 | 0.083469 |  0.024038 |   0.000165 |
|  64000 |   1 |    6337.000000 | 0.099016 |  0.026240 |   0.000129 |
| 128000 |   1 |   14008.000000 | 0.109437 |  0.026687 |   0.000094 |
| 256000 |   1 |   28685.000000 | 0.112051 |  0.025144 |   0.000064 |
| 512000 |   1 |   61883.000000 | 0.120865 |  0.024957 |   0.000045 |

- **CSub**: N  
- **CAjus**: pow(N, 1.12)  
- **CSobre**: pow(N, 1.6)  

Para cuando está ordenados de forma ascendente podemos observar que las cota 
ajustada se sitúa entre 0.024038 y 0.025144.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |      17.980000 | 0.035960 |  0.017059 |   0.000864 |
|   1000 | 100 |      38.440000 | 0.038440 |  0.016780 |   0.000609 |
|   2000 |  10 |      86.000000 | 0.043000 |  0.017272 |   0.000450 |
|   4000 |  10 |     179.800000 | 0.044950 |  0.016614 |   0.000310 |
|   8000 |   1 |     684.000000 | 0.085500 |  0.029080 |   0.000389 |
|  16000 |   1 |    1516.000000 | 0.094750 |  0.029654 |   0.000285 |
|  32000 |   1 |    3133.000000 | 0.097906 |  0.028196 |   0.000194 |
|  64000 |   1 |    7012.000000 | 0.109562 |  0.029035 |   0.000143 |
| 128000 |   1 |   15068.000000 | 0.117719 |  0.028707 |   0.000102 |
| 256000 |   1 |   30687.000000 | 0.119871 |  0.026898 |   0.000068 |
| 512000 |   1 |   64411.000000 | 0.125803 |  0.025976 |   0.000047 |

- **CSub**: N  
- **CAjus**: pow(N, 1.12) 
- **CSobre**: pow(N, 1.6)  

Y para esta última forma de ordenación, vemos que la cota ajustada está
entre 0.025976 y 0.026898.  

-----

## Mediciones de Quicksort con un umbral de 100

### Prueba con elementos aleatorios

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |      41.650000 | 0.061052 |  0.041789 |   0.002001 |
|   1000 |  10 |      97.700000 | 0.069166 |  0.045383 |   0.001548 |
|   2000 |  10 |     211.100000 | 0.072178 |  0.045399 |   0.001104 |
|   4000 |   1 |     841.000000 | 0.138878 |  0.083735 |   0.001450 |
|   8000 |   1 |    1844.000000 | 0.147067 |  0.085002 |   0.001049 |
|  16000 |   1 |    3926.000000 | 0.151225 |  0.083786 |   0.000737 |
|  32000 |   1 |    8629.000000 | 0.160529 |  0.085259 |   0.000534 |
|  64000 |   1 |   17946.000000 | 0.161242 |  0.082092 |   0.000367 |
| 128000 |   1 |   37918.000000 | 0.164541 |  0.080304 |   0.000255 |
| 256000 |   1 |   81329.000000 | 0.170449 |  0.079743 |   0.000181 |
| 512000 |   1 |  178593.000000 | 0.180772 |  0.081071 |   0.000131 |

- **CSub**: pow(N, 1.05)  
- **CAjus**: pow(N, 1.111)
- **CSobre**: pow(N, 1.6)  

Ahora ya con el umbral de 100, vemos algo interesante sobre como afecta el 
umbral a los tiempos que se mencionará en la conclusión. Y la cota ajustada 
de esta prueba está entre 0.079743 y 0.081071.  

-----

### Prueba con elementos ordenados de forma ascendente

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |       7.320000 | 0.027254 |  0.007209 |   0.000352 |
|   1000 | 100 |      18.580000 | 0.037072 |  0.008454 |   0.000294 |
|   2000 | 100 |      42.690000 | 0.045646 |  0.008974 |   0.000223 |
|   4000 |  10 |     101.300000 | 0.058044 |  0.009838 |   0.000175 |
|   8000 |  10 |     216.800000 | 0.066570 |  0.009728 |   0.000123 |
|  16000 |   1 |     791.000000 | 0.130157 |  0.016398 |   0.000148 |
|  32000 |   1 |    2000.000000 | 0.176358 |  0.019155 |   0.000124 |
|  64000 |   1 |    4354.000000 | 0.205744 |  0.019267 |   0.000089 |
| 128000 |   1 |    9602.000000 | 0.243149 |  0.019630 |   0.000065 |
| 256000 |   1 |   20067.000000 | 0.272312 |  0.018954 |   0.000045 |
| 512000 |   1 |   42366.000000 | 0.308088 |  0.018488 |   0.000031 |

- **CSub**: pow(N, 0.9)  
- **CAjus**: pow(N, 1.114)  
- **CSobre**: pow(N, 1.6)  

Con una ordenación ascendente vemos unos tiempos muy buenos, que la cota 
ajustada parece estar entre 0.018488 y 0.019630.  

-----

### Prueba con elementos ordenados de forma descendente

|   [N]  | [I] |       [T]      | [T/CSub] | [T/CAjus] | [T/CSobre] |
|-------:|----:|---------------:|---------:|----------:|-----------:|
|    500 | 100 |      11.850000 | 0.023700 |  0.011964 |   0.003673 |
|   1000 | 100 |      22.570000 | 0.022570 |  0.010557 |   0.002841 |
|   2000 |  10 |      50.700000 | 0.025350 |  0.010987 |   0.002592 |
|   4000 |  10 |     107.000000 | 0.026750 |  0.010742 |   0.002222 |
|   8000 |  10 |     239.500000 | 0.029937 |  0.011140 |   0.002020 |
|  16000 |   1 |     995.000000 | 0.062187 |  0.021441 |   0.003408 |
|  32000 |   1 |    2148.000000 | 0.067125 |  0.021445 |   0.002988 |
|  64000 |   1 |    4966.000000 | 0.077594 |  0.022969 |   0.002805 |
| 128000 |   1 |   10163.000000 | 0.079398 |  0.021778 |   0.002332 |
| 256000 |   1 |   21887.000000 | 0.085496 |  0.021729 |   0.002039 |
| 512000 |   1 |   48786.000000 | 0.095285 |  0.022439 |   0.001846 |

- **CSub**: pow(N, 1)  
- **CAjus**: pow(N, 1.11)
- **CSobre**: pow(N, 1.3)  

Y con esta última prueba vemos que también tiene tiempos buenos y que la cota 
ajustada se sitúa entre 0.021729 y 0.022439.  

-----

## Conclusiones

**No se detectaron mediciones anómalas**.  

### Algoritmo de Ordenación por Inserción

Este algoritmo se puso a prueba con tres tipos de arrays, siendo estos con 
**números al azar**, en **orden ascendente** y en **orden descendente**.  

En la **ordenación** de números **al azar** obtuvo **tiempos normales**, 
comparándolo con los otros dos tipos de arrays.  

Sin embargo, el **mejor** de los **tiempo** se midió en la **ordenación 
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

Este algoritmo a parte de tener las mismas pruebas que el de ordenación por 
inserción, también se le sometió con dos variantes distintas. Tener un umbral 
a partir del cual se utilice la ordenación por inserción, los umbrales elegidos 
fueron 1, 10 y 100. El umbral indica a partir de que tamaño de las semimitades, 
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
independiente a la cantidad elementos que tiene el array. Y si hay colecciónes 
de elementos casi ordenados la mejor opción será el primero. Y dentro de las 
tres posibilidades estudiadas del Quicksort, el mejor será con umbral 10.  


