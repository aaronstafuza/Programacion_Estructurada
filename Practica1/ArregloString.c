#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 25
#define C 25
#define N 25
/*
Funciones a desarrolar:
    -Sacar los espacios
    -Ordenar ascendente y descendente
    -Pasar a mayuscula y a minuscula
*/

void cargarArrC(char arrC[F][C],char nombre[N]){
    int f,c;
    char i;
    FILE *arch;
    arch=fopen(nombre,"r");

    i=fgetc(arch);
    for(f=0;i!=EOF && f<F && i!=10;f++){ 
        for(c=0;c<C && i!=10;c++){
            while(i==32){
                i=fgetc(arch);
            }
            arrC[f][c]=i;
            i=fgetc(arch);
        }
        arrC[f][c]='\0';
        i=fgetc(arch);
    }
    arrC[f][0]='\0';
    fclose(arch);
}



void imprimirArrC(char arrC[F][C]){
    int f,c;
    for(f=0;f<F && arrC[f][0]!='\0';f++){
        for(c=0;c<C && arrC[f][c]!='\0';c++){
                printf("%c",arrC[f][c]);
        }
        printf("\n");
    }
}


void aMinus(char arrC[F][C]){
    int f,c;
    for(f=0;f<F && arrC[f][0]!='\0';f++){
        for(c=0;c<C && arrC[f][c]!='\0';c++){
            if (arrC[f][c]>='A' && arrC[f][c]<='Z')
                arrC[f][c]=arrC[f][c]+32;
        }
    }   
}

void aMayus(char arrC[F][C]){
    int f,c;
    for(f=0;f<F && arrC[f][0]!='\0';f++){
        for(c=0;c<C && arrC[f][c]!='\0';c++){
            if (arrC[f][c]>='a' && arrC[f][c]<='z')
                arrC[f][c]=arrC[f][c]-32;
        }
    }   
}

void ordenarTabla(char arrC[F][C],int numOrden){
    int f,c;
    char aux[N]={0};
    if(numOrden==1){
        for(f=0;arrC[f][0]!='\0';f++){
            for(c=0;arrC[c][0]!='\0';c++){
                if(strcmp(arrC[f],arrC[c]) < 0){
                    strcpy(aux,arrC[f]);
                    strcpy(arrC[f],arrC[c]);
                    strcpy(arrC[c],aux);
                }
            }
        }
    }
    else{
        for(f=0;arrC[f][0]!='\0';f++){
            for(c=0;arrC[c][0]!='\0';c++){
                if(strcmp(arrC[f],arrC[c]) > 0){
                    strcpy(aux,arrC[f]);
                    strcpy(arrC[f],arrC[c]);
                    strcpy(arrC[c],aux);
                }
                
            }
        }
    }
}

// void ordenarTexto(char m[F][C]){
//     int x;
//     int y;
//     char aux[N]={0};

//     for(x=0;m[x][0]!='\0';x++){
//         for(y=0;m[y][0]!='\0';y++){
//             if(strcmp(m[x],m[y])<0)  //Si entrega un numero menor a 0, entonces matriz[x] es menor.
//             { 
//                 strcpy(aux,m[x]);
//                 strcpy(m[x],m[y]);
//                 strcpy(m[y],aux);
//             }          
//         }
//     }

// }
int main(){
    int num;
    char a[F][C]={0};
    cargarArrC(a,"archivo.txt");
    imprimirArrC(a);
    printf("\n");
    printf("Ingrese como ordenar [1 ascendente] o [0 descendente]:");
    scanf("%d",&num);
    ordenarTabla(a,num);
    imprimirArrC(a);
    // aMinus(a);
    // imprimirArrC(a);
    // printf("\n");
    // aMayus(a);
    // imprimirArrC(a);

}