#include <stdio.h>
#include <stdlib.h>

#define N 20

int* fun1(int arreglo[N],int pos){
    return &arreglo[pos];
}

int main(){
    int arr[5];
    int *direccion=fun1(arr,3);
    printf("%p\n",&arr);
    printf("%p\n",direccion);
    printf("%d\n",*direccion);
    return 0;

}
