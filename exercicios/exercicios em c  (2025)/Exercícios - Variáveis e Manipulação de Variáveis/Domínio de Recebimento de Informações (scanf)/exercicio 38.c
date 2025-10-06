#include <stdio.h>

int main(){
	float centimetros=0;
	float milimetros=0;
	float metros=0;
	
	printf("digite o valor em centimetros e aperte enter:\n");
	scanf("%f",&centimetros);
	
	metros=centimetros/100;
	milimetros=centimetros*10;
	
	printf("%.2f centimetros,fazendo conversao para metros e:%.2f\n",centimetros,metros);
	printf("%.2f centimetros,fazendo conversao para milimetros e:%.2f\n",centimetros,milimetros);

	
	return 0;
}
