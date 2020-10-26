#include <stdio.h>

void printptrarr(char **array, int n)
{
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            printf("%c", *(*(array + a) + b));
        }
        printf("\n");
    }
}

int main()
{
    char *lista[12];
    char array[][10] = {"Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Once", "Doce"};

    for (int i = 0; i < 12; i++)
    {
        lista[i] = array[i];
    }

    printptrarr(lista, 7);
}