#include <stdio.h>

int main(){
	float tensao=0;
	float corrente_eletrica=0;
	float potencia_eletrica=0;

	printf("digite a tensao em volts e aperte enter:\n");
	scanf("%f",&tensao);
	printf("digite a corrente eletrica em amperes e aperte enter:\n");
	scanf("%f",&corrente_eletrica);
	
	potencia_eletrica=tensao*corrente_eletrica;
	
	printf("a potencia eletrica e:%.2f w ",potencia_eletrica);



	return 0;
}
