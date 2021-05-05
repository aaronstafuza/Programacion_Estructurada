#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo *siguienteNodo;
};

typedef struct s_nodo * nodo;


void agregarNumeroLista(nodo * dirDelNodo, int nuevoNumero);
void imprimirLista(nodo nodoDeLista);
void imprimirListaReversa(nodo nodoDeLista);


int main(){
    nodo listaDeNumeros;
    listaDeNumeros=NULL;

    agregarNumeroLista(&listaDeNumeros,1);
    agregarNumeroLista(&listaDeNumeros,20);
    agregarNumeroLista(&listaDeNumeros,-3);
    agregarNumeroLista(&listaDeNumeros,15);
    agregarNumeroLista(&listaDeNumeros,0);

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);
    printf("\n");
    printf("---LISTA REVERSA---\n");
    imprimirListaReversa(listaDeNumeros);

    return 0;
}

void agregarNumeroLista(nodo * dirDelNodo, int nuevoNumero){
    if(*(dirDelNodo)==NULL){  //me tengo que fijar siempre que la direccion del nodo no sea NULL.
        (*dirDelNodo) = malloc(sizeof(struct s_nodo)); //agrego memoria dinamica al nodo, de tipo struct s_nodo
        (*dirDelNodo) -> siguienteNodo = NULL; //limpio direccion siguiente 
        //*dirDelNodo.siguienteNodo=NULL;
        (*dirDelNodo) -> valor = nuevoNumero; //agrego valor en el nodo que estoy 
    }
    else{
        agregarNumeroLista(&((*dirDelNodo)->siguienteNodo),nuevoNumero); //si hay algo en ese nodo, voy al siguiente 
    }
}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista!=NULL){
        printf("%d\n",nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}

void imprimirListaReversa(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        imprimirListaReversa(nodoDeLista->siguienteNodo);
        printf("%d\n",nodoDeLista->valor);
    }
}


