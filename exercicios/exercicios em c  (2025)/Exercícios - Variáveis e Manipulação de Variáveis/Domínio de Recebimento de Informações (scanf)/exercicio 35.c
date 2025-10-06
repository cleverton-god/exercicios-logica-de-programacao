#include <stdio.h>

int main(){
	float base=0;
	float altura=0;
	float perimetro=0;
	
	printf("digite a base e aperte enter:\n");
	scanf("%f",&base);
	printf("digite a altura e aperte enter:\n");
	scanf("%f",&altura);
	
	perimetro=2*(base+altura);
	
	printf("o perimetro e:%.2f",perimetro);
	
	return 0;
}
