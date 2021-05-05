#include<stdio.h>

#define F 20
#define C 20
#define N 20
void cargarMatTextDeArch(char m[F][C],char nom[N]);
void imprimirMatText(char m[F][C]);

int main(){
	char m[F][C]={0};
	char nom[N]="equipos.txt";
	cargarMatTextDeArch(m,nom);
	imprimirMatText(m);
	return 0;
}

void cargarMatTextDeArch(char m[F][C],char nom[N]){
	int f, c;
	char i;

	FILE *arch;
	arch=fopen(nom,"r");

	i=fgetc(arch);
	for(f=0;f<F && i!=10 && i!=EOF;f++){
		for(c=0;c<C && i!=10;c++){
			m[f][c]=i;
			i=fgetc(arch);
		}
		m[f][c]='\0';
		i=fgetc(arch);
	}
	m[f][0]='\0';
	fclose(arch);
}

void imprimirMatText(char m[F][C]){
	int f,c;
	char i;
	for(f=0;m[f][0]!='\0' && f<F;f++){
		for(c=0;c<C && m[f][c]!='\0';c++)	{
			printf("%c",m[f][c]);
		}
		printf("\n");
	}
	printf("\n");
}


