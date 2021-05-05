/*
Desarrollar la función ​cargarStrDin() ​que permita ingresar una frase 
desde el teclado hasta presionar ENTER. Y que lo ingresado lo almacene 
en un arreglo en memoria dinámica y sin desperdiciar espacio. Luego 
la función deberá remitir al exterior el contenido cargado. Realizar 
una prueba desde el programa principal imprimiendo en consola el 
contenido remitido por la función.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int esNull(void *puntero){
    int esNull=0;

    if(puntero==NULL){
        esNull=1;
    }
    return esNull;
}

char* cargarStrDin(){
    char *arrCad=(char*) malloc(sizeof(char));
    int cont = 0;
    char caracter = 0;

    caracter = getchar(); //ingreso un caracter
    while(caracter!=10){  // mientras que sea distinto de enter sigue cargando
        arrCad[cont] = caracter; //guardo el arreglo
        cont++; //suma uno el contador
        arrCad= realloc(arrCad,(cont+1)*sizeof(char)); //libero memoria un espacio mas

        if(esNull(arrCad)){ //se fija que no tenga memoria null
            return NULL;
        }
        caracter=getchar(); //si hay espacio, agrega un nuevo caracter
    }
    arrCad[cont]='\0'; //termino con \0
    return arrCad;
}

int main(){
    printf("%s",cargarStrDin());
    printf('\n');
    return 0;
}
