#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<math.h>

CRITICAL_SECTION cs;

int inicio, fin, total = 0;

int isPrime(int numero);
DWORD WINAPI hilo(LPVOID arg);

int main(){
    printf("Inicio: ");
    scanf("%d",&inicio);
    printf("Fin: ");
    scanf("%d",&fin);
    
    clock_t i,f;
    HANDLE thread[5];
    void *function = hilo;
    int sequence[10]={};

    double time;
    i = clock();
    InitializeCriticalSection(&cs);
    for(int i = 0;i < 5;++i){
        sequence[i] = i;
        thread[i] = CreateThread(NULL, 0, hilo, &sequence[i], 0, NULL);
    }
    WaitForMultipleObjects(5, thread, TRUE, INFINITE);
    DeleteCriticalSection(&cs);
    f = clock();
    
    time = (double)(f-i)/1000;
    printf("Tarde: %f segundos\n",time);
    printf("Hay %d primos en el rango",total);
}

int isPrime(int n){
    int primo = 0;
    int factor = 3;
    int limite = sqrt(n);
    if( n < 2 ){
        primo = 0;
    }
    else if( n == 2 ){
        primo = 1;
    }
    else if( n % 2 == 0 ){
        primo = 0;
    }
    else{
        while(factor<=limite&&n%factor){
            factor += 2;
        }
        primo = factor > limite;
    }
    return primo;
}


DWORD WINAPI hilo(LPVOID arg){
    int myNum = *((int *) arg);
    int i = ((fin-inicio)* myNum)/5 + inicio;
    int f = ((fin-inicio)*(myNum + 1))/5 + inicio;
    int cantidad = 0;
    for(int i = i; i < f;i++){
        if(isPrime(i)){
            cantidad++;
        }
    }
    EnterCriticalSection(&cs);
    total+=cantidad;
    LeaveCriticalSection(&cs);
}

