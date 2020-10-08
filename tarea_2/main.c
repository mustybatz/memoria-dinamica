#include <stdio.h>
#include <string.h>

int length(char *str)
{
    int i;

    for (i = 0; *str != '\0'; str++)
    {
        i++;
    }

    return i;
}

void swap(char *a, char *b)
{
    char chr = *b;
    *b = *a;
    *a = chr;
}

void reverse(char *str)
{
    int strLenght, i, middle;
    char *begin, *end, chr;

    strLenght = length(str);
    middle = strLenght / 2;

    begin = str;
    end = str;

    // Mover el puntero al final
    for (i = 0; i < strLenght - 1; i++)
    {
        end++;
    }

    for (i = 0; i < middle; i++)
    {
        swap(begin, end);

        // Mover los punteros
        begin++;
        end--;
    }
}

int compareStr(char *string1, char *string2)
{
    if (*string1 == '\0' && *string2 == '\0')
    {
        return 0;
    }
    else if (*string1 > *string2)
    {
        return 1;
    }
    else if (*string1 < *string2)
    {
        return -1;
    }
    return compareStr(string1 + 1, string2 + 1);
}


void sortnames(char (*names)[10])
{
    int i, j;
    char temp[10];
    

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if( strcmp(*(names + j), *(names + j + 1)) > 0){
                strcpy(temp, *(names + j));
                strcpy(*(names + j), *(names + j + 1));
                strcpy(*(names + j + 1), temp);
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    char str[] = "Hola mundo";

    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);

    char nombres[10][10]= {"Juán","José","Gaby","María","Karla","Luis","Antonio","Cecilia","Roberto","Francisdo"};

    // Pedir nombres por consola
    /* char(*ptr)[10] = nombres;
    int cnt = 0;

    for (cnt = 0; cnt < 10; cnt++)
    {
        printf("Ingresa la palabra %d: ", cnt + 1);
        scanf("%s", ptr);
        ptr++;
    } */

    sortnames(nombres);

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", nombres[i]);
    }
    
   

    return 0;
}
