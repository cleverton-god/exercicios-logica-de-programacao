#include <stdio.h>

int main(){
	float velocidade_onda=0;
	float comprimento_onda=0;
	float frequencia=0;

	printf("digite a velocidade da onda e aperte enter:\n");
	scanf("%f",&velocidade_onda);
	printf("digite o comprimento de onda e aperte enter:\n");
	scanf("%f",&comprimento_onda);
	
	frequencia=velocidade_onda/comprimento_onda;
	
	printf("a frequencia e:%.2f ",frequencia);



	return 0;
}
