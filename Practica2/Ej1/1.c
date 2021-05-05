#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct punto{
    float x;
    float y;
};

double normaDe(struct punto punto){
    double norma = sqrt(pow(punto.x,2)+pow(punto.y,2)); //calculo la norma de ambos puntos de la estructura
    return norma;
}

int puntoLejano(struct punto punto1, struct punto punto2){
    double normaPunto1=normaDe(punto1);
    double normaPunto2=normaDe(punto2);
    int p = 0; //variable para guardar el punto mas lejano.

    if(normaPunto1>normaPunto2){
        p=1;
    }

    else if(normaPunto2>normaPunto1){
        p=2;
    }

    else{
        p=0;
    }
    return p;
}
void imorimirPunto(struct punto punto1, struct punto punto2){
    int num = puntoLejano(punto1,punto2);
    
    if(num==1){
        printf("El punto 1 (%.2f,%.2f) es el punto mas lejano.\n",punto1.x,punto1.y);
    }
    else if(num==2){
        printf("El punto 2 (%.2f,%.2f) es el punto mas lejano.\n",punto2.x,punto2.y);
    }
    else{
        printf("Ambos numeros estan a igual de distancia.\n");
    }
}
int main(){
    struct punto punto1;
    struct punto punto2;

    printf("Cargar coordenada X del pto 1:");
    scanf("%f",&punto1.x);

    printf("Cargar coordenada Y del pto 1:");
    scanf("%f",&punto1.y);

    printf("Cargar coordenada X del pto 1:");
    scanf("%f",&punto2.x);

    printf("Cargar coordenada Y del pto 1:");
    scanf("%f",&punto2.y);

    imorimirPunto(punto1,punto2);
    return 0;
}