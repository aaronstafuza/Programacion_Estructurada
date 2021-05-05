#include <stdio.h>
#include <stdlib.h>

void redondear(double *punteroNum){
    int num;
    num=*punteroNum;
    if(*punteroNum-num>0.6){
        *punteroNum=num+1;
    }
    else{
        *punteroNum=num;
    }
}


int main(){
    double numero;
    printf("Ingrese numero: ");
    scanf("%lf",&numero);

    redondear(&numero);
    printf("Numero redondeado: %.2lf\n",numero);

    return 0;
}
