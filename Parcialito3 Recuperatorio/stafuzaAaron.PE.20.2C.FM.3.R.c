/** SECCI�N[0] ---------------- G E N E R A L -------------------------------*/
///////////////////////////////////////////////////////  V E R S I O N   //////
// P R O G R A M A C I � N   E S T R U C T U R A D A //  20200427 19:30  //////
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[1]----- D A T O S   E S T U D I A N T E --------- */
/** ------ C O M P L E T A R    O B L I G A T O R I O ------ */
///////////////////////////////////////////////////////////////////////////////
// FECHA        :  16 / 11 / 2020
// COMISI�N     : FM
// EXAMEN Nro   : 3
// EXAMEN [P|R] : R
// TEMA Nro     : -
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

#define N 50
#define T 5

typedef struct {
    char nombre[N];
    int notas[T]; // finaliza con -1
    int max;
}t_dato;

struct s_nodo{
    t_dato dato;
    struct s_nodo *sig;
};typedef struct s_nodo *t_nodo;

void cargarListaO(t_nodo *lista, char *nomArch);
int retornarNumeroMasGrandeDelArreglo(int *arreglo);
void imprimir(t_nodo lista);
void agregarALista(t_nodo *dirDelNodo, t_dato valor);

int main(){
    t_nodo lista = NULL;
    char *nomArch = "calificaciones.txt";
    cargarListaO(&lista,nomArch);
    printf("NOMBRE -------- NOTAS -------- NOTA MAXIMA\n\n");
    imprimir(lista);
    return 0;
}

void cargarListaO(t_nodo *lista, char *nomArch)
{
    t_dato aux;
    int i = 0, j = 0;
    int max;
    char letra, letra_nom;
    char arreglo[N];
    int arreglo2[T];
    int notas = 0;
    FILE *arch;
    arch = fopen(nomArch, "r");
    if (arch == NULL)
    {
        printf("ERROR en la apertura del archivo.");
    }
    else
    {
        letra = fgetc(arch);
        while (letra != EOF)
        {
            while (letra != ',')
            {
                arreglo[i] = letra;
                i++;
                letra = fgetc(arch);
            }
            arreglo[i] = '\0';
            strcpy(aux.nombre, arreglo);
            fscanf(arch, "%d,%d,%d,%d\n", &arreglo2[0], &arreglo2[1],&arreglo2[2],&arreglo2[3]);
            arreglo2[4]=-1;
            aux.notas[0] = arreglo2[0];
            aux.notas[1] = arreglo2[1];
            aux.notas[2] = arreglo2[2];
            aux.notas[3] = arreglo2[3];
            aux.notas[4] = arreglo2[4];
            max=retornarNumeroMasGrandeDelArreglo(arreglo2);
            aux.max=max;

            agregarALista(lista, aux);
            letra = fgetc(arch);
            i = 0, j = 0, notas = 0, max = 0;
        }
    }
}

int retornarNumeroMasGrandeDelArreglo(int *arreglo)
{

    int numeroDeFuncionActual = *(arreglo); 
    int numeroDeFuncionAnterior = 0;        

    if (*(arreglo) != -1)
    {
        numeroDeFuncionAnterior = retornarNumeroMasGrandeDelArreglo(arreglo + 1); 

        
        if (numeroDeFuncionAnterior == 0){
            return numeroDeFuncionActual;
        }

        if (numeroDeFuncionActual > numeroDeFuncionAnterior){
            return numeroDeFuncionActual; 
        }
        else{
            return numeroDeFuncionAnterior; 
        }
    }
    else
        return 0; 
}

void imprimir(t_nodo lista){
    int i=0;
    if (lista != NULL){
        printf("%s  ----  ", lista->dato.nombre);
        while(lista->dato.notas[i] != -1){
            printf("%d,",lista->dato.notas[i]);
            i++;
        }
        printf("---- %d\n",lista->dato.max);
        imprimir(lista->sig);
    }
}
void agregarALista(t_nodo*dirDelNodo, t_dato valor)
{
    if ((*dirDelNodo) == NULL)
    {
        (*dirDelNodo) = malloc(sizeof(struct s_nodo));
        (*dirDelNodo)->dato = valor;
        (*dirDelNodo)->sig = NULL;
    }
    else
    {
        agregarALista(&((*dirDelNodo)->sig), valor);
    }
}