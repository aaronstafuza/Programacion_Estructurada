#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a, b, c;
}t_tres;

void ordenarMayorMenor(t_tres *punteroEstructura){
    int aux;
    //Comparo a con b
    if((*punteroEstructura).a>(*punteroEstructura).b){
        aux=(*punteroEstructura).a;
        (*punteroEstructura).a=(*punteroEstructura).b;
        (*punteroEstructura).b=aux;
    }
    //Comparo a con c
    if((*punteroEstructura).a>(*punteroEstructura).c){
        aux=(*punteroEstructura).a;
        (*punteroEstructura).a=(*punteroEstructura).c;
        (*punteroEstructura).c=aux;
    }
    //Comparo b con c
    if((*punteroEstructura).b>(*punteroEstructura).c){
        aux=(*punteroEstructura).b;
        (*punteroEstructura).b=(*punteroEstructura).c;
        (*punteroEstructura).c=aux;
    }
}

int main(){
    t_tres estructuraTresNum;

    printf("Ingrese el valor (a): ");
    scanf("%d",&estructuraTresNum.a);

    printf("Ingrese el valor (b): ");
    scanf("%d",&estructuraTresNum.b);

    printf("Ingrese el valor (c): ");
    scanf("%d",&estructuraTresNum.c);

    ordenarMayorMenor(&estructuraTresNum);

    printf("Numeros ordenados: \n");
    printf("%d\n",estructuraTresNum.a);
    printf("%d\n",estructuraTresNum.b);
    printf("%d\n",estructuraTresNum.c);

    return 0;
}