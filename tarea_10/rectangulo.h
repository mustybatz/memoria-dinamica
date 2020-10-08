#ifndef stdlib
    #include <stdlib.h>
#endif

#include <stdio.h>

struct Rectangulo{
    float base,altura;
};

typedef struct Rectangulo *rectangulo;

rectangulo new_rectangle(){
    rectangulo n;
    n = malloc(sizeof(struct Rectangulo));
    n->base = 1;
    n->altura = 4;
    return n;
}

float base(rectangulo n){
    return n->base;
}

float height(rectangulo n){
    return n->altura;
}

float area(rectangulo n){
    return (n->altura) * (n->base);
}

float perimeter(rectangulo n){
    return 2 * (n->altura) + 2 * (n->base);
}

void set_height(rectangulo n, float b){
    n->altura = b;
}

void set_base(rectangulo n, float b){
    n->base = b;
}
