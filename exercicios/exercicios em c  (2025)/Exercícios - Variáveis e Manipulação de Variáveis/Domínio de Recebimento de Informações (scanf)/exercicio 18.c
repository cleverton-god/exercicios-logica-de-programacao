#include <stdio.h>

int main() {
	float celsius=0;
	float Fahrenheit=0;
	
	printf("digite a temperatura em Fahrenheit\n");
	scanf("%f",&Fahrenheit);
	
	celsius= (Fahrenheit-32)*5/9;


	printf("a temperatura em celsius e:%.2f",celsius);
	
    return 0;
}

