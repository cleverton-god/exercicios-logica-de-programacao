#include <stdio.h>

int main(){
	float diametro=0;
	float comprimento=0;
	double pi=3.14159;

	printf("digite o diametro da circuferencia e aperte enter:\n");
	scanf("%f",&diametro);

	comprimento=pi*diametro;
	
	printf("o comprimento da circuferencia e:%f",comprimento);
	
	return 0;
}
