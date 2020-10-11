#include <stdio.h>
#include <stdlib.h>

int main()
{
    char file;
    printf("Que matriz quieres capturar? ingresa A o B: ");
    scanf("%c", &file);
    int array[3][3];
    FILE *archivo;

    if (file == 'A')
    {
        if ((archivo = fopen("A.bin", "wb")) == NULL)
        {
            printf("Error! opening file");
            exit(1);
        }
    }
    else
    {
        if ((archivo = fopen("B.bin", "wb")) == NULL)
        {
            printf("Error! opening file");
            exit(1);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int n = 0;
            printf("Ingresa el elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
    fwrite(&array, sizeof(int[3][3]), 1, archivo);
    fclose(archivo);
    return 0;
}