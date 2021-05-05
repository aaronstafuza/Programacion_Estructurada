#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarNumeroLista(nodo * dirDelNodo, int nuevoNum);
void eliminarNumeroLista(nodo *dirDelNodo,int numEliminar);
void imprimirLista(nodo nodoDeLista);

int main(){

    nodo listaDeNumeros;
    listaDeNumeros = NULL;

    agregarNumeroLista(&listaDeNumeros, 1);
    agregarNumeroLista(&listaDeNumeros, 20);
    agregarNumeroLista(&listaDeNumeros, -3);
    agregarNumeroLista(&listaDeNumeros, 15);
    agregarNumeroLista(&listaDeNumeros, 0);

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);
    printf("\n");

    eliminarNumeroLista(&listaDeNumeros, 20);
    eliminarNumeroLista(&listaDeNumeros, 0);

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);


    return 0;
}

void agregarNumeroLista(nodo * dirDelNodo, int nuevoNum){
	if((*dirDelNodo)==NULL){
		(*dirDelNodo)=malloc(sizeof(struct s_nodo));
		(*dirDelNodo)->siguienteNodo=NULL;
		(*dirDelNodo)->valor=nuevoNum;
	}
	else{
		agregarNumeroLista(&((*dirDelNodo)->siguienteNodo),nuevoNum);
	}
}

void eliminarNumeroLista(nodo *dirDelNodo,int numEliminar){
	nodo nodoAuxiliar = NULL;
	if((*dirDelNodo)!=NULL){
		if((*dirDelNodo)->valor == numEliminar){
			// nodoAuxiliar=(*dirDelNodo);
			(*dirDelNodo)=(*dirDelNodo)->siguienteNodo;
			// free(nodoAuxiliar);
		}
	
		else{
			eliminarNumeroLista(&((*dirDelNodo)->siguienteNodo),numEliminar);
		}
	}
}

void imprimirLista(nodo nodoDeLista){
	if(nodoDeLista!=NULL){
		printf("%d\n",nodoDeLista->valor);
		imprimirLista(nodoDeLista->siguienteNodo);
	}
}