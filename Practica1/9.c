#include <stdio.h>

#define F 10
#define C 10
void cargarMatText(char mat[F][C]);
void imprimirMatText(char mat[F][C]);
void ordernarMatText(char mat[F][C]);

int main(){
	char mat[F][C]={0};

	return 0;
}

void cargarMatText(char mat[F][C]){
	int f, c;
	char i;
	printf("Agregue texto a la matriz: ")
	c=getchar();
	for(f=0;f<F && f!=10;f++){
		for(c=0;c<C && c!=10;c++){
			mat[f][c]=i;
			c=getchar();
		}
		mat[f][c]='\0';
	}
	mat[f][c]='\0';
}

void imprimirMatText(char mat[F][C]){
	int f,c;
	char i;
	for(f=0;f<F &&f!='\0';f++){
		for(c=0;c<C && c!='\0';c++)	{
			printf(mat[f][c]);
		}
		printf('\n')
	}
	printf('\n')
}


void ordernarMatText(char mat[F][C]){
	int f,c;
	char i;
	for(f=0;f<F &&f!='\0';f++){
		for(c=0;c<C && c!='\0';c++)	{
			if (mat[f][c]>='A' && mat[f][c]<='Z'){
				mat[f][c]=mat[f][c]+32 //+32 me pasa todo a minus, -32 todo a mayus
			}
			
		}
	}
}


