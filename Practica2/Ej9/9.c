// Realizar una función que efectúe el SHIFT A DERECHA completando 
// con 0 desde la izquierda. Aplicarla en un programa de ejemplo.
#include <stdio.h>
#include <stdlib.h>

char shiftearAlaIzq(char);

int main(){
    printf("%d", shiftearAlaIzq(0b11111111));
}

char shiftearAlaIzq(char n){
    int mascara = 0b01111111;
    int resultado = (n >> 1) & mascara;

    return resultado;
}


/*
And: 
    1-1 = 1
    0-0 = 1
    1-0 = 0
    0-1 = 0
    0 Falso
    1 Verdadero

*/