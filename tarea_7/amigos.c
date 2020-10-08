#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<math.h>

#define NTH 12

CRITICAL_SECTION cs;
int top, bottom, size;

DWORD WINAPI thread(LPVOID name){
    int amigo;
    for(int x=*((int *) name ) * size + bottom; x < top; x += size * 8){
        for(int y=x;y<x+size&&y<=top;y++){
            amigo=esAmigo(y);
            if(amigo<=top&&amigo>=bottom){
                printf("%d %d son numeros amigos\n",y,amigo);
            }
        }
    }
    
    return 0;
}

long long int esAmigo(long long int n){
    long long int friend=0;
    for(int a = 1;a < n; a++){
        friend += (n % a) ? 0 : a;
    }
    return friend;
}

int main(){
    clock_t inicio,fin;
    HANDLE tid[8];
    int args[8];
    long long int actual;
    printf("Inicio: ");
    scanf("%d",&bottom);
    printf("Final: ");
    scanf("%d",&top);

    size = sqrt( top - bottom ) * log( top - bottom);
    // Iniciamos el reloj
    inicio = clock();
    for(int i = 0; i < 8;i++){
        args[i] = i;
        tid[i] = CreateThread(NULL,0,thread,&args[i],0,NULL);
        
    }
    WaitForMultipleObjects(8,tid,1,INFINITE);
    fin = clock();
    double tiempo=(double)(fin-inicio)/1000/1000;
    printf("%lf",tiempo);
}





