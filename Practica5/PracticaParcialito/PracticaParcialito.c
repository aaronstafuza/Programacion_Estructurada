#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo *nodo;

void agregarNumeroLista(nodo * dirDelNodo, int nuevoNumero);
void sumarValores(nodo nodoDeLista,int cont);
void imprimirLista(nodo nodoDeLista);

int main(){
	nodo listaDeNumeros;
	listaDeNumeros=NULL;
	int cont=0;
	agregarNumeroLista(&listaDeNumeros,11);
	agregarNumeroLista(&listaDeNumeros,1);
	agregarNumeroLista(&listaDeNumeros,14);
	agregarNumeroLista(&listaDeNumeros,16);
	agregarNumeroLista(&listaDeNumeros,4);
	agregarNumeroLista(&listaDeNumeros,5);

	imprimirLista(listaDeNumeros);
	printf("\n");
	sumarValores(listaDeNumeros,cont);
	printf("\n");

}

void agregarNumeroLista(nodo * dirDelNodo, int nuevoNumero){
	if((*dirDelNodo)==NULL){
		(*dirDelNodo)=malloc(sizeof(struct s_nodo));
		(*dirDelNodo)->siguienteNodo=NULL;
		(*dirDelNodo)->valor=nuevoNumero;
	}
	else{
		agregarNumeroLista(&((*dirDelNodo)->siguienteNodo),nuevoNumero);
	}
}

void sumarValores(nodo nodoDeLista,int cont){
	if(nodoDeLista!=NULL){
		cont=cont+(nodoDeLista->valor);
		sumarValores(nodoDeLista->siguienteNodo,cont);
	}
	else{
		printf("%d",cont);
	}
}

void imprimirLista(nodo nodoDeLista){
	if(nodoDeLista!=NULL){
		printf("%d\n",nodoDeLista->valor);
		imprimirLista(nodoDeLista->siguienteNodo);
	}
}