#include <stdio.h>

int main() {
    float reais=0;
    char converter;
    float cotacao=0;
    float conversao=0;
    
    printf("digite de qual moeda vc quer converter reais D-dolar E-euro L-libra:\n");
    scanf("%c", &converter);
    
    if (converter == 'D') {
    	printf("digite a cotacao do dolar:\n");
    	scanf("%f", &cotacao);
    	printf("digite o valor em reais:");
    	scanf("%f", &reais);
    	
    	conversao=reais/cotacao;
    	
    	printf("o valor e:%.2f dolares",conversao);
	} else if (converter == 'E') {
    	printf("digite a cotacao do euro:\n");
    	scanf("%f", &cotacao);
    	printf("digite o valor em reais:");
    	scanf("%f", &reais);
    	
    	conversao=reais/cotacao;
    	
    	printf("o valor e:%.2f euros",conversao);
	} else if(converter == 'L') {
    	printf("digite a cotacao do libras:\n");
    	scanf("%f", &cotacao);
    	printf("digite o valor em reais:");
    	scanf("%f", &reais);
    	
    	conversao=reais/cotacao;
    	
    	printf("o valor e:%.2f libras",conversao);
	}else {
		printf("moeda invalida");
	}
    
    return 0;
}

