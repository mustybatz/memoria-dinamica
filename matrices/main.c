#include <stdio.h>
#include <time.h>

#define size 2000

// Tiempo secuancial 47 segundos

float A[size][size], B[size][size], C[size][size];

int main()
{
    int i, j, k, tiempo;
    clock_t inicio, fin;

    inicio = clock();
    for (i = 0; i < size; i++)
    {
        for (k = 0; k < size; k++)
        {

            for (j = 0; j < size; j++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    fin = clock();
    tiempo = ((int)fin - (int)inicio) / 1000;
    printf("El tiempo fue %d segundos \n", tiempo);
}