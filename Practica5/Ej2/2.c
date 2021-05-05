#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void insertarNumeroLista(nodo * dirDelNodo, int nuevoNum);
void imprimirLista(nodo nodoDeLista);

int main()
{
    nodo listaDeNumeros = NULL;

    insertarNumeroLista(&listaDeNumeros, 1);
    insertarNumeroLista(&listaDeNumeros, 20);
    insertarNumeroLista(&listaDeNumeros, 5);
    insertarNumeroLista(&listaDeNumeros, 0);
    insertarNumeroLista(&listaDeNumeros, 30);
    insertarNumeroLista(&listaDeNumeros, -14);

    imprimirLista(listaDeNumeros);

    return 0;
}

void insertarNumeroLista(nodo * dirDelNodo, int nuevoNum){
    nodo nodoAuxiliar = NULL;

    if((*dirDelNodo)==NULL || ((*dirDelNodo)->valor)>nuevoNum){ // se tiene que cumplir asi como esta el IF, sino no funca
        nodoAuxiliar=malloc(sizeof(struct s_nodo));  //agrego memoria al nodo auxiliar
        nodoAuxiliar->siguienteNodo = (*dirDelNodo); //al siguiente nodo, le paso la direccion del nodo mayor
        nodoAuxiliar->valor=nuevoNum; //al nuevo nodo, le agrego el nuevo valor (menor)
        (*dirDelNodo)=nodoAuxiliar;  //el nodo donde estoy, valor auxiliar
    }

    else{
        insertarNumeroLista(&((*dirDelNodo)->siguienteNodo),nuevoNum);
    }
}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n",nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}
