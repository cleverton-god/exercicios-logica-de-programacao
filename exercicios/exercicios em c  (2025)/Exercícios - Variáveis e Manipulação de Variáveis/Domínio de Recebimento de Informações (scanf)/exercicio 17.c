#include <stdio.h>

int main() {
	float celsius=0;
	float Fahrenheit=0;
	
	printf("digite a temperatura em Celsius\n");
	scanf("%f",&celsius);
	
	Fahrenheit=celsius*9/5+32;


	printf("a temperatura em Fahrenheit e:%.2f",Fahrenheit);
	
    return 0;
}

