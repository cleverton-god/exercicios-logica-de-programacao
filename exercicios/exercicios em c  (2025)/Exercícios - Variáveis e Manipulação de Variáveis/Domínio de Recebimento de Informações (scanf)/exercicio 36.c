#include <stdio.h>

int main(){
	float raio=0;
	float pi=3.14159;
	float perimetro=0;
	
	printf("digite a raio e aperte enter:\n");
	scanf("%f",&raio);
	
	
	perimetro=2*pi*raio;
	
	printf("o perimetro e:%.2f",perimetro);
	
	return 0;
}
