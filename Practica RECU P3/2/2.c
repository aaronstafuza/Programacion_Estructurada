#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 70

typedef struct{
	char articulo[70];
	float precio;	
	int cantidad;
	int id;
}t_producto;

struct s_nodo{ 
	t_producto info;
	struct s_nodo *sig;
};
typedef struct s_nodo * t_data;

void cargarListaFrente(t_data* lista,char *nomArch);
void agregarALista(t_data *dirDelNodo,t_producto valor);
void imprimir(t_data lista);
int maximoDe(t_data lista);
float get_precio(t_producto productoActual);

int main(){
	t_data lista=NULL;
	int *maximos;
	char *nomArch="datos_t3.txt";
	cargarListaFrente(&lista,nomArch);
	imprimir(lista);
	printf("%p\n",maximoDe(lista));
	return 0;
}

void cargarListaFrente(t_data* lista,char *nomArch){
	t_producto aux;
	char letra;
	char arreglo[N];
	float precio;
	int i=0,cantidad=0,id=0;
	FILE *arch;
	arch=fopen(nomArch,"r");

	if(arch==NULL){
		printf("ERROR al abrir el archivo.");
	}
	else{
		letra=fgetc(arch);
		while(letra!=EOF){
			while(letra!=','){
				arreglo[i]=letra;
				i++;
				letra=fgetc(arch);
			}
			arreglo[i]='\0';
			strcpy(aux.articulo,arreglo);
			fscanf(arch,"%f,%d,%d\n",&precio,&cantidad,&id);
			aux.precio=precio;
			aux.cantidad=cantidad;
			aux.id=id;

			agregarALista(lista,aux);
			letra=fgetc(arch);
			i=0,precio=0,cantidad=0,id=0;
		}
	}
}
void agregarALista(t_data *dirDelNodo,t_producto valor){
	if((*dirDelNodo)==NULL){
		(*dirDelNodo)=malloc(sizeof(struct s_nodo));
		(*dirDelNodo)->info = valor;
		(*dirDelNodo)->sig=NULL;
	}
	else{
		agregarALista(&((*dirDelNodo)->sig),valor);
	}
}


void imprimir(t_data lista){
    if (lista !=NULL){
        printf("%s ---- %f ---- %d ----%d\n",lista->info.articulo,lista->info.precio,lista->info.cantidad,lista->info.id);
        imprimir(lista->sig);
    }
}






