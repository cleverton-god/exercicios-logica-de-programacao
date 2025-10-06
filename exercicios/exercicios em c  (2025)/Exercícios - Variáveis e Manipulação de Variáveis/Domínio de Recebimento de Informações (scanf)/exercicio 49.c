#include <stdio.h>

int main(){
	float velocidade=0;
	float tempo=0;
	float deslocamento=0;

	printf("digite a velocidade e aperte enter:\n");
	scanf("%f",&velocidade);
	printf("digite o tempo e aperte enter:\n");
	scanf("%f",&tempo);
	
	deslocamento=velocidade*tempo;
	
	printf("o deslocamento e:%.2f ",deslocamento);



	return 0;
}
