#include <stdio.h>
#include <math.h>

int main(){
	float altura=0;
	float tempo=0;
	float gravidade=9.81;
	
	printf("digite a altura e aperte enter:\n");
	scanf("%f",&altura);

	tempo=sqrt(2*altura/gravidade);
	
	printf("o tempo em quedalivre e:%.2f m/s",tempo);



	return 0;
}
