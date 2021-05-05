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
	return 0;
}

void cargarLista(t_nodo *lista){
	t_refran aux;
	char letra;
	char arreglo[N];
	int i=0;

	FILE *arch;
	arch=fopen("refranes.txt","r");
	if(arch==NULL){
		printf("El archivo no existe");
	}
	else{
		letra=fgetc(arch);
		while(letra!=EOF){
			while(letra!=','){
				arreglo[i]=letra;
				i++;
				letra=fgetc(arch);
			}
			
		}
	}
}










