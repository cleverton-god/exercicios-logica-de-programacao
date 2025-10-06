#include <stdio.h>

int main(){
	float densidade=0;
	float altura=0;
	float gravidade=0;
	float pressao=0;
	
	printf("digite a densidade do fluido e aperte enter:\n");
	scanf("%f",&densidade);
	printf("digite a altura e aperte enter:\n");
	scanf("%f",&altura);
	printf("digite a gravidade e aperte enter:\n");
	scanf("%f",&gravidade);

	pressao=densidade*gravidade*altura;
	
	printf("a pressao e:%.2f",pressao);



	return 0;
}
