#include<stdio.h>

#define T 100

void cargarArr(int arr[T]);
void imprimirArr(int arr[T]);
void invertirArr(int arr[T]);
void ordenarArr(int arr[T]);

int main(){
	int arr1[T], arr2[T];
	printf("Cargar arreglo: ");
	cargarArr(arr1);
	printf("Arreglo impreso: ");
	imprimirArr(arr1);
	printf("\n");
	invertirArr(arr1);
	printf("Arreglo invertido: ");
	imprimirArr(arr1);
	printf("\n");
	ordenarArr(arr1);
	printf("Arreglo ordenado: ");
	imprimirArr(arr1);
	printf("\n");
	return 0;

}

void cargarArr(int arr[T]){
	int i=0;
	scanf("%d",&arr[i]);
	while (arr[i]!=0){
		i++;
		scanf("%d",&arr[i]);
	}
	arr[i]=0;
}

void imprimirArr(int arr[T]){
	int i;
	for(i=0;arr[i]!=0;i++){
		printf("%d",arr[i]);
	}
}

void invertirArr(int arr[T]){
	int i=0;
	int cant;
	int aux;
	for(cant=0;arr[cant]!=0;cant++);
	cant=cant-1;
	while (i<cant){
		aux=arr[i];
		arr[i]=arr[cant];
		arr[cant]=aux;
		cant--;
		i++;
	}
}

void ordenarArr(int arr[T]){
	int i,j, aux;
	for(i=0;arr[i]!=0;i++){
		for(j=i+1;arr[j]!=0;j++){
			if(arr[i]>arr[j]){
				aux=arr[i];
				arr[i]=arr[j];
				arr[j]=aux;
			}
		}
	}

}






