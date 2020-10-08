#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int min, int max)
{
    srand(time(NULL));
    int rnd = rand();
    return (rnd % (20 - 2 + 1)) + 2;
}

int main()
{

    int R = random(2, 20), index = 1, fp1;

    for (int i = 0; i < R; i++)
    {

        printf("[");
        for (int j = 0; j <= i  ; j++)
        {
            if (j  == i )
            {
                printf("%d", index);
            }
            else
            {
                printf("%d,", index);
            }
        }
        printf("]\n");
        index++;
    }
}