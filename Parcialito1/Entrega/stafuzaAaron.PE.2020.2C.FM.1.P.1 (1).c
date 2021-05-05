/** SECCI�N[0] ---------------- G E N E R A L -------------------------------*/
///////////////////////////////////////////////////////  V E R S I O N   //////
// P R O G R A M A C I � N   E S T R U C T U R A D A //  20200427 19:30  //////
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[1]----- D A T O S   E S T U D I A N T E --------- */
/** ------ C O M P L E T A R    O B L I G A T O R I O ------ */
///////////////////////////////////////////////////////////////////////////////
// FECHA        :  28 / 09 / 2020
// COMISI�N     : FM
// EXAMEN Nro   : 1
// EXAMEN [P|R] : P
// TEMA Nro     : 1
// APELLIDO     : STAFUZA
// NOMBRE       : AARON 
// LEGAJO       : 151621767
// DNI          :  40178767
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


/*El archivo codigod.txt contiene líneas con frases o palabras. La cantidad de líneas es indefinida pero menor a 20. Desarrollar un programa que:
1- Lea el archivo y lo almacene en una matriz.
2- Imprima por pantalla la matriz cargada con los datos del archivo.
3- Con las letras de la diagonal se completa una palabra que se guardará en el arreglo “clave”, de a lo
sumo 20 caracteres, el cuál debe ser impreso como resultado del proceso.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 25
#define C 25
#define N 25

void cargarArrC(char arrC[F][C],char nombre[N]){
    int f,c;
    char i;
    FILE *arch;
    arch=fopen(nombre,"r");

    i=fgetc(arch);
    for(f=0;i!=EOF && f<F && i!=10;f++){ 
        for(c=0;c<C && i!=10;c++){
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

void claveArrC(char arrC[F][C]){
    int f,c,j=0;
    int cont;
    char contrasena[]={0};
    for(f=0;f<F && arrC[f][0]!='\0';f++){
        for(c=0;c<C && arrC[f][c]!='\0';c++){
            if(f==c){
                printf("%c",arrC[f][c]);
            }
        }
    }
}
int main(){
    int num;
    char a[F][C]={0};
    cargarArrC(a,"archivocodigo.txt");
    printf("\nMATRIZ CARGADA:\n");
    imprimirArrC(a);
    printf("\n");
    printf("CLAVE:\n");
    claveArrC(a);
    printf("\n\n");
    
}