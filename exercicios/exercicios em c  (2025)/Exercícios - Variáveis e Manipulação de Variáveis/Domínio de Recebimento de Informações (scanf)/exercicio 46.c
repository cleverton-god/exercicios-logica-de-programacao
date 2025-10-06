#include <stdio.h>

int main(){
	float massa=0;
	float velocidade=0;
	float energia_cinetica=0;

	printf("digite a massa e aperte enter:\n");
	scanf("%f",&massa);
	printf("digite a velocidade e aperte enter:\n");
	scanf("%f",&velocidade);
	
	energia_cinetica=(massa*velocidade)/2;
	
	printf("a energia cinetica e:%.2f ",energia_cinetica);



	return 0;
}
