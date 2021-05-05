#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a, b;
}t_dosint;

void intercambiarVariables(int * puntero1, int * puntero2){
    int memoriaDeNumero;
    
    memoriaDeNumero = *puntero1;
    *puntero1 = *puntero2;
    *puntero2 = memoriaDeNumero;
}

int main(){
    t_dosint structEnteros;
    structEnteros.a=5;
    structEnteros.b=10;
    printf("Numero 1: %d\n",structEnteros.a);
    printf("Numero 2: %d\n\n",structEnteros.b);

    printf("Intercambio:\n");

    intercambiarVariables(&structEnteros.a,&structEnteros.b);

    printf("Numero 1: %d\n",structEnteros.a);
    printf("Numero 2: %d\n",structEnteros.b);
    
    return 0;
}