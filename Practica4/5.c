#include <stdio.h>
#include <stdlib.h>

int maximo(int * arreglo);
int *maximoDir(int * arreglo);

int main(){
    int arreglo[] = {1,5,6,-5,6,122,45,12,5,6,0};
    printf("%d\n",maximo(arreglo));
    int * maximoDireccion = maximoDir(arreglo);
    printf("%d\n",*maximoDireccion); //prueba de que esta bien la direcicon de memoria
    printf("%p\n",maximoDireccion);
}

int maximo(int * arreglo){

    int max=0,m=0;
    max=*arreglo;
    if(*arreglo!=0){
        arreglo++;
        m=maximo(arreglo);
        if(m>max){
            max=m;
        }
    }
    return max;
}

int *maximoDir(int *arreglo){
    int *max = NULL;
    int *m = NULL;
    max=arreglo;
    if(*arreglo!=0){
        arreglo++;
        m=maximoDir(arreglo);
        if((*m)>(*max)){
            max=m;
        }
    }
    return max;
}