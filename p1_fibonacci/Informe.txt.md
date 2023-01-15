  # Algoritmos Práctica 1, Sucesión de Fibonacci

Grupo: 3.1

- AUTOR 1: Alejandro Becerra Suárez	LOGIN 1: a.becerra
- AUTOR 2: Adrián Rego Criado              LOGIN 2: adrian.rego
- AUTOR 3: Miguel Cortón Debén           LOGIN 3: m.cortond

La práctica fue realizada con los siguientes dispositivos:  

- Primera máquina:
  - **Hardware**: 11th Gen Intel i7-1165G7 (8) @ 2.80 GHz (16 Gb RAM)
  - **OS**: Ubuntu 22.04.1 LTS x86_64
  - **Kernel**: 5.15.0-47-generic

- Segundo máquina
  - **Hardware**: AMD 9620P 3.2 GHz (16 GB RAM)
  - **OS**: Ubuntu 22.04.1 LTS x86_64
  - **Kernel**: 5.15.0-47-generic

- Tercera máquina
  - **Hardware**: Intel® Core™ i5-4300U CPU @ 1.90GHz × 4
  - **OS**: Ubuntu 22.04.1 LTS x86_64
  - **Kernel**: 5.15.0-47-generic

## Introducción:

La práctica se basa en 3 algoritmos que ejecutan el algoritmo de Fibonacci de formas diferentes. La Sucesión o Algoritmo de Fibonacci se caracteriza por el hecho de que cada número en ella es igual a la suma de los anteriores.  

El objetivo de esta práctica es la comparación del tiempo de ejecución de estos 3 algoritmos diferentes para el cálculo de la sucesión de Fibonacci.  

Se mide la eficacia de cada algoritmo con unas entras ya predefinidas para cada uno. El primer algoritmo fib1 utiliza un array de 5 enteros con razón 2, mientras que el segundo y tercer algoritmo usan el mismo array de 7 enteros con razón 10.  

También a partir de esto se realizan unas tablas con la Cota Subestimada, Ajustada y la Sobreestimada.

## Unidades de Tiempo: 

 Todas las mediciones de tiempo de este ejercicio están expresadas en microsegundos (us).        

|  n   | Media de x iteraciones | TiempoFib1(n) | Cota Subestimada | Cota Ajustada | Cota Sobreestimada |
| :--: | ---------------------: | ------------: | ---------------: | ------------: | -----------------: |
|  2   |                1000000 |      0.005986 |         0.005058 |      0.002377 |           0.001507 |
|  4   |                1000000 |      0.018774 |         0.012177 |      0.002565 |           0.001159 |
|  8   |                  10000 |      0.140300 |         0.065824 |      0.003018 |           0.000554 |
|  16  |                    100 |      6.700000 |         1.458115 |      0.003063 |           0.000102 |
|  32  |                      1 |  14818.000000 |       688.886701 |      0.002982 |           0.000003 |

La cota Ajustada esta entre 0.0025-0.0030 en el algoritmo 1.

- **Cota Subestimada** = TiempoFib1(n) / pow(1.1, n)
- **Cota Ajustada** = TiempoFib1(n) / pow( ( (1+sqrt(5) ) / 2), n )
- **Cota Sobreestimada** = TiempoFib1(n) / pow(2, n)

-----

|          n | Media de x iteraciones |  TiempoFib1(n) | Cota Subestimada | Cota Ajustada | Cota Sobreestimada |
| ---------: | ---------------------: | -------------: | ---------------: | ------------: | -----------------: |
|       1000 |                  10000 |       1.775800 |         0.007032 |      0.001720 |           0.000589 |
|      10000 |                    100 |      17.440000 |         0.010007 |      0.001607 |           0.000423 |
|     100000 |                    100 |     201.260000 |         0.019576 |      0.001909 |           0.000357 |
|    1000000 |                      1 |    1979.000000 |         0.030557 |      0.002067 |           0.000344 |
|   10000000 |                      1 |   19751.000000 |         0.047379 |      0.001959 |           0.000272 |
|  100000000 |                      1 |  194093.000000 |         0.076040 |      0.002012 |           0.000253 |
| 1000000000 |                      1 | 1950707.000000 |         0.132091 |      0.001878 |           0.000208 |

La cota Ajustada esta entre 0.0018-0.0020 en el algoritmo 2.  

- **Cota Subestimada** = TiempoFib2(n) / pow(n, 0.8)
- **Cota Ajustada** = TiempoFib2(n) / n
- **Cota Sobreestimada** = TiempoFib2(n) / (n * log10(n))

-----

|          n | Media de x iteraciones | TiempoFib1(n) | Cota Subestimada | Cota Ajustada | Cota Sobreestimada |
| ---------: | ---------------------: | ------------: | ---------------: | ------------: | -----------------: |
|       1000 |                1000000 |      0.040554 |         0.023501 |      0.013209 |           0.001290 |
|      10000 |                  10000 |      0.050300 |         0.025050 |      0.012525 |           0.000501 |
|     100000 |                  10000 |      0.061300 |         0.027861 |      0.012320 |           0.000195 |
|    1000000 |                  10000 |      0.075900 |         0.031149 |      0.012750 |           0.000076 |
|   10000000 |                  10000 |      0.087800 |         0.033563 |      0.012471 |           0.000027 |
|  100000000 |                  10000 |      0.102900 |         0.036805 |      0.013362 |           0.000010 |
| 1000000000 |                  10000 |      0.115800 |         0.038600 |      0.012889 |           0.000004 |

La cota Ajustada esta entre 0.012-0.013 en el algoritmo 3.  

- **Cota Subestimada** = TiempoFib3(n) / sqrt(log10(n))
- **Cota Ajustada** = TiempoFib3(n) / log10(n)
- **Cota Sobreestimada** = TiempoFib3(n) / pow(n, 0.5)

-----

**No se detectaron mediciones anómalas**  

## Conclusión:

Según las tablas expuestas anteriormente, se puede concluír que el algoritmo con el menor tiempo de respuesta, el más rápido, es el tercer algoritmo, y el más lento el primero.  

En los tres algoritmos el tiempo de ejecución aumenta a medida que crece el valor de "n", pero en el caso del tercer algoritmo, con un valor de n=1000000000 el tiempo es muy pequeño (0.115800 us), mientras que en el caso del segundo algoritmo, con el mismo valor de n, el tiempo es mucho mayor (1950707.0 us).  

Por último, en el primer algoritmo, cogiendo un valor de n=32, mucho más pequeño que en los otros 2 casos, el tiempo es muy grande (14818.0 us).  



