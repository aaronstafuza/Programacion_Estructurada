#include <stdio.h>

#define N 100
void leer(char t[N]);
void reemplazar(char t[N], char l1, char l2);

int main(){
	char t[N];
	char l1, l2;
	int i;

	printf("Ingrese texto: ");
	leer(t);

	printf("Ingrese carácter a reemplazar: ");
	l1=getchar();
	getchar();

	printf("Ingrese carácter de reemplazo: ");
	l2=getchar();
	reemplazar(t,l1,l2);
	
	printf("El resultado es: ");
	
	for(i=0;t[i]!='\0';i++){
		printf("%c",t[i]);
	}
	printf("\n");
	return 0;

}

void leer(char t[N]){
	char c;
	int i=0;
	c=getchar();
	while(c!=10){
		t[i]=c;
		i++;
		c=getchar();
	}
	t[i]='\0';
}

void reemplazar(char t[N], char l1, char l2){
	int i=0;
	while(t[i]!='\0'){
		if(t[i]==l1){
			t[i]=l2;
		}
		i++;
	}
}