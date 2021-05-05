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

void imprimirLista(nodo nodoDeLista);
void ordenarPorDni(nodo * dirDelNodo, int nuevoDni, char*nuevoNom, char*nuevoApe);
void ordenarPorNombre(nodo * dirDelNodo, int nuevoDni, char*nuevoNom, char*nuevoApe);
void ordenarPorApellido(nodo * dirDelNodo, int nuevoDni, char*nuevoNom, char*nuevoApe);

int main(){
    nodo listaDeNumeros;
    listaDeNumeros=NULL;
    int op;
    printf("Ingresar opcion a ordenar (1 DNI - 2 NOMBRE - 3 APELLIDO): ");
    scanf("%d",&op);

    while (op!=3 && op!=2 && op!=1){
        printf("Error al ingreso de la opcion. Ingrese nuevamente: ");
        scanf("%d",&op);
    }

    if (op==1){
        ordenarPorDni(&listaDeNumeros,40190,"aaron","stafuza");
        ordenarPorDni(&listaDeNumeros,31213,"sasha","ibanez");
        ordenarPorDni(&listaDeNumeros,22241,"ricardo","gomez");
    }

    else if(op==2){
        ordenarPorNombre(&listaDeNumeros,40190,"aaron","stafuza");
        ordenarPorNombre(&listaDeNumeros,31213,"sasha","ibanez");
        ordenarPorNombre(&listaDeNumeros,22241,"ricardo","gomez");
    }

    else{
        ordenarPorApellido(&listaDeNumeros,40190,"aaron","stafuza");
        ordenarPorApellido(&listaDeNumeros,31213,"sasha","ibanez");
        ordenarPorApellido(&listaDeNumeros,22241,"ricardo","gomez");
    }

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);
    printf("\n");
    return 0;
}


void ordenarPorDni(nodo * dirDelNodo, int nuevoDni, char * nuevoNom, char * nuevoApe){
	nodo nodoAuxiliar = NULL;

    if(((*dirDelNodo) == NULL) || ((*dirDelNodo)->dni),nuevoDni){
        nodoAuxiliar = malloc(sizeof(struct s_nodo));
        nodoAuxiliar->siguienteNodo = (*dirDelNodo);
        nodoAuxiliar->dni = nuevoDni;
        nodoAuxiliar->nombre = nuevoNom;
        nodoAuxiliar->apellido = nuevoApe;
        (*dirDelNodo) = nodoAuxiliar;
    
    }
    
    else{
        ordenarPorDni(&((*dirDelNodo)->siguienteNodo),nuevoDni,nuevoNom,nuevoApe);
    }
}

void ordenarPorNombre(nodo * dirDelNodo, int nuevoDni, char * nuevoNom, char * nuevoApe){
    nodo nodoAuxiliar = NULL;

    if((*dirDelNodo) == NULL || (strcmp(((*dirDelNodo)->nombre),nuevoNom)>0)){
        nodoAuxiliar=malloc(sizeof(struct s_nodo));
        nodoAuxiliar->siguienteNodo=(*dirDelNodo);
        nodoAuxiliar->dni=nuevoDni;
        nodoAuxiliar->nombre=nuevoNom;
        nodoAuxiliar->apellido=nuevoApe;
        (*dirDelNodo)=nodoAuxiliar;
    }
    else{
        ordenarPorNombre(&((*dirDelNodo)->siguienteNodo),nuevoDni,nuevoNom,nuevoApe);
    }
}

void ordenarPorApellido(nodo * dirDelNodo, int nuevoDni, char * nuevoNom, char * nuevoApe){
    nodo nodoAuxiliar= NULL;

    if((*dirDelNodo) == NULL || (strcmp(((*dirDelNodo)->apellido),nuevoApe)>0)){
        nodoAuxiliar=malloc(sizeof(struct s_nodo));
        nodoAuxiliar->siguienteNodo=(*dirDelNodo);
        nodoAuxiliar->dni=nuevoDni;
        nodoAuxiliar->nombre=nuevoNom;
        nodoAuxiliar->apellido=nuevoApe;
        (*dirDelNodo)=nodoAuxiliar;
    }
    else{
        ordenarPorApellido(&((*dirDelNodo)->siguienteNodo),nuevoDni,nuevoNom,nuevoApe);
    }
    
}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d - %s - %s\n",nodoDeLista->dni,nodoDeLista->nombre,nodoDeLista->apellido);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}
