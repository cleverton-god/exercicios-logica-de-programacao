#include <stdio.h>

int main(){
	float kelvin=0;
	float fahrenheit=0;


	printf("digite a temperatura em kelvin e aperte enter:\n");
	scanf("%f",&kelvin);

	fahrenheit=(kelvin-273.15)*9/5+32;
	
	printf("a temperatura em fahrenheit e:%.2f",fahrenheit);
	
	return 0;
}
