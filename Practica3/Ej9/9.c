#include <stdio.h>
#include <stdlib.h>


char * leerArch(const char * nomArch){
    char * str = NULL;
    char caracter = 0;
    int contadorDeLetras = 0;
    FILE * archivoConFrase = fopen(nomArch, "r");

    str = malloc(sizeof(char));

    caracter = fgetc(archivoConFrase);

    while(caracter != EOF){
        *(str+contadorDeLetras) = caracter;

        contadorDeLetras++;
        str = realloc(str, sizeof(char) * (contadorDeLetras+1) );

        caracter = fgetc(archivoConFrase);
    }

    *(str+contadorDeLetras) = '\0';

    fclose(archivoConFrase);

    return str;
}

char * subcadena(char *p,unsigned int i, unsigned int n){
    char *subP=NULL; //que significa esto?
    char caracter;
    int cantLetrasATomar=0;
    int cont=0;
    int len=0;

    subP=malloc(sizeof(char));
    if(n<0){
        cantLetrasATomar=-n; 
    }
    else{
        cantLetrasATomar=n;
    }
    for(len=0;*(p+len)!='\0';len++); //calculo el len

    //Si i > len no me interesa, solo si i < len
    if(i<len){
        caracter=*(p+i); //cargo en caracter el primer char en las posicion i pasada por parametro
        
        while(caracter!='\0' && cont < cantLetrasATomar){ 
            *(subP+cont)=caracter; //agrego a subP el caracter tomado
            cont++; //suma uno el contador
            subP=realloc(subP,sizeof(char)*cont); //agrego mas memoria dinamica

            if(n<0){ 
                caracter=*(p+i-cont); //como n<0 tengo que ir moviendome a izquierda
                printf("%c",caracter);
            }
            else{
                caracter=*(p+i+cont); //como n>0 tengo que ir moviendome a derecha 
            }
        }
    }
    *(subP+cont)='\0'; //termino con un '\0'
    return subP;

}


int main(){
    char* str=NULL;
    char* subStr=NULL;
    int i=10, n=4;

    str = leerArch("frase.txt"); 
    subStr = subcadena(str, i, n);

    printf("\n%s\n",str);

    printf("Para i = %d y n = %d ,Se encontro el substring: ", i,n); 
    printf("%s\n\n", subStr);

    return 0; 
}


