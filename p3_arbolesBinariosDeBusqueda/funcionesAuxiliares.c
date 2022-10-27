/*
 * AUTOR 1: Adrián Rego Criado
 * AUTOR 2: Miguel Cortón Debén
 * AUTOR 3: Alejandro Becerra Suárez
 * */

#include "funcionesAuxiliares.h"

void test() {
    int i;
    arbol T = crearArbol();
    printf("Arbol vacio: ");
    visualizar(T);

    printf("\n");
    printf("Altura del arbol: %d\n", altura(T));

    printf("Insertamos por este orden 3-1-2-5-4-5 al arbol vacio\n");
    T = insertar(3, T);
    T = insertar(1, T);
    T = insertar(2, T);
    T = insertar(5, T);
    T = insertar(4, T);
    T = insertar(5, T);

    printf("Arbol: ");
    visualizar(T);

    printf("\nAltura del arbol: %d\n", altura(T));

    for(i = 1; i <= 6; i++) {
        printf("Busco %d y ", i);
        if(buscar(i, T) != NULL) {
            printf("encuentro %d repetido: %d veces\n", i,
                   numeroRepeticiones(buscar(i, T)));
        } else {
            printf("no encuentro nada\n");
        }
    }

    printf("Elimino el arbol\n");
    T = eliminarArbol(T);

    printf("Arbol vacío: ");

    visualizar(T);

    printf("\nAltura del arbol: %d\n", altura(T));
}


void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int v [], int n) {
    int i, m = 2 * n + 1;

    for(i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

chrono tardanzaI(int array[], int size) {
    double tInicial, tFinal, ta, tb, Tiempo;
    int count = 1, i, cnt;
    arbol T = crearArbol();
    chrono c = {count, (Tiempo / count)};

    aleatorio(array, size);
    tInicial = microsegundos();
    for(cnt = 0; cnt < size; cnt++) {
        insertar(array[cnt], T);
    }
    tFinal = microsegundos();
    Tiempo = tFinal - tInicial;

    while(Tiempo <= 500) {
        tInicial = microsegundos();
        for(i = 0; i <= count; i++) {
            aleatorio(array, size);
            for(cnt = 0; cnt < size; cnt++) {
                insertar(array[cnt], T);
            }
        }
        tFinal = microsegundos();
        ta = tFinal - tInicial;

        tInicial = microsegundos();
        for(i = 0; i <= count; i++) {
            aleatorio(array, size);
        }
        tFinal = microsegundos();
        tb = tFinal - tInicial;

        Tiempo = ta - tb;

        if(Tiempo <= 500) count *= 10;
    }

    c.count = count;
    c.tiempoMedio = Tiempo / count;
    return c;
}

chrono tardanzaB(int array[], int size) {
    double tInicial, tFinal, ta, tb, Tiempo;
    int count = 1, i, cnt;
    arbol T = crearArbol();
    chrono c = {count, (Tiempo / count)};

    aleatorio(array, size);
    for(cnt = 0; cnt < size; cnt++) {
        insertar(array[cnt], T);
    }

    aleatorio(array, size);
    tInicial = microsegundos();
    for(cnt = 0; cnt < size; cnt++) {
        buscar(array[cnt], T);
    }
    tFinal = microsegundos();
    Tiempo = tFinal - tInicial;

    while(Tiempo <= 500) {
        aleatorio(array, size);
        for(cnt = 0; cnt < size; cnt++) {
            insertar(array[cnt], T);
        }

        tInicial = microsegundos();
        for(i = 0; i <= count; i++) {
            aleatorio(array, size);
            for(cnt = 0; cnt < size; cnt++) {
                buscar(array[cnt], T);
            }
        }
        tFinal = microsegundos();
        ta = tFinal - tInicial;

        tInicial = microsegundos();
        for(i = 0; i <= count; i++) {
            aleatorio(array, size);
        }
        tFinal = microsegundos();
        tb = tFinal - tInicial;

        Tiempo = ta - tb;

        if(Tiempo <= 500) count *= 10;
    }

    c.count = count;
    c.tiempoMedio = Tiempo / count;
    return c;
}

void tablaIB(int inicialSize, int maxSize) {
    int actualSize = inicialSize;
    chrono TI, TB;
    int arrayNumbers[maxSize];

    printf("\n*********************************************************\n");
    printf("Tiempos en insertar y buscar n números enteros aleatorios:\n\n");
    printf("   [N]\t\t     [II]\t\t[T_ins]\t    [IB]\t\t[T_bus]\n");

    do{
        TI = tardanzaI(arrayNumbers, actualSize);
        TB = tardanzaB(arrayNumbers, actualSize);

        printf("%8d\t%8d\t%15lf\t%8d\t%15lf\n",
               actualSize, TI.count, TI.tiempoMedio, TB.count, TB.tiempoMedio);

        actualSize *= 2;
    } while(actualSize <= maxSize); //&& dato.tiempoMedio <= maxTime
}

void tablaI(int inicialSize, int maxSize) {

    int actualSize = inicialSize;
    int arrayNumbers[maxSize];
    chrono TI;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Inserción de n elementos.\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        TI = tardanzaI(arrayNumbers, actualSize);

        TSu = TI.tiempoMedio / pow(actualSize, 1.2);  // Tiempo / CotaSubestimada
        TA = TI.tiempoMedio / actualSize;      // Tiempo / CotaAjustada
        TSo = TI.tiempoMedio / pow(actualSize, 0.8);   // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, TI.count, TI.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime
}

void tablaB(int inicialSize, int maxSize) {

    int actualSize = inicialSize;
    int arrayNumbers[maxSize];
    chrono TB;
    double TSu, TA, TSo;

    printf("\n\n*********************************************************\n");
    printf("Búsqueda de n elementos.\n\n");
    printf("   [N]\t\t      [I]\t\t[T]\t\t[T/CSub]\t[T/CAjus]\t[T/CSobre]\n\n");

    do {
        TB = tardanzaI(arrayNumbers, actualSize);

        TSu = TB.tiempoMedio / actualSize;  // Tiempo / CotaSubestimada
        TA = TB.tiempoMedio / pow(actualSize, 1.25);      // Tiempo / CotaAjustada
        TSo = TB.tiempoMedio / pow(actualSize, 1.5);   // Tiempo / CotaSobreestimada

        printf("%8d\t%8d\t%14lf\t%15lf\t%15lf\t%15lf\n",
               actualSize, TB.count, TB.tiempoMedio, TSu, TA, TSo);

        actualSize *= 2;
    } while (actualSize <= maxSize);  //&& dato.tiempoMedio <= maxTime
}