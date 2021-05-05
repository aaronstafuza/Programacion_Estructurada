#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int dni;
    char * nombre;
    char * apellido;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void imprimirLista(nodo nodoDeLista);
void agregarLista(nodo * dirDelNodo, int nuevoDni, char *nuevoNom, char *nuevoApellido);

int main(){
    nodo listaDeNumeros;
    listaDeNumeros=NULL;

    agregarLista(&listaDeNumeros,40190,"aaron","stafuza");
    agregarLista(&listaDeNumeros,31213,"sasha","ibanez");

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);
    printf("\n");
    return 0;
}

void agregarLista(nodo * dirDelNodo, int nuevoDni, char *nuevoNom, char *nuevoApellido){
    if((*dirDelNodo)==NULL){
        (*dirDelNodo)=malloc(sizeof(struct s_nodo));
        (*dirDelNodo)->siguienteNodo = NULL;
        (*dirDelNodo)->dni = nuevoDni;
        (*dirDelNodo)->nombre = nuevoNom;
        (*dirDelNodo)->apellido= nuevoApellido;    
    }
    else{
        agregarLista(&((*dirDelNodo)->siguienteNodo),nuevoDni,nuevoNom,nuevoApellido);
    }
}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista!=NULL){
        printf("%d - %s - %s\n",nodoDeLista->dni,nodoDeLista->nombre,nodoDeLista->apellido);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}

