/*
Desarrollar dos versiones de la función del ejercicio anterior ​
cargarStrDin() ​según el siguiente detalles:
Versiones de cargarStrDin():
    1. Esta versión ​char* cargarStrDin1()​, no se le pasan parámetros 
    y retorna la dirección de memoria del arreglo dinámico creado.
    2. Esta versión ​void cargarStrDin2(char**)​, no retorna ningún valor,
    y se le pasa por parámetro la ​dirección​ de memoria ​de un puntero​ a 
    char.

Desarrollar la función ​escribirArch() que recibe por parámetro el 
nombre del archivo “​frase.txt​” y un string. La función deberá escribir 
en el archivo de nombre pasado por parámetro, el contenido del string 
también pasado por parámetro.
Además desarrollar la función ​impimirArch() qué recibe por parámetro el 
nombre del archivo “​frase.txt​” e imprime su contenido. (​ver prototipos​)
*/

#include <stdio.h>
#include <stdlib.h>

char * cargarStrDin1();
void cargarStrDin2(char ** pCadena);
void escribirArch(char * nomArch, char * cadena);
void imprimirArch(char * nomArch);
int esNull(void * puntero);

int main()
{
    char * string = NULL; //null para que este vacio

    //Sacar comentario a una sola linea a la vez
    string = cargarStrDin1();
    //cargarStrDin2(&string);
    escribirArch("archivo.txt",string);
    imprimirArch("archivo.txt");

    return 0;
}

char * cargarStrDin1(){
    char * arregloCadena = (char *) malloc(sizeof(char));
    int contadorLetras = 0;
    char caracter = 0;

    caracter = getchar();

    while( caracter != 10 ){
        *(arregloCadena + contadorLetras) = caracter;

        contadorLetras++;

        arregloCadena = realloc(arregloCadena, (contadorLetras+1) * sizeof(int));

        if(esNull(arregloCadena)){
            return NULL;
        }

        caracter = getchar();
    }

    *(arregloCadena + contadorLetras) = '\0';

    return arregloCadena;

}
void cargarStrDin2(char ** pCadena){
    *pCadena = (char *) malloc(sizeof(char));
    int contadorLetras = 0;
    char caracter = 0;

    caracter = getchar();

    while( caracter != 10 ){
        *(*pCadena + contadorLetras) = caracter;

        contadorLetras++;
        *pCadena= realloc(*pCadena, (contadorLetras+1) * sizeof(int));

        caracter = getchar();
    }

    *(*pCadena + contadorLetras) = '\0';
}
void escribirArch(char * nomArch, char * cadena){
    FILE * archivo = fopen(nomArch, "w");
    char caracter = 0;
    int indiceDeCadena = 0;

    caracter = *cadena;

    while(caracter != '\0'){
        fputc(caracter, archivo);
        indiceDeCadena++;
        caracter = *(cadena+indiceDeCadena);
    }

    fclose(archivo);
}
void imprimirArch(char * nomArch){
    FILE * archivo = fopen(nomArch, "r");
    char caracter = 0;
    int indiceDeCadena = 0;

    caracter = fgetc(archivo);

    while(caracter != EOF){
        printf("%c", caracter);
        indiceDeCadena++;
        caracter = fgetc(archivo);
    }

    fclose(archivo);
}
int esNull(void * puntero){
    int esNull = 0;

    if(puntero == NULL){
        esNull = 1;
    }

    return esNull;
}