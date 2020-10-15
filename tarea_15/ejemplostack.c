#include <stdio.h>
#include "stack.h"

int main()
{
    int n;
    STACK stack = stack_create();

    n = 1;
    stack_push_int(stack, n);
    n = 2;
    stack_push_int(stack, n);
    n = 3;
    stack_push_int(stack, n);

    printf("%d\n", stack_pop_int(stack));

    printf("%d\n", stack_pop_int(stack));

    printf("%d\n", stack_pop_int(stack));
}
