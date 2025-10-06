#include <stdio.h>

int main() {
	float numero1=0;
	float numero2=0;
	float divisao=0;
	
	printf("digite dois numeros\n");
	scanf("%f %f",&numero1,&numero2);
	
	divisao=numero1/numero2;

	printf("a divisao dos numeros e:%.2f\n",divisao);


    return 0;
}

