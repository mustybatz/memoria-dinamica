#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LIST_INITIALIZER \
    {                    \
        NULL, NULL       \
    }

typedef struct STRNODO
{
    int num;
    struct STRNODO *next;
    struct STRNODO *prev;
} NODO;

typedef struct
{
    struct STRNODO *head;
    struct STRNODO *tail;
} LIST;

unsigned int factores = 0;

int esprimo(int n)
{
    int primo = 0;
    int factor = 3;
    int limite = sqrt(n);

    if (n < 2)
        primo = 0;
    else if (n == 2)
        primo = 1;
    else if (n % 2 == 0) // es un par mayor a 4
        primo = 0;
    else
    {
        factores++;
        while (factor <= limite && n % factor)
        {
            factor += 2;
            factores++;
        }

        primo = factor > limite;
    }
    return (primo);
}

void list_insert(LIST *l, int num)
{
    NODO *new = malloc(sizeof(NODO));
    new->num = num;
    new->next = NULL;

    if (l->head == NULL)
    {
        l->head = new;
    }

    else
    {
        l->tail->next = new;
        new->prev = l->tail;
    }

    l->tail = new;
    return;
}

/**
 * Despliega la lista en la pantalla, 
 * Recibe una lista L y un carácter que 
 * especifica si se va a desplegar de manera
 * ascendente o descendente, se tiene que enviar 'a' o 'd'
 * @param{List l, char modoDespliegue}
 * */
void list_display(LIST l, char modoDespliegue)
{
    if (modoDespliegue == 'a')
    {
        NODO *ptr = l.head;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->num);
            ptr = ptr->next;
        }
    }

    else
    {
        NODO *ptr = l.tail;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->num);
            ptr = ptr->prev;
        }
    }
}

int main()
{
    int inicio, fin;
    int i, count = 0;
    int tiempo;
    LIST lista1 = LIST_INITIALIZER;
    clock_t tinicio, tfin;

    setbuf(stdout, NULL);

    char choise;
    printf("Como quieres desplegar los numeros, en manera ascendente o descendente? a/d: ");
    scanf("%C", &choise);

    printf("Valor inicial :");
    scanf("%d", &inicio);
    printf("Valor final :");
    scanf("%d", &fin);

    
    tinicio = clock();
    for (i = inicio; i <= fin; i++)
        if (esprimo(i))
        {
            count++;
            list_insert(&lista1, i);
        }
    tfin = clock();
    tiempo = ((int)tfin - (int)tinicio) / 1000;
    printf("%d primos encontrados entre %d y %d\n", count, inicio, fin);
    printf("Factores=%d\n", factores);
    printf("Tiempo = %d segundos\n", tiempo);
    list_display(lista1, choise);
}