#include <stdio.h>
#include <stdlib.h>

void imprimirRepresentacionBinariaDeChar(char caracter);

int main()
{
    imprimirRepresentacionBinariaDeChar('a');
    imprimirRepresentacionBinariaDeChar('A');
    return 0;
}

void imprimirRepresentacionBinariaDeChar(char caracter){
    int contador;
    int resultado;

    int mascara = 0b10000000;

    for(contador = 0; contador < 8 ; contador++){
        resultado = caracter & mascara;
        //caracter = 01100011 --- 11000110 --- 10001100 --- 00011000 -- 
        //mascara = 10000000

        if(resultado == mascara){
            printf("1");
        }
        else{
            printf("0");
        }

        caracter = caracter << 1;
    }
    
    printf("\n");

}
