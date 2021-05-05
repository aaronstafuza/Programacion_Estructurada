#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define CANTIDAD 10
#define COLUMNAS 2
#define FILAS 10

struct punto{
    float x;
    float y;
};

double normaDe(struct punto punto){
    double norma = sqrt(pow(punto.x,2)+pow(punto.y,2)); //calculo la norma de ambos puntos de la estructura
    return norma;
}

void cargarPuntos(struct punto arregloDePtos[CANTIDAD]){
    int i;
    FILE *arch;

    arch=fopen("puntos.csv","r");
    for(i=0;fscanf(arch,"%f,%f,",&arregloDePtos[i].x,&arregloDePtos[i].y)!= EOF && i < FILAS; i++);

    fclose(arch);
}

double minDistancia(struct punto arregloDePtos[CANTIDAD]){
    struct punto puntoDif;
    int i,l;
    double distMin=0;
    double distEntrePtos=0;

    puntoDif.x=arregloDePtos[0].x-arregloDePtos[1].x;
    puntoDif.y=arregloDePtos[0].y-arregloDePtos[1].y;
    distMin=normaDe(puntoDif);

    for(i=0;i<CANTIDAD;i++){
        for(l=i+1;l<CANTIDAD;l++){
            puntoDif.x=arregloDePtos[i].x-arregloDePtos[l].x;
            puntoDif.y=arregloDePtos[i].y-arregloDePtos[l].y;
            distEntrePtos=normaDe(puntoDif);

            if(distEntrePtos<distMin){
                distMin=distEntrePtos;
            }
        }
    }
    return distMin;
}

double minDistanciaConsecutivos(struct punto arregloDePtos[CANTIDAD]){
    struct punto puntoDif;
    int i,l;
    double distMin=0;
    double distEntrePtos=0;

    puntoDif.x=arregloDePtos[0].x-arregloDePtos[1].x;
    puntoDif.y=arregloDePtos[0].y-arregloDePtos[1].y;
    distMin=normaDe(puntoDif);

    for(i=1;i<CANTIDAD;i++){
        puntoDif.x=arregloDePtos[i].x-arregloDePtos[i+1].x;
        puntoDif.y=arregloDePtos[i].y-arregloDePtos[i+1].y;
        distEntrePtos=normaDe(puntoDif);
    
        if(distEntrePtos<distMin){
            distMin=distEntrePtos;
        }
    }
    return distMin;
}


void imprimirMinDist(struct punto arregloDePtos[CANTIDAD]){
    double distMin=minDistancia(arregloDePtos);
    printf("\nLa minima distancia entre puntos es %lf.\n",distMin);
}

void imprimirMinDistConsecutivos(struct punto arregloDePtos[CANTIDAD]){
    double distMin=minDistanciaConsecutivos(arregloDePtos);
    printf("\nLa minima distancia entre puntos consecutivos es %lf.\n",distMin);
}

int main(){
    struct punto arregloDePtos[CANTIDAD];
    cargarPuntos(arregloDePtos);
    imprimirMinDist(arregloDePtos);
    imprimirMinDistConsecutivos(arregloDePtos);
}