/* 
Desarrollar una función que le permita al usuario cargar en
un archivo (csv) personas.txt los datos de personas 
(n° de documento, nombre, país). Se debe permitir ingresar por 
teclado de los datos hasta una cantidad máxima N (constante),o 
finalizando cuando el documento ingresado es cero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define MAXI 3
struct persona{
    int dni;
    char nombre[N];
    char pais[N];
};

void cargarString(char string[N]){
    char caracter = getchar();
    int indice=0;

    /*--------------------------------
    Se verifica que el getchar no haya
    leido el caracter '\r'
    --------------------------------*/

    if(caracter==10){
        caracter=getchar();
    }
    while(indice<N-1 && caracter!=10){
        string[indice]=caracter;
        indice++;
        caracter=getchar();
    }
    string[indice]='\0';
}

void agregarPersona(struct persona personaNueva, char nombre[]){
    FILE *archivo = fopen(nombre,"a"); //"a": append -- agrego/escribo en el archivo

    //Varias instrucciones para que sea facil de ver
    fprintf(archivo, "%d,",personaNueva.dni);
    fprintf(archivo, "%s,",personaNueva.nombre);
    fprintf(archivo, "%s\n",personaNueva.pais);

    fclose(archivo);
}

void cargarPersonas(){
    struct persona personaNueva;
    int c=0;

    printf("Ingrese DNI (0 para terminar): ");
    scanf("%d",&personaNueva.dni);

    while(personaNueva.dni!=0 && c<MAXI){
        printf("Ingrese nombre: ");
        cargarString(personaNueva.nombre);

        printf("Ingrese pais: ");
        cargarString(personaNueva.pais);

        printf("%d\n",personaNueva.dni);
        printf("%s\n",personaNueva.nombre);
        printf("%s\n",personaNueva.pais);

        agregarPersona(personaNueva,"personas.txt");

        c++;
 
        if(c<MAXI){ //para que ingrese solo dos personas
            printf("Ingrese DNI(0 para terminar): ");
            scanf("%d",&personaNueva.dni);
        }
    }
}

int main(){
    cargarPersonas();
    return 0;
}