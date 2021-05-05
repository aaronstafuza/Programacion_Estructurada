#include <stdio.h>
#include <stdlib.h>

struct s_texto
{
    char * txt;
    unsigned int longitud;
};
typedef struct s_texto t_texto;

// Desarrollar una función ​cargarTexto() ​que permita ingresar un texto 
// de longitud indefinida y guardarlo en una variable externa del tipo de dato t_texto​, 
// completando ambos campos. Se recomienda en esta función llamar a la función del ejercicio 8 .2 
// pero modificarla para que retorne el tamaño del string cargado.


t_texto cargarStrDin1(){
    t_texto string;
    int cont = 0;
    char caracter = 0;

    string.txt = malloc(sizeof(char));

    caracter = getchar();
    while( caracter != 10 ){
        *(string.txt + cont) = caracter;

        cont++;

        string.txt = realloc(string.txt, (cont+1) * sizeof(int));

        caracter = getchar();
    }
    string.longitud=cont;
    *(string.txt + cont) = '\0';

    return string;
}

// Luego, desarrollar la función ​escribirArchTex() ​a la cual se le pasa 
// por parámetro el nombre del archivo “​frases_con_longitud.csv” y el 
// puntero a una estructura t_texto*. La función deberá escribir en el 
// archivo la longitud del texto y el texto, separando ambos elementos 
// por una coma

void escribirArchTex(char *nomArch, t_texto string){
    char caracter=0;
    int cont=0;
    FILE *arch;
    arch=fopen(nomArch,"w");

    fprintf(arch,"%d,",string.longitud);

    caracter=*(string.txt+cont);
    
    while(caracter!='\0'){
        fputc(caracter,arch);
        cont++;
        caracter=*(string.txt+cont);
    }
    fputc('\n',arch);
    fclose(arch);
    
}

int main(){
    // cargarStrDin1();
    escribirArchTex("frases_con_longitud.csv", cargarStrDin1());
    return 0;
}