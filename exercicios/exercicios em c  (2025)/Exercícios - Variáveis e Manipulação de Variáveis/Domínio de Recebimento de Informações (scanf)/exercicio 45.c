#include <stdio.h>

int main(){
	float velocidade_hmhora=0;
	float velocidade_ms=0;

	printf("digite a velocidade em hm/h e aperte enter:\n");
	scanf("%f",&velocidade_hmhora);
	
	velocidade_ms=velocidade_hmhora/3.6;
	
	printf("a velocidade em m/s e:%.2f m/s",velocidade_ms);



	return 0;
}
