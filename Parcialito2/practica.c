#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#define N 20

typedef struct{
	char* texto;
	int anio, mes,dia;
}t_dato;


int sacarMes(unsigned int valor);
int sacarDia(unsigned int valor);
int sacarAnio(unsigned int valor);
void cargarArr(t_dato arrP[N],char *nomArch);
void imprimirArr(t_dato datos[N]);


int main(){
	t_dato datos[N];
	cargarArr(datos,"datos.csv");
	imprimirArr(datos);
	return 0;
}

void cargarArr(t_dato arrP[N],char *nomArch){
	int i=0,j=0;
	unsigned int num=0; //siempre que use mascaras uso unsigned int
	char *nombre=NULL; //nombre tiene que ser un puntero porque lo cargo con malloc y realloc
	char letra;

	FILE *arch;
	arch=fopen(nomArch,"r");

	letra=fgetc(arch);
	while(letra!=EOF){
		nombre=malloc(sizeof(char));
		while(letra!=','){
			*(nombre+i)=letra; //cargo en la direccion de memoria de nombre[i] la letra 
			i++;
			nombre=realloc(nombre,(i+1)*sizeof(char)); //agrego memoria dinamica
			letra=fgetc(arch); //leo la siguiente letra del nombre
		}
		*(nombre+i)='\0'; //Sasha\0 --> Es para poner un terminador siempre despues de un string
		arrP[j].texto=nombre; //agrego a la estructura .texto el nombre guardado
		fscanf(arch,"%d\n",&num); //leo del archivo el valor numerico
		arrP[j].mes=sacarMes(num); 
		arrP[j].dia=sacarDia(num);
		arrP[j].anio=sacarAnio(num);
		letra=fgetc(arch); //leo de nuevo la primer letra del nombre siguiente 
		i=0; //como estoy en un while, limpio el contador 
		j++; //sumo 1, y paso a la siguiente estructura
	}
	arrP[j].texto=NULL; //terminador del arreglo
	fclose(arch);
	
}

void imprimirArr(t_dato datos[N]){
	int j;
	for(j=0;datos[j].texto!=NULL;j++){
		printf("Nombre: %s\nFecha de nacimiento (D/M/A):%d/%d/%d\n\n",datos[j].texto,datos[j].dia,datos[j].mes,datos[j].anio);
	}
}

int sacarMes(unsigned int valor){
	unsigned int MASK1;
	MASK1=pow(2,8)-1; //(2^8)-1=255
	return (valor)&MASK1;
}
int sacarDia(unsigned int valor){
	unsigned int MASK1;
	MASK1=pow(2,8)-1;//(2^8)-1=255
	return (valor>>8)&MASK1;
}
int sacarAnio(unsigned int valor){
	unsigned int MASK1;
	MASK1=pow(2,16)-1;//(2^16)-1=65535
	return (valor>>16)&MASK1;
}


