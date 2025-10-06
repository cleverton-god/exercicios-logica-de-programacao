#include <stdio.h>

int main(){
	float potencia=0;
	float tensao=0;
	float corrente_eletrica=0;

	printf("digite a potencia em watts e aperte enter:\n");
	scanf("%f",&potencia);
	printf("digite a tensao em volts e aperte enter:\n");
	scanf("%f",&tensao);
	
	corrente_eletrica=potencia/tensao;
	
	printf("a corrente eletrica e:%.2f a ",corrente_eletrica);



	return 0;
}
