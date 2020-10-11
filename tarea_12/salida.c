#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *salida = fopen("C.bin", "rb");
    int C[3][3];
    fread(&C, sizeof(int[3][3]), 1, salida);
    fclose(salida);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}