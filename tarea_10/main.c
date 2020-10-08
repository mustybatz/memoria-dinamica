#include <stdio.h>
#include "rectangulo.h"

int main()
{
    rectangulo r1=new_rectangle(10.0,20.0);

    printf("Base del rectángulo %f\n",base(r1));           // Deberá mostrar 10 en pantalla
    printf("Altura del rectángulo %f\n",height(r1));       // Deberá mostrar 20 en pantalla
    printf("Área del rectángulo %f\n",area(r1));           // Deberá mostrar 200 en pantalla
    printf("Perínetro del rectángulo %f\n",perimeter(r1));  // Deberá mostrar 60 en pantalla

    set_base(r1,12.0);
    set_height(r1,15.0);

    printf("Base del rectángulo %f\n",base(r1));           // Deberá mostrar 12 en pantalla
    printf("Altura del rectángulo %f\n",height(r1));       // Deberá mostrar 15 en pantalla
}