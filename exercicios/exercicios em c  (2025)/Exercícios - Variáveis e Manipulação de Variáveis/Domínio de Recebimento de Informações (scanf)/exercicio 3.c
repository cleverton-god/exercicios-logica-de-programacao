#include <stdio.h>

int main() {
	float numero1=0;
	float numero2=0;
	float soma=0;
	
	printf("digite dois numeros\n");
	scanf("%f %f",&numero1,&numero2);
	
	soma=numero1+numero2;

	printf("a soma dos numeros e:%.2f",soma);
    return 0;
}

