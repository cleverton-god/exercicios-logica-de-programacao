#include <stdio.h>

int main(){
	float distancia_milhas=0;
	float distancia_quilometros=0;

	printf("digite a distancia em milhas e aperte enter:\n");
	scanf("%f",&distancia_milhas);

	distancia_quilometros=distancia_milhas*1.60934;
	
	printf("a distancia em quilometros e:%.2f km",distancia_quilometros);



	return 0;
}
