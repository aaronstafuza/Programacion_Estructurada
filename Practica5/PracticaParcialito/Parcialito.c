#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
typedef struct
{
	char descrip[N];
	// char *descrip;
	int cantidad, vocales;
}t_insumo;

struct s_nodo
{
    t_insumo dato;
    struct s_nodo *siguienteNodo;
};
typedef struct s_nodo * t_nodo;

void cargarLista(t_nodo *lista);
void agregarNumLista(t_nodo *dirDelNodo,t_insumo valor);
int vocal(char *arreglo);
int esVocal(char n);
void imprimirRecursiva(t_nodo lista);
void imprimirNoRecursiva(t_nodo lista);

int main(){
	t_nodo lista=NULL;
	cargarLista(&lista);
	printf("\n\t\t\tIMPRESION DE LA LISTA CARGADA\n");
  //  imprimir_nr(lista);
    imprimirRecursiva(lista);
	return 0;
}

void cargarLista(t_nodo *lista){
	t_insumo aux;
	char letra;
	char arreglo[N];
	int num=0;
	int i=0;

	FILE *arch=fopen("stock.txt","r");
	if(arch==NULL){
		printf("Error en la apertura del archivo.");
	}

	else{
		letra = fgetc(arch);
		while(letra!=EOF){
			while(letra!=','){
				arreglo[i]=letra;
				i++;
				letra=fgetc(arch);
			}
			arreglo[i]='\0'; //terminador de la fila
			strcpy(aux.descrip,arreglo); //copio en descrip lo que cargue en arreglo
			printf("\nLa cantidad de vocales de %s es %d\n",aux.descrip,vocal(aux.descrip));
			aux.vocales=vocal(aux.descrip);
            fscanf(arch,"%d\n",&num);
			aux.vocales=num;

			agregarNumLista(lista,aux);

			letra=fgetc(arch);
			i=0;
		}
	}
	fclose(arch);
}

void agregarNumLista(t_nodo *dirDelNodo,t_insumo valor){
	if((*dirDelNodo)==NULL){
		(*dirDelNodo)=malloc(sizeof(struct s_nodo));
		(*dirDelNodo)->dato = valor;
		(*dirDelNodo)->siguienteNodo=NULL;
	}
	else{
		agregarNumLista(&((*dirDelNodo)->siguienteNodo),valor);
	}
}

void imprimirNoRecursiva(t_nodo lista){
	for(;lista!=NULL;lista=lista->siguienteNodo){
		printf("%s - %d - %d\n",lista->dato.descrip,lista->dato.cantidad,lista->dato.vocales);
	}
}

void imprimirRecursiva(t_nodo lista){
	if(lista!=NULL){
		printf("%s - %d - %d\n",lista->dato.descrip,lista->dato.cantidad,lista->dato.vocales);
		imprimirRecursiva(lista->siguienteNodo);
	}
}

int vocal(char *arreglo){
    if (*arreglo!='\0')
    {
        if(!esVocal(*arreglo))
            return vocal(arreglo+1);
        else
            return 1 + vocal(arreglo+1);
    }
    return 0;
}

int esVocal(char n)
{
    int rta= 0;
    if(n=='a' || n=='A' || n=='e' || n=='E' || n=='i' || n=='I' || n=='o' || n=='O' || n=='u' || n=='U' )
        rta=1;
    return rta;
}






