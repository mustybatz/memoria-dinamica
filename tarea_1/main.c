
#include <stdio.h>
#include <math.h>

int length(char *str){
    int i;
    
    for ( i = 0; *str != '\0' ; str++)
    {
        i++;
    }

    return i;

}

void swap(int *a, int *b){
    int prison_cell = *a;
    *a = *b;
    *b = prison_cell;
}

struct Vector {
    float x;
    float y;
};

void unitVector(struct Vector *vec){
    float magnitud =  sqrt( pow( vec->x,2 ) + pow( vec->y,2 ) );
    vec->x = vec->x / magnitud;
    vec->y = vec->y / magnitud;
}

int main(int argc, char const *argv[])
{
    int a = 35;
    int b = 40;

    // Longitud de string
    printf("El string mide: %d caracteres\n", length("hola mundo"));

    // Valores antes del swap
    printf("La variable a vale: %d y b vale: %d \n", a, b);
    swap(&a, &b);
    // Valores después del swap
    printf("La variable a vale: %d y b vale: %d\n", a, b);

    struct Vector test_vector = { 3.0, 4.0 };
    unitVector(&test_vector);
    printf("El vector unitario es: {%f,%f}", test_vector.x, test_vector.y);
    return 0;
}
