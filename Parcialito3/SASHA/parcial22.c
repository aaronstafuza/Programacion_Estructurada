/** SECCI�N[0] ---------------- G E N E R A L -------------------------------*/
///////////////////////////////////////////////////////  V E R S I O N   //////
// P R O G R A M A C I � N   E S T R U C T U R A D A //  20200427 19:30  //////
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[1]----- D A T O S   E S T U D I A N T E --------- */
/** ------ C O M P L E T A R    O B L I G A T O R I O ------ */
///////////////////////////////////////////////////////////////////////////////
// FECHA        :  09 / 11 / 2020
// COMISI�N     :	FM
// EXAMEN Nro   :	3
// EXAMEN [P|R] :	P
// TEMA Nro     :
// APELLIDO     : Ibanez Musielack
// NOMBRE       : Sasha
// LEGAJO       : 151622227
// DNI          : 40384833
//
// COMENTARIOS o OBSERVACIONES del estudiante:
// <Usar si desea comunicar algo al profesor corrector>
//
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[2] ---- N O M B R E   D E L   A R C H I V O ------ */
///////////////////////////////////////////////////////////////////////////////
// �Como confeccionar el nombre del archivo ?
// [Apellido].PE.[Anio].[Cuatrimestre].[Comisi�n][NroExamen][TipoExamen][NroTema].c
//
// [Apellido]    -> REEMPLAZAR por tu apellido y nombre, con
//                  la forma apellidoNombre.
//  PE           -> NO se reemplaza, signifa Programaci�n Estructurada.
// [Anio]        -> REEMPLAZAR con dos d�gitos del a�o actual. Ej: 20
// [Cuatrimestre]-> REEMPLAZAR con un d�gito 1 =  1� Cuatr | 2 = 2� Cuatr.
// [Comisi�n]    -> REEMPLAZAR por las dos letras de su comisi�n Ejemplo: BM.
// [NroExamen]   -> REEMPLAZAR por el n�mero (entero) de examen ej: 1.
// [TipoExamen]  -> REEMPLAZAR con P  = Parcial | R = Recuperatorio |
//                  E = Extraordinario.
// [NroTema]     -> REEMPLAZAR por en n�mero(entero) de tema ej: 2.
//  c            -> NO se reemplaza, es la extensi�n del archivo.
//
//
// Un ejemplo del "nombre de un archivo" podria ser:
//
//     Ej ->   alvarezMartin.PE.20.1C.BM.1.P.2.c
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[3]--- E N V � O   D E L   A R C H I V O --------- */
///////////////////////////////////////////////////////////////////////////////
// El archivo .c con la soluci�n deber� ser entregado
// a trav�s de la plataforma EVA UCA
// Dentro de la pagina de la materia en EVA, IR a la
// solapa EVALUACIONES o bien copiar el siguiente link
//
// https://eva.uca.edu.ar/course/view.php?id=1360&section=4
//
// Ah� podr�n encontrar una tarea de entrega de parcialito
// Deber�n hacer click sobre ella y se abrir� una ventana
// donde aparecer� el bot�n 'Agregar Entrega'  en el cual deber�n hacer click
// sobre �l para desplegar una nueva ventana donde podr�n realizar la carga del
// archivo
//
// IMPORTANTE: La tarea ser� abierta pasados los 15 minutos
// del horario del comiezo de la clase y estar� disponible 90 minuto
// Ejemplo: Si tu clase es de 7:45 a 10:15 => la tarea se
//          abrir� a las 8:00 y se cerrar� 9:30
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[4]----- P A R A   E L   P R O F E S O R --------- */
///////////////////////////////////////////////////////////////////////////////
// COMENTARIOS o OBSERVACIONES del PROFESOR:
// <Reservado para uso del profesor>
//
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[5]-- S O L U C I � N   A  L A  C O N S I G N A --*/
// ||||| ///////////////////////////////////////////////////////// ||||| //////
// |||||  ESCRIBA su c�digo de la Soluci�n a partir de AQUI ABAJO  ||||| //////
// vvvvv ///////////////////////////////////////////////////////// vvvvv //////

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 100

typedef struct {
    char fr[100];
    int limite;
    int valido;
}t_frase;

struct s_nodo
{
    t_frase frase;
    struct s_nodo *sig;
};typedef struct s_nodo *t_nodo;

void agregar(t_nodo *lista, t_frase aux);
void cargarLista(t_nodo *lista);
void imprimir(t_nodo lista);
int contar(char *frase, int cont);

int main(){
    t_nodo lista= NULL;
    cargarLista(&lista);
    imprimir(lista);
    return 0;
}

void cargarLista(t_nodo *lista){
    int i =0 , cont=0 ,val=0,lim=0, x=0;
    char frase[N];
    char letra;
    t_frase aux;
    FILE * arch;
    arch=fopen("frases.txt","r");
    if (arch==NULL){
        printf("El archivo no existe");
    }
    else{
        letra=fgetc(arch);
        while (letra!=EOF){
            while(letra!=';'){
                frase[i]=letra;
                i++;
                letra=fgetc(arch);
            }
            frase[i]='\0';
            strcpy(aux.fr,frase);
            x=contar(frase,cont);
           
            fscanf(arch,"%d\n",&lim);
            aux.limite=lim;
            
            if(x<=lim){
                val=1;
            }
            aux.valido=val;
            agregar(lista,aux);
            letra=fgetc(arch);
            i=0,val=0,lim=0,cont=0;
        }
    }
    fclose(arch);
}

void agregar(t_nodo *lista, t_frase aux){
    if ((*lista)==NULL){
        (*lista)=malloc(sizeof(struct s_nodo));
        (*lista)->frase=aux;
        (*lista)->sig=NULL;
    }
    else{
        agregar((&(*lista)->sig),aux);
    }
}

int contar(char *frase,int cont){
    if (frase[cont]!='\0'){
        return 1+contar(frase,cont+1);
    }
}

void imprimir(t_nodo lista){
    if (lista !=NULL){
        printf("%s  %d   %d \n",lista->frase.fr,lista->frase.limite,lista->frase.valido);
        imprimir(lista->sig);
    }
}