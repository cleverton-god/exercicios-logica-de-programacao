#include <stdio.h>

int main() {
    int num1, num2;  

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1); 

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);  

    if (num2 != 0) {  
        int divisao = num1 / num2;  

        printf("A divisao de %d por %d = %d.\n", num1, num2, divisao); 
    } else {
        printf("Erro: divisao por zero nao e permitida.\n");
    }

    return 0;
}

