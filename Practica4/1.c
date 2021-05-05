// Crear una función recursiva que retorne el producto de dos números 
// enteros en función de la suma.

#include <stdio.h>
#include <stdlib.h>

int multiplicarDosNum(int n1, int n2);

int main(){
    printf("%d\n",multiplicarDosNum(45,2));
    printf("%d\n",multiplicarDosNum(-2,-50));
    printf("%d\n",multiplicarDosNum(10,7));
    return 0;
}

int multiplicarDosNum(int n1, int n2){
    if(n2==0){
        return 0;
    }

    if(n2>0){
        return n1+multiplicarDosNum(n1,n2-1);
    }

    else if(n2<0){
        return -n1+multiplicarDosNum(n1,n2+1);
    }

    else{
        return n1;
    }
}