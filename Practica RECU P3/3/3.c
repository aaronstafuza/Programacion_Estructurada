#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
#define T 25

typedef struct{
	char apellido[50];
	int dni;	
	int edad;
	char nombre[35];
}t_personas;

struct s_nodo{ 
	t_personas info;
	struct s_nodo *sig;
};
typedef struct s_nodo * t_data;

void imprimir(t_data lista);
void cargarListaO(t_data * lista,char * nomArch);
void agregarALista(t_data *dirDelNodo,t_personas valor);
void ordenarPorDni(t_data *dirDelNodo, t_personas nuevo);
int sumaDe(t_data lista);

// int minimoDat(t_data dirDelNodo);
int *retornarDireccionDelNumeroMasGrandeDelArreglo(t_data *arreglo);
int *retornarDireccionDelNumeroMasChicoDelArreglo(t_data *arreglo);
int retornarNumeroMasGrandeDelArreglo(t_data arreglo);

int main(){
	t_data lista=NULL;
	int *aux,*aux2;
	int mas_grande=0;
	char *nomArch="datos_t1.txt";
	cargarListaO(&lista,nomArch);
	imprimir(lista);
	aux=retornarDireccionDelNumeroMasGrandeDelArreglo(&lista);
	printf("%d\n",(*aux));
	printf("%p\n",aux);
	aux2=retornarDireccionDelNumeroMasChicoDelArreglo(&lista);
	printf("%d\n",(*aux2));
	printf("%p\n",aux2);

	mas_grande=retornarNumeroMasGrandeDelArreglo(&lista);
	printf("%d\n",mas_grande);
	return 0;
}


void cargarListaO(t_data * lista,char * nomArch){
	t_personas aux;
	int i=0,j=0;
	char letra,letra_nom;
	char arreglo[N], arreglo2[T];
	int edad=0,dni=0;
	FILE *arch;
	arch=fopen(nomArch,"r");
	if(arch==NULL){
		printf("ERROR en la apertura del archivo.");
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
			strcpy(aux.apellido,arreglo);
			fscanf(arch,"%d,%d,",&dni,&edad);
			aux.edad=edad;
			aux.dni=dni;

			letra_nom=fgetc(arch);
			while(letra_nom!='\n'){
				arreglo2[j]=letra_nom;
				j++;
				letra_nom=fgetc(arch);
			}
			arreglo2[j]='\0';
			strcpy(aux.nombre,arreglo2);

			// ordenarPorDni(lista,aux);
			agregarALista(lista,aux);
			letra=fgetc(arch);
			i=0,j=0,edad=0,dni=0;
		}
	}
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
        printf("%s ---- %d ---- %d ----%s\n",lista->info.apellido,lista->info.dni,lista->info.edad,lista->info.nombre);
        imprimir(lista->sig);
    }
}

// void ordenarPorDni(t_data *dirDelNodo, t_personas nuevo)
// {
// 	t_data nodoAuxiliar = NULL;

// 	if (((*dirDelNodo)==NULL) || (((*dirDelNodo)->info).dni)>nuevo.dni){
// 		nodoAuxiliar = malloc(sizeof(struct s_nodo));
// 		nodoAuxiliar->sig = (*dirDelNodo);
// 		nodoAuxiliar->info=nuevo;
// 		(*dirDelNodo) = nodoAuxiliar;
// 	}

// 	else
// 	{
// 		ordenarPorDni(&((*dirDelNodo)->sig), nuevo);
// 	}
// }

//FUNCION RECURSIVA que retorna la sumatoria de las edades de aquellos nodos de la lista que
//cumplen con la condicion: El campo <dni> ES multiplo de 3 y NO ES PAR.
int sumaDe(t_data lista){
	if(lista!=NULL){
		if(lista->info.dni%3==0 && lista->info.dni%2!=0){
			return lista->info.edad+sumaDe(lista->sig);
		}
		else{
			return sumaDe(lista->sig);
		}
	}
	return 0;
}


//ESTA BIEN ESTA
int *retornarDireccionDelNumeroMasGrandeDelArreglo(t_data *arreglo)
{

	int *direccionDelNumeroDeFuncionActual = &(*arreglo)->info.dni;
	int *direccionDelNumeroDeFuncionAnterior = NULL;

	if (*(arreglo) != NULL)
	{
		direccionDelNumeroDeFuncionAnterior = retornarDireccionDelNumeroMasGrandeDelArreglo(&((*arreglo)->sig));

		if (direccionDelNumeroDeFuncionAnterior == NULL){
			return direccionDelNumeroDeFuncionActual;
		}

		if (*(direccionDelNumeroDeFuncionActual) > *(direccionDelNumeroDeFuncionAnterior)){
			return direccionDelNumeroDeFuncionActual;
		}
		else{
			return direccionDelNumeroDeFuncionAnterior;
		}
	}
	else
		return NULL;
}

//ESTA BIEN ESTA
int *retornarDireccionDelNumeroMasChicoDelArreglo(t_data *arreglo)
{

	int *direccionDelNumeroDeFuncionActual = &(*arreglo)->info.dni;
	int *direccionDelNumeroDeFuncionAnterior = NULL;

	if (*(arreglo) != NULL)
	{
		direccionDelNumeroDeFuncionAnterior = retornarDireccionDelNumeroMasChicoDelArreglo(&((*arreglo)->sig));

		if (direccionDelNumeroDeFuncionAnterior == NULL){
			return direccionDelNumeroDeFuncionActual;
		}

		if (*(direccionDelNumeroDeFuncionActual) < *(direccionDelNumeroDeFuncionAnterior)){
			return direccionDelNumeroDeFuncionActual;
		}
		else{
			return direccionDelNumeroDeFuncionAnterior;
		}
	}
	else
		return NULL;
}




