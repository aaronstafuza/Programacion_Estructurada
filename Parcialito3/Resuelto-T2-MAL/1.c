//AARON STAFUZA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct{
	char txt[100];
	char car;	
	int cantidad_caracter;
}t_refran;

struct s_nodo{ 
	t_refran ref;
	struct s_nodo *sig;
};
typedef struct s_nodo * t_nodo;

void cargarLista(t_nodo *lista);
void agregarNumLista(t_nodo *dirDelNodo,t_refran valor);
void imprimir(t_nodo lista);
int esCaracter(char *n,char car,int cont);

int main(){
	t_nodo lista=NULL;
	cargarLista(&lista);
	printf("\nRefran ---- Caracter ---- Cantidad\n");
	imprimir(lista);
	return 0;
}

void cargarLista(t_nodo *lista){
	t_refran aux;
	char letra;
	char arreglo[N];
	char caracter;
	int i=0,j=0;
	int cuentaCaracter;

	FILE * arch;
    arch=fopen("refranes.txt","r");
    if (arch==NULL){
        printf("El archivo no existe");
    }
    else{
        letra=fgetc(arch);
        while (letra!=EOF &&letra!=10){
            while(letra!=','){
                arreglo[i]=letra;
                i++;
                letra=fgetc(arch);
            }

			arreglo[i]='\0';
			strcpy(aux.txt,arreglo);
			caracter=arreglo[-1];
			strcpy(aux.car,caracter);
			printf("%s",aux.txt);

			// caracter=fgetc(arch);
			// aux.car=caracter;

			// cuentaCaracter=esCaracter(aux.txt,aux.car,j);
			// aux.cantidad_caracter=1;

			agregarNumLista(lista,aux);

			letra=fgetc(arch);
			i=0;
		}
	}
	fclose(arch);
}

void agregarNumLista(t_nodo *dirDelNodo,t_refran valor){
	if((*dirDelNodo)==NULL){
		(*dirDelNodo)=malloc(sizeof(struct s_nodo));
		(*dirDelNodo)->ref = valor;
		(*dirDelNodo)->sig=NULL;
	}
	else{
		agregarNumLista(&((*dirDelNodo)->sig),valor);
	}
}

void imprimir(t_nodo lista){
    if (lista !=NULL){
        printf("%s ",lista->ref.txt);
        imprimir(lista->sig);
    }
}

int contar(char *frase, char n, int cont){
	if(frase[cont]!='\0'){
		if(frase[cont]==n){
			return 1+contar(frase,n,cont+1);
		}
		else{
			return contar(frase,n,cont+1);
		}
	}
}
// int esCaracter(char *n,char car,int cont){
// 	int cantidad;
// 	if(n[cont]==car){
// 		cantidad++;

// 		return 1+ esCaracter(n,car,cont+1);
// 	}
// 	else{

// 		esCaracter(n,car,cont+1);
// 	}
// 	return 0;
// }











