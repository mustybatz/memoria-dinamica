#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>

#define THREAD_COUNT 6

typedef struct
{
    int start;
    int end;
    void *param;
} ForData;

typedef DWORD (*ParallelFunc)(ForData *);

void parallel_for(ParallelFunc func, int start, int end, void *param)
{
    ForData data[THREAD_COUNT];
    HANDLE threads[THREAD_COUNT];

    int step = (end - start) < THREAD_COUNT ? 1 : (end - start) / THREAD_COUNT;
    int func_i = 0;

    int factor = min(end - start, THREAD_COUNT);

    for (int i = 0; i < factor; ++i)
    {
        data[i].start = i != 0 ? data[i - 1].end + 1 : func_i;
        func_i += step;
        data[i].end = i == factor - 1 ? end : func_i;
        data[i].param = param;
        threads[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)func, data + i, 0, NULL);
    }

    WaitForMultipleObjects(factor, threads, TRUE, INFINITE);
}

bool is_prime(unsigned n)
{
    if ((n % 2 == 0 && n > 2) || n <= 1){
        return false;
    }

    for (int i = 3; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

DWORD is_prime_parallel(ForData *data)
{
    long count = 0;

    for (unsigned i = data->start; i <= data->end; ++i)
    {
        count += is_prime(i);
    }

    InterlockedAdd(data->param, count);
    return 0;
}

int main()
{
    long contador = 0;
    int start = 0;
    int end = 0;

    printf("Principio: ");
    scanf("%d", &start);
    printf("Fin: ");
    scanf("%d", &end);

    time_t t0 = clock();
    parallel_for(is_prime_parallel, start, end, &contador);
    time_t t1 = clock();
    double time_taken = ((double)(t1 - t0)) / CLOCKS_PER_SEC;
    printf("Hay %d primos en el rango [%d, %d], tomo: %f segundos", contador, start, end, time_taken);
}