#include <stdio.h>
#include <stdlib.h>

void ordenarVector(int *arreglo);
int *minimoDir(int *arreglo);

int main(){
    int i, longitud_arr;

    int arreglo[] = {1,5,6,-5,6,122,45,12,5,6,0};
    printf("\nValor minimo: %d\n",*minimoDir(arreglo));

    int * minimoDireccion = minimoDir(arreglo);
    // printf("%d\n",*minimoDireccion); //prueba de que esta bien la direcicon de memoria
    printf("Direccion de memoria minimo: %p\n",minimoDireccion);
    
    ordenarVector(arreglo);
    for(i=0;arreglo[i]!=0;i++){
        longitud_arr=i;
    }
    for(i=0;arreglo[i]!=0;i++){
        if(i==0){
            printf("Arreglo ordenado: [%d,",arreglo[i]);
        }
        else if(i<longitud_arr){
            printf("%d,",arreglo[i]);
        }
        else{
            printf("%d]\n\n",arreglo[i]);
        }
    }
    return 0;
}

int *minimoDir(int *arreglo){
    int *min,*m;
    // int *x;
    // x=arreglo;
    min=arreglo;
    if(*arreglo!=0){
        arreglo++;
        m=minimoDir(arreglo);
        if((*m<*min) && *arreglo!=0){
            min=m;
        }
    }
    return min;
}

void ordenarVector(int *arreglo){
    int *m,*a;
    int aux;
    a=arreglo;

    if(*arreglo!=0){
        m=minimoDir(arreglo);
        aux=*arreglo;
        *arreglo=*m;
        *m=aux;
        arreglo++;
        ordenarVector(arreglo);
    }
}