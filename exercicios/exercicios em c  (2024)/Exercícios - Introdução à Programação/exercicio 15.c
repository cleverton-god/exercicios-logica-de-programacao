#include <stdio.h>

int main() {
    int num1, num2;  

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1); 

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);  

    float media = (num1 + num2) / 2.0; 

    printf("A média aritmética entre %d e %d e: %.2f\n", num1, num2, media); 

    return 0;
}

