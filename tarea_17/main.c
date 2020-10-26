#include "list.c"
#include <stdio.h>

int main()
{
    LIST list = list_create();
    ITERATOR iterator;
    int num;
    int i;

    setbuf(stdout, NULL);
    for (i = 0; i < 10; i++)
    {
        printf("Dame un número :");
        scanf("%d", &num);
        list_insert_int(list, num);
    }

    iterator = list_begin(list);
    while (has_next(iterator))
    {
        iterator = list_next(iterator);
        num = iterator_data(iterator);
        printf("%d\n", num);
    }
    printf("\n");
    iterator = list_end(list);
    while (has_prior(iterator))
    {
        iterator = list_prior(iterator);
        num = iterator_data(iterator);
        printf("%d\n", num);
    }
}