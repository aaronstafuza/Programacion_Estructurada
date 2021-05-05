#include <stdio.h>
#include <stdlib.h>

#define N 100
#define MAXI 50

struct persona{
    int dni;
    char nombre[N];
    char pais[N];
};

void importarPersonas(char nombre[], struct persona arregloPersonas[MAXI]){
    int i;
    FILE *arch; 
    arch=fopen(nombre,"r"); //abro archivo para leerlo
    for(i=0;fscanf(arch,"%d,%[^,],%s", &arregloPersonas[i].dni,&arregloPersonas[i].nombre,&arregloPersonas[i].pais)!=EOF && i<MAXI-1;i++){}
    //importo los datos para cada variable leyendo desde el archivo

    arregloPersonas[i].dni=EOF;
    fclose(arch);
}

void imprimirTabla(){
    int i;
    struct persona arregloPersonas[MAXI];

    importarPersonas("personas.txt",arregloPersonas);

    //Cabeceras
    printf("%-20s","Documento");
    printf("%-20s","Nombre");
    printf("%-20s","Pais");

    printf("\n");

    for(i=0;i<60;i++){
        printf("=");
    }
    printf("\n");
    
    for(i=0;arregloPersonas[i].dni!=EOF;i++){
        printf("%-20d",arregloPersonas[i].dni);
        printf("%-20s",arregloPersonas[i].nombre);
        printf("%-20s",arregloPersonas[i].pais);
        printf("\n");
    }
}

int main(){
    imprimirTabla();
    return 0;
}