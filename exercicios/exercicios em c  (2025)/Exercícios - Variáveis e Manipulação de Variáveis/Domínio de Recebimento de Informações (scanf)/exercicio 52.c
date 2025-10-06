#include <stdio.h>

int main(){
	float raio=0;
	float altura=0;
	float pi=3.14159;
	float volume=0;

	printf("digite o raio da base e aperte enter:\n");
	scanf("%f",&raio);
	printf("digite a altura do cilindro e aperte enter:\n");
	scanf("%f",&altura);
	
	volume=pi*(raio*raio)*altura;
	
	printf("o volume e:%.2f",volume);



	return 0;
}
