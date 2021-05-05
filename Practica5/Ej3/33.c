#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_nodo{
	int dni;
	char *nombre;
	char *apellido;
	struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarLista(nodo * dirDelNodo, int nuevoDni, char * nuevoNombre, char * nuevoApe);
void eliminarDni(nodo *dirDelNodo, int borrarDni);
void imprimirLista(nodo nodoDeLista);
void eliminarApe(nodo *dirDelNodo,char *borrarApe);
void eliminarNom(nodo *dirDelNodo,char *borrarNom);

int main(){

    nodo listaDeNumeros;
    listaDeNumeros = NULL;
    int op;

    agregarLista(&listaDeNumeros, 1,"sasha","iba");
    agregarLista(&listaDeNumeros, 20,"gonza","sabaino");
    agregarLista(&listaDeNumeros, -3,"aaron","stafuza");
    agregarLista(&listaDeNumeros, 15,"jose","marti");
    agregarLista(&listaDeNumeros, 0,"sofia","plo");
    agregarLista(&listaDeNumeros, 20,"camila","amor");
    agregarLista(&listaDeNumeros, 20,"gonza","sabaino");

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);
    printf("\n");

    printf("ingresar una opcion a eliminar[1=DNI 2=NOMBRE 3=APELLIDO]: ");
    scanf("%d",&op);
    
    while(op!=1 && op!=2 && op!= 3 ){
        printf("ERROR opcion incorrecta , vuelva a ingresar otra: ");
        scanf("%d",&op);
    }

    if (op==1){
    	eliminarDni(&listaDeNumeros, 20);
    	eliminarDni(&listaDeNumeros, 0);
    }
    
    else if(op==2){
    	eliminarApe(&listaDeNumeros,"iba");
    	eliminarApe(&listaDeNumeros,"sabaino");
    }

    else if(op==3){
    	eliminarNom(&listaDeNumeros,"aaron");
    	eliminarNom(&listaDeNumeros,"sofia");
    }
   
    printf("\n-------LISTA-------\n");
    imprimirLista(listaDeNumeros);

    return 0;
}

void agregarLista(nodo * dirDelNodo, int nuevoDni, char * nuevoNombre, char * nuevoApe){
	if((*dirDelNodo)==NULL){
		(*dirDelNodo)=malloc(sizeof(struct s_nodo));
		(*dirDelNodo)->siguienteNodo=NULL;
		(*dirDelNodo)->dni= nuevoDni;
		(*dirDelNodo)->nombre=nuevoNombre;
		(*dirDelNodo)->apellido=nuevoApe;
	}
	else{
		agregarLista(&((*dirDelNodo)->siguienteNodo),nuevoDni,nuevoNombre,nuevoApe);
	}
}

void eliminarDni(nodo *dirDelNodo, int borrarDni){
	// nodo nodoAuxiliar = NULL;
	if((*dirDelNodo)!=NULL){
		if(((*dirDelNodo)->dni)==borrarDni){
			(*dirDelNodo)=(*dirDelNodo)->siguienteNodo;
			eliminarDni(dirDelNodo,borrarDni); //-->agrego esta linea si quiero eliminar todas las ocurrencias.
			}
		else{
			eliminarDni(&((*dirDelNodo)->siguienteNodo),borrarDni);
		}
	}
}

void eliminarApe(nodo *dirDelNodo,char *borrarApe){
	if((*dirDelNodo)!=NULL){
		if((strcmp(((*dirDelNodo)->apellido),borrarApe))==0){
			(*dirDelNodo)=(*dirDelNodo)->siguienteNodo;
		}
		else{
			eliminarApe(&((*dirDelNodo)->siguienteNodo),borrarApe);
		}
	}
}

void eliminarNom(nodo *dirDelNodo,char *borrarNom){
	nodo nodoAuxiliar = NULL;
	if((*dirDelNodo)!=NULL){
		if((strcmp(((*dirDelNodo)->nombre),borrarNom))==0){
			nodoAuxiliar=(*dirDelNodo);
			(*dirDelNodo)=(*dirDelNodo)->siguienteNodo;
			free(nodoAuxiliar);
		}
		else{
			eliminarNom(&((*dirDelNodo)->siguienteNodo),borrarNom);
		}
	}
}


void imprimirLista(nodo nodoDeLista){
	if(nodoDeLista!=NULL){
		printf("%d - %s - %s\n",nodoDeLista->dni, nodoDeLista->nombre,nodoDeLista->apellido);
		imprimirLista(nodoDeLista->siguienteNodo);
	}
}