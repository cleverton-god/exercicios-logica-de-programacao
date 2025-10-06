#include <stdio.h>

int main() {
	float peso=0;
	float altura=0;
	float imc=0;
	
	printf("digite a peso em kg\n");
	scanf("%f",&peso);
	printf("digite a altura metros\n");
	scanf("%f",&altura);
	
	imc=peso/(altura*altura);
	
	
	printf("o imc e:%.2f",imc);
	
    return 0;
}

