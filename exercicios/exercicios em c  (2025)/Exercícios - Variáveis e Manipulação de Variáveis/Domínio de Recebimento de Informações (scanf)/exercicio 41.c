#include <stdio.h>

int main(){
	float celsius=0;
	float kelvin=0;


	printf("digite a temperatura em kelvin e aperte enter:\n");
	scanf("%f",&kelvin);

	celsius=kelvin-273.15;
	
	printf("a temperatura em celsius e:%.2f",celsius);
	
	return 0;
}
