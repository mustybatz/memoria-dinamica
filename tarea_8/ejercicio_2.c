#include <stdio.h>
#include<stdlib.h>

int main() {

    int N, current = 0, *ptr, i;

    printf("Ingresa los numeros a ingresar: ");
    scanf("%d", &N);
    ptr = (int*)(malloc(N * sizeof(int)));

    for ( i = 0; i < N; i++)
    {
        printf("Numero: ");
        scanf("%d", (ptr + i) );
    }

    for ( i = 0; i < N; i++)
    {
        current += *(ptr + i);
    }

    
    printf("PROMEDIO: %d\n", current / N );
    printf("Utilice %d bytes de memoria\n", sizeof(int) * N);
    
    free(ptr);
    exit(0);

}