#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    while (1)
    {
        ptr = (int *)malloc(64 * sizeof(int));

        if (ptr == NULL)
        {
            printf("La memoria no fue allocada.\n");
            exit(0);
        }

        // La razón de cambio de cada impresión depende de 
        // en cuanto tiempo se pida memoria y en cuanto tiempo se demora,
        // varía en cada equipo.

        *(ptr + 10) = 5000;
        printf("Memoria inicial: %p\n", ptr);
        free(ptr);

        /**
         * Si le pido que muestre la dirección de memoria apuntada por ptr 
         * ¿Qué imprime el programa? Escribe tu respuesta en un comentario dentro del mismo programa.
         * 
         * En este punto se imprimiria la dirección de memoria inicial, que pertenece al bloque
         * de memoria dinámica.
         * /

    }
}