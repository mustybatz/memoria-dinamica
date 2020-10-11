#include <stdio.h>
#include <stdlib.h>

void multiplyMatrix(int A[3][3], int B[3][3], int C[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main()
{
    FILE *AFile = fopen("A.bin", "rb");
    FILE *BFile = fopen("B.bin", "rb");
    FILE *CFile = fopen("C.bin", "wb");

    int A[3][3], B[3][3], C[3][3];
    fread(A, sizeof(int[3][3]), 1, AFile);
    fread(B, sizeof(int[3][3]), 1, BFile);
    fclose(AFile);
    fclose(BFile);

    multiplyMatrix(A, B, C);
    fwrite(&C, sizeof(int[3][3]), 1, CFile);
    fclose(CFile);

}