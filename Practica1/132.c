#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define F 25
#define C 25
#define N 25
#define TERM_I 100


int cargarMatNumdeArch(int arrI[F][C], char nombre[F]);
int cargarMatTextDeArch(char arrC[F][C],char nombre[F]);
void imprimirTabla(int datos[F][C], char cabeceras[F][C], char items[F][C], int fil, int col);
void swapI(int elem1[F],int elem2[F]);
void swapC(char elem1[F],char elem2[F]);
void ordenarTabla(char arrC[F][C],int arrI[F][C],int col,int num);


int main(){
    int datos[F][C]={0};
    char cabeceras[F][C]={0};
    char items[F][C]={0};

    cargarMatNumdeArch(datos,"datos.txt");
    cargarMatTextDeArch(cabeceras,"cabeceras.txt");
    cargarMatTextDeArch(items,"items.txt");
    imprimirTabla(datos,cabeceras,items,5,8);
    ordenarTabla(items,datos,2,0);
    imprimirTabla(datos,cabeceras,items,5,8);
}

int cargarMatNumdeArch(int arrI[F][C], char nombre[F]){
    int i;
    FILE *arch;
    arch=fopen(nombre,"r");
    if(arch==NULL){ //le pregunto al programa si encontro el archivo, si no lo encontro la funcion retorna -1.
        return -1;
    }

    for(i=0; fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d\n", &arrI[i][0], &arrI[i][1], &arrI[i][2],
                                                         &arrI[i][3], &arrI[i][4], &arrI[i][5],
                                                         &arrI[i][6], &arrI[i][7]) != EOF && i< F-1; i++){}
    arrI[i][0] = EOF;

    fclose(arch);
    return 0;

}

int cargarMatTextDeArch(char arrC[F][C],char nombre[F]){
    int f,c;
    char aux;
    FILE *arch;
    arch=fopen(nombre,"r");
    if(arch==NULL){
        return -1;
    }
    aux=fgetc(arch); //leo el primer caracter del archivo y lo guardo en la variable aux
    for(f=0;aux!=EOF && f<F-1;f++){ //preugnto si el archivo esta vacio y si llegamos al tamaño maximo (en filas) de la matriz
        for(c=0;c<C-1 && aux!=EOF && aux!='\n';c++){
            arrC[f][c]=aux;
            aux=fgetc(arch);
        }
        arrC[f][c]='\0';
        if(aux=='\n'){
            aux=fgetc(arch);
        }
    }
    arrC[f][c]='\0';
    fclose(arch);
    return 0;
}

void imprimirTabla(int datos[][N], char cabeceras[][N], char items[][N], int fil, int col){
    int x;
    int y;

    printf("\n");

    //Imprimimos las cabeceras
    for(y=0; y<col+1; y++){
            printf("%-8s",cabeceras[y]);
    }

    printf("\n");

    for(y=0; y<col+1; y++){
        if(y==0){
            printf("----------");
        }
        else{
            printf("--------");
        }

    }

    printf("\n");

    //Imprimimos los items a medida que pasan los datos
    for(y=0; y<fil; y++){
        printf("%-8s",items[y]);
        for(x=0; x<col; x++){
            if( datos[y][x] > 0 && x == 7 ){
                    printf("+%-7d",datos[y][x]);
            }
            else{
                printf("%-8d",datos[y][x]);
            }
        }
        printf("\n");

    }
}
int largoArrI(int arrI[]){
    /** retorna el largo efectivo (cantidad de numeros) que contiene un arreglo de enteros*/
    int i;
    for (i=0; i<F-1 && arrI[i]!=TERM_I; i++);
    printf("%d",i);
    // return i;
}
void swapI(int elem1[F],int elem2[F]){
    int i;
    int aux[F]={0}; //inicializo mi matriz auxiliar en 0
    for(i=0;i<F && i!=TERM_I;i++){
        aux[i]=elem1[i]; //almaceno uno de los elementos del arreglo 1 en la matriz auxiliar
        elem1[i]=elem2[i]; //Copio el elemento correspondiente a esa posicion del arreglo 2 al 1.
        elem2[i]=aux[i]; //copio el elemento almacenado anteriormente en la auxiliar en el arreglo 2.
    }
}

void swapC(char elem1[F],char elem2[F]){
    int i;
    char aux[F]={0}; //inicializo mi matriz auxiliar en 0
    for(i=0;i<F && i!=10;i++){
        strcpy(aux,elem1[i]);
        strcpy(elem1[i],elem2[i]);
        strcpy(elem2[i],aux);          
        }
}


void ordenarTabla(char arrC[F][C],int arrI[F][C],int col,int num){
    int i,j;
    int f,c;
    int cantNum;
    cantNum=largoArrI(arrI); 
    for(i=0;i<cantNum-1;i++){   //recorro desde el primer elemento hasta el penultimo
        for(j=i+1;j<cantNum;j++){   //recorro desde el segundo elemento hasta el ultimo
            if(num==0){      //si ingresaron 0, ordeno de forma ascendente
                if(arrI[i][col-1]>arrI[j][col-1]){  //pregunto si el elemento seleccionado es mayor al siguiente
                    swapI(arrI[i],arrI[j]); //como es mayor y yo quiero ordenar de menor a mayor intercambio ambas filas
                    swapC(arrC[i],arrC[j]); //intercambio sus respectivos strings.
                }
            }
            else if(num==1){ //si ingresaron 1, ordeno de forma descendente
                if(arrI[i][col-1]<arrI[j][col-1]){ //pregunto si el elemento seleccionado es menor al siguiente
                    swapI(arrI[i],arrI[j]); //como es menor y yo quiero ordenar de mayor a menor, intercambio ambas filas
                    swapC(arrC[i],arrC[j]); //intercambio sus respectivos strings
                }
            }
        }
    }
}

