#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define T 50

typedef struct{
	int id;
	char cod[4];	
	char provincia[50];
	int poblacion;
}t_personas;

struct s_nodo{ 
	t_personas info;
	struct s_nodo *sig;
};
typedef struct s_nodo * t_data;

void cargarListaFrente(t_data *lista,char*nomArch);
void agregarALista(t_data *dirDelNodo,t_personas valor);
void imprimir(t_data lista);

int main(){
	char *nomArch="datos_t2.txt";
	t_data lista=NULL;
	cargarListaFrente(&lista,nomArch);
	imprimir(lista);
	return 0;
}

void cargarListaFrente(t_data *lista,char*nomArch){
	t_personas aux;
	int i=0,j=0,poblacion=0,id=0;
	char letra_cod,letra_prov;
	char arreglo_prov[T],arreglo_cod[N];
	FILE *arch;
	arch=fopen(nomArch,"r");
	if(arch==NULL){
		printf("ERROR.");
	}
	else{
		fscanf(arch,"%d,",&id);
		aux.id=id;
		letra_cod=fgetc(arch);
		while(letra_cod!=EOF){
			while(letra_cod!=','){
				arreglo_cod[i]=letra_cod;
				i++;
				letra_cod=fgetc(arch);
			} 
			arreglo_cod[i]='\0';
			strcpy(aux.cod,arreglo_cod);
			letra_prov=fgetc(arch);
			while(letra_prov!=','){
				arreglo_prov[j]=letra_prov;
				j++;
				letra_prov=fgetc(arch);
			}
			arreglo_prov[j]='\0';
			strcpy(aux.provincia,arreglo_prov);
			fscanf(arch,",%d\n",&poblacion);
			aux.poblacion=poblacion;

			agregarALista(lista,aux);
			i=0,j=0,id=0,poblacion=0;

			fscanf(arch,"%d,",&id);
			aux.id=id;
			letra_cod=fgetc(arch);
		}
	}
	fclose(arch);
}


void agregarALista(t_data *dirDelNodo,t_personas valor){
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
        printf("%d ---- %s ---- %s ----%d\n",lista->info.id,lista->info.cod,lista->info.provincia,lista->info.poblacion);
        imprimir(lista->sig);
    }
}

