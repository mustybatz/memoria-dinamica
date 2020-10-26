#include <stdio.h>

void imprimirdoble(int a)
{
    printf("%d\n", 2 * a);
}

void imprimirrriple(int a)
{
    printf("%d\n", 3 * a);
}

int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}

int main()
{
    void (*func_a)(int) = imprimirdoble;
    func_a(3);
    func_a = imprimirrriple;
    func_a(3);
    int (*func_b)(int, int) = sumar;
    printf("%d\n", func_b(3, 4));
    func_b = restar;
    printf("%d\n", func_b(3, 4));
}
