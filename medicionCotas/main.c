#include <stdio.h>
#include <math.h>

double media_aritmetica(int size, const double datos[]);
double varianza(int size, double datos[]);
double minimoDeDosNumeros(double num1, double num2);
void logN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto);
void NlogN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto);
void powNa(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto);
int calentarProcesador(int n);

int main() {
    //int numeroDeIteraciones[] = {500,1000,2000,4000,8000,16000,32000,64000,128000,256000,512000};
    int numeroDeIteraciones[] = {500,1000,2000,4000,8000,16000};
    //int numeroDeIteraciones[] = {1000,10000,100000,1000000,10000000,100000000,1000000000};
    double tiempos[] = {   744.000000
            ,2624.000000
            ,13112.000000
            ,58045.000000
            ,225416.000000
            ,915923.000000




    };

    float inicioIntervalo, finalIntervalo, salto;
    int seleccion;
    int size = sizeof(numeroDeIteraciones) / sizeof(numeroDeIteraciones[0]);

    printf("Escribe inicio del intervalo, final y salto separados por espacio: ");
    scanf("%f %f %f", &inicioIntervalo, &finalIntervalo, &salto);

    printf("\nSe generarán %f tablas\n", roundf((finalIntervalo - inicioIntervalo) / salto));

    do {
        printf("\nVer cota ajustada para log N (1), N log N (2), N^a (3), fin programa(4):");
        scanf("%d", &seleccion);

        calentarProcesador(50);

        switch (seleccion) {
            case 1: logN(numeroDeIteraciones, size, tiempos, inicioIntervalo, finalIntervalo, salto);
                break;
            case 2: NlogN(numeroDeIteraciones, size, tiempos, inicioIntervalo, finalIntervalo, salto);
                break;
            case 3: powNa(numeroDeIteraciones, size, tiempos, inicioIntervalo, finalIntervalo, salto);
                break;
            case 4: break;
            default:
                printf("Parámetro no válido");
        }
    } while(seleccion != 4);

    return 0;
}

double media_aritmetica(int size, const double datos[]) {
    double suma = 0;
    for (int i = 0; i < size; i++) {
        suma += datos[i];
        //suma = suma+vector[i];
    }
    return suma / size;
}

double varianza(int size, double datos[]) {
    double media = media_aritmetica(size, datos);
    double var = 0;
    for (int i = 0; i < size; i++) {
        var += pow(datos[i] - media, 2);
    }
    var /= size;
    return var;
}

double minimoDeDosNumeros(double num1, double num2) {
     if(num1 <= num2) {
         return num1;
     } else {
         return num2;
     }
}

void logN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto) {
    float potencia;
    double potenciasParaVarianza[size], varianzaNum;
    struct minimo {double varizanza; float n;} minimo;
    minimo.varizanza = 999999;

    do {
        // No estoy seguro de si se puede log N^%f o es solo para la potencial
        printf("\nCotas para t(N) / log N^%f\n", iniInter);

        for(int i = 0; i < size; i++) {
            potencia = powf( (float)numIter[i], iniInter);
            printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / log( (double) potencia));
            potenciasParaVarianza[i] = tiempos[i] / log( (double) potencia);
        }
        varianzaNum = varianza(size, (double *) potenciasParaVarianza);
        printf("Varianza: %.15lf\n", varianzaNum);
        if(minimoDeDosNumeros(minimo.varizanza, varianzaNum) == varianzaNum && potenciasParaVarianza[size - 1] > 0.000010) {
            minimo.varizanza = varianzaNum;
            minimo.n = iniInter;
        }

        iniInter += salto;
    } while(iniInter <= finInter);

    printf("\nMínimo alcanzado en log N^%f con varianza de %.15lf\n", minimo.n, minimo.varizanza);
    for(int i = 0; i < size; i++) {
        potencia = powf( (float)numIter[i], minimo.n);
        printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / log( (double) potencia));
        potenciasParaVarianza[i] = tiempos[i] / log( (double) potencia);
    }
}

void NlogN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto) {
    float potencia;
    double potenciasParaVarianza[size], varianzaNum;
    struct minimo {double varizanza; float n;} minimo;
    minimo.varizanza = 999999;

    do {
        // No estoy seguro de si se puede N^%f log N^%f o es solo para la potencial
        printf("\nCotas para t(N) / N^%f log N^%f\n", iniInter, iniInter);

        for(int i = 0; i < size; i++) {
            potencia = powf( (float)numIter[i], iniInter);
            printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / (potencia * log((double) potencia)));
            potenciasParaVarianza[i] = tiempos[i] / (potencia * log((double) potencia));
        }
        varianzaNum = varianza(size, (double *) potenciasParaVarianza);
        printf("Varianza: %.15lf\n", varianzaNum);
        if(minimoDeDosNumeros(minimo.varizanza, varianzaNum) == varianzaNum && potenciasParaVarianza[size - 1] > 0.000010) {
            minimo.varizanza = varianzaNum;
            minimo.n = iniInter;
        }

        iniInter += salto;
    } while(iniInter <= finInter);

    printf("\nMínimo alcanzado en N^%f log N^%f con varianza de %.15lf\n", minimo.n, minimo.n, minimo.varizanza);

    for(int i = 0; i < size; i++) {
        potencia = powf( (float)numIter[i], minimo.n);
        printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / (potencia * log((double) potencia)));
        potenciasParaVarianza[i] = tiempos[i] / (potencia * log((double) potencia));
    }
}

void powNa(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto) {
    float potencia;
    double potenciasParaVarianza[size];
    struct minimo {double varizanza; float n;} minimo;
    minimo.varizanza = 999999;
    double varianzaNum;
    do {
        printf("\nCotas para t(N) / N^%f\n", iniInter);

        for(int i = 0; i < size; i++) {
            potencia = powf( (float)numIter[i], iniInter);
            printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / potencia);
            potenciasParaVarianza[i] = tiempos[i] / potencia;
        }
        varianzaNum = varianza(size, (double *) potenciasParaVarianza);
        printf("Varianza: %.15lf\n", varianzaNum);
        if(minimoDeDosNumeros(minimo.varizanza, varianzaNum) == varianzaNum && potenciasParaVarianza[size - 1] > 0.000010) {
            minimo.varizanza = varianzaNum;
            minimo.n = iniInter;
        }

        iniInter += salto;
    } while(iniInter <= finInter);

    printf("\nMínimo alcanzado en N^%.15f con varianza de %.15lf\n", minimo.n, minimo.varizanza);

    for(int i = 0; i < size; i++) {
        potencia = powf( (float)numIter[i], minimo.n);
        printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / potencia);
        potenciasParaVarianza[i] = tiempos[i] / potencia;
    }
}

int calentarProcesador(int n) {
    if(n == 0) {
        return n;
    } else {
        n * calentarProcesador(n - 1);
    }
}