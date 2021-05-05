#include<stdio.h>

#define F 20
#define C 20
#define N 20

void cargarMatNumDeArch(int m[F][C],char nom[N]);
void imprimirMatNum(int m[F][C]);

int main(){
    int m[F][C]={0};
    char nom[N]="puntos.txt";
    cargarMatNumDeArch(m,nom);
    imprimirMatNum(m);
    return 0;
}

void cargarMatNumDeArch(int m[F][C],char nom[N]){
    int f,n1,n2,n3,n4,n5,n6,n7,n8,n9;
    FILE *arch;
    arch=fopen(nom,"r");

 //como hacerlo generico
    for(f=0;fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9)!=EOF && f<F;f++){
        m[f][0]=n1;
        m[f][1]=n2;
        m[f][2]=n3;
        m[f][3]=n4;
        m[f][4]=n5;
        m[f][5]=n6;
        m[f][6]=n7;
        m[f][7]=n8;
        m[f][8]=100; //le pongo un terminador, asi se como buscar para que corte
    }
    m[f][0]=EOF; //siempre en un archivo le pongo EOF que es end of file
    fclose(arch);
}

void imprimirMatNum(int m[F][C]){
	int f,c;
	for(f=0;m[f][0]!=EOF && f<F;f++){
		for(c=0;c<C && m[f][c]!=100;c++){ //busco el 100 en la columna que me significa el terminador
            if (m[f][c]>0 && c==7){  //Si el numero es positivo y esta en la ultima columna, le pongo el + 
		    	printf("+%d\t",m[f][c]);
		    }
            else{ //sino no le pongo nada, porque los negativos ya vienen con el signo negativo
                printf("%d\t",m[f][c]); 
            }
        }
        printf("\n");
	}
    printf("\n");

}
