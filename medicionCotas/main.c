#include <stdio.h>
#include <math.h>

void logN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto);
void NlogN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto);
void powNa(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto);
int calentarProcesador(int n);

int main() {
    int numeroDeIteraciones[] = {8000,16000,32000,64000,128000,256000};
    double tiempos[] = {1094.000000,2514.000000,6242.000000,18595.000000,36353.000000,83593.000000};

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

void logN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto) {
    float potencia;

    do {

        printf("\nCotas para t(N) / log N^%f\n", iniInter);

        for(int i = 0; i < size; i++) {
            potencia = powf( (float)numIter[i], iniInter);
            printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / log( (double) potencia));
        }
        iniInter += salto;
    } while(iniInter <= finInter);

}

void NlogN(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto) {
    float potencia;

    do {

        printf("\nCotas para t(N) / N^%f log N^%f\n", iniInter, iniInter);

        for(int i = 0; i < size; i++) {
            potencia = powf( (float)numIter[i], iniInter);
            printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / (potencia * log((double) potencia)));
        }
        iniInter += salto;
    } while(iniInter <= finInter);
}

void powNa(int numIter[], int size, double tiempos[], float iniInter, float finInter, float salto) {
    float potencia;

    do {
        printf("\nCotas para t(N) / N^%f\n", iniInter);

        for(int i = 0; i < size; i++) {
            potencia = powf( (float)numIter[i], iniInter);
            printf("%8d\t%15lf\t%15lf\n", numIter[i], tiempos[i], tiempos[i] / potencia);
        }
        iniInter += salto;
    } while(iniInter <= finInter);
}

int calentarProcesador(int n) {
    if(n == 0) {
        return n;
    } else {
        n * calentarProcesador(n - 1);
    }
}