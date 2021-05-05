// Crear una función recursiva que retorne el cociente de dos 
// números enteros en función de la resta.

#include <stdio.h>
#include <stdlib.h>

int dividirDosNum(int dividendo, int divisor);

int main(){

    printf("%d\n", dividirDosNum(-15,5));
    return 0;
}

int dividirDosNum(int dividendo, int divisor){

    int resta = dividendo - divisor;

    if(divisor==0 || dividendo==0){
        return 0;
    }

    if(divisor > 0 && dividendo > 0 && resta >= 0){
        return 1 + dividirDosNum(resta,divisor);
    }
    //Esto solo sera ejecutado (o no, en el caso que ambos numeros sean positivos) la primera vez que se entra
    else if(divisor < 0 && dividendo < 0){
        return dividirDosNum(-dividendo,-divisor);
    }
    else if(divisor > 0 && dividendo < 0){
        return -dividirDosNum(dividendo,-divisor);
    }
    else if(divisor < 0 && dividendo > 0){
        return -dividirDosNum(-dividendo,divisor);
    }
    else{
        return 0;
    }
        
}