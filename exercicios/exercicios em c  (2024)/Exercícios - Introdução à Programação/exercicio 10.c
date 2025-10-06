#include <stdio.h>

int main() {
    int num1, num2; 

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1); 

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);  

    int soma = num1 + num2;  
    int subtracao = num1 - num2; 

    printf("A soma de %d e %d = %d.\n", num1, num2, soma); 
    printf("A subtracao de %d e %d = %d.\n", num1, num2, subtracao); 

    return 0;
}

