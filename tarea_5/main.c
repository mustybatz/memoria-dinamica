#include <Windows.h>
#include <stdio.h>

void hello_world(LPVOID id)
{
    printf("Hola desde el hilo %zu\n", id);
}

int main()
{
    HANDLE threads[4];
    void *function = hello_world;
    for (size_t i = 0; i < 4; i++)
    {
        threads[i] = CreateThread(NULL, 0, function, (LPVOID) i, 0, NULL);
        WaitForMultipleObjects(4, threads, TRUE, INFINITE );
    }
    
}