#include <stdio.h>

int main() {
	int num1,num2;
	
	printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1); 
    
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2); 
    
    int multiplicacao=num1 * num2;
    
    printf("a multiplicacao de %d e %d= %d\n",num1,num2,multiplicacao);
	
	return 0;
}
  
