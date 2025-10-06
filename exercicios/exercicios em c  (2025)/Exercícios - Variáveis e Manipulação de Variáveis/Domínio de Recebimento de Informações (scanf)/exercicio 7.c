#include <stdio.h>

int main() {
	float numero1=0;
	float numero2=0;
	float multiplicacao=0;
	
	printf("digite dois numeros\n");
	scanf("%f %f",&numero1,&numero2);
	
	multiplicacao=numero1*numero2;

	printf("a multiplicacao dos numeros e:%.2f\n",multiplicacao);


    return 0;
}

