#include <stdio.h>

int piso(double num);
int redondeo(double num);
int techo(double num);


int main(){
	double num;
	printf("Ingrese un numero real: ");
	scanf("%lf",&num);
	redondeo(num);
	printf("\nPiso: %d", piso(num));
	printf("\nTecho: %d", techo(num));
	printf("\nRedondeo: %d\n", redondeo(num));

	return 0;
}

int redondeo(double num){
	int redond, num1;
	num1=num;
	if((num-num1)>0.5){
		redond = num1+1;
	}
	else{
		redond = num1-1;
	}
	return redond;
}

int piso(double num){
	int var;
	var=num;
	return var;
}

int techo(double num){
	int techo, num2;
	num2=num;
	techo = num2+1;
	return techo;
}

