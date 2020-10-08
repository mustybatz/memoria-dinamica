#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initMat(int *mat, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            *(mat + i * n + j) = rand() % 10;
        }
    }
}

void printMat(int *mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(mat + i * n + j));
        }
    }
    printf("\n");
}


void multiplyMat(int *A, int *B, int *C, int size)
{
    int i, j, k;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                *(C + i * size + j) += *(A + i * size + k) * *(B + k * size + j);
            }
        }
    }
}

int main()
{

    int n;

    printf("Ingresa el tamaño de las matrices: ");
    scanf("%d", &n);

    int *mat1 = (int *)malloc(n * n * sizeof(int));
    int *mat2 = (int *)malloc(n * n * sizeof(int));
    int *output = (int *)calloc(n * n, sizeof(int));

    initMat(mat1, n);
    initMat(mat2, n);

    printf("---- MAT 1 ----\n");
    printMat(mat1, n);

    printf("---- MAT 2 ----\n");
    printMat(mat2, n);

    multiplyMat(mat1, mat2, output, n);

    printf("---- RESULTADO ----\n");
    printMat(output, n);

    free(mat1);
    free(mat2);
    free(output);

}