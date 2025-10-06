#include <stdio.h>

int main() {
    int num1, num2, num3;  

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);  

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);  

    printf("Digite o terceiro numero inteiro: ");
    scanf("%d", &num3);  

    int soma = num1 + num2 + num3;  
    float media = soma / 3.0;  

    printf("A soma dos tres numeros e: %d\n", soma); 
    printf("A media dos tres numeros e: %.2f\n", media); 

    return 0;
}

