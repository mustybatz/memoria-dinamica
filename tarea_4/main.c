#include <stdio.h>
#define R 3
#define C 3

int max(int mat[R][C])
{
    int i,j,currentMax;
    for (i = 0; i < R; i++)
    {   
        
        for (j = 0; i < C; j++)
        {
            
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int mat[R][C] = {{1,2,3}, {-1,-2,0}, {2,4,-3}};
    int *ptmat[C];

    for (int i = 0; i < C; i++)
    {
        ptmat[i] = &mat[i][0]
    }
    
    int n = max(mat);

    return 0;
}
