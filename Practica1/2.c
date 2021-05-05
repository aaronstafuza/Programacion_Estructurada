#include <stdio.h>

int suma(int num1, int num2);
int resta(int num1, int num2);
int multiplicacion(int num1, int num2);
int division(int num1, int num2);

int main(){
	int num1, num2;
	char oper;
	printf("Ingrese numero 1: ");
	scanf("%d",&num1);
	printf("Ingrese numero 2: ");
	scanf("%d",&num2);
	getchar();
	printf("Ingrese operacion [+ - / *]: ");
	oper = getchar();
	if (oper=='+'){
		printf("El resultado es: %d\n",multiplicacion(num1,num2));
	}
	else if (oper=='-'){
		printf("El resultado es: %d\n",resta(num1,num2));
	}
	else if (oper=='+'){
		printf("El resultado es: %d\n",suma(num1,num2));
	}
	else{
		printf("El resultado es: %d\n",resta(num1,num2));
	}

}

int suma(int num1, int num2){
	int suma;
	suma=num1+num2;
	return suma;
}

int resta(int num1, int num2){
	int resta;
	if(num1>num2){
		resta=num1-num2;
	}
	else{
		resta=num2-num1;
	}
	return resta;
}

int multiplicacion(int num1, int num2){
	int multi;
	multi=num1*num2;
	return multi;
}

int division(int num1, int num2){
	int division;
	division = num1/num2;
	return division;
}	






