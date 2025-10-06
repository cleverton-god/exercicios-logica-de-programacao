#include <stdio.h>

int main() {
	float raio=0;
	float pi=3.14;
	float area=0;
	
	printf("digite o raio de um circulo\n");
	scanf("%f",&raio);
	
	area=(pi*raio*raio);
	
	printf("a area do circulo e:%.2f",area);
	
    return 0;
}

