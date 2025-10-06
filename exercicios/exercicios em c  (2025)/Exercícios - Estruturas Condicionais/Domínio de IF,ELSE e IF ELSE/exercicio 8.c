#include <stdio.h>

int main() {
    int saque, nota100, nota50, nota20, nota10, nota5, nota2;

    
    printf("Digite o valor do saque: R$ ");
    scanf("%d", &saque);

   
    nota100 = saque / 100;
    saque = saque % 100;

    
    nota50 = saque / 50;
    saque = saque % 50;

    
    nota20 = saque / 20;
    saque = saque % 20;

    
    nota10 = saque / 10;
    saque = saque % 10;

    
    nota5 = saque / 5;
    saque = saque % 5;

    
    nota2 = saque / 2;
    saque = saque % 2;

    
    printf("\nNotas fornecidas:\n");
    if (nota100 > 0) printf("Notas de R$ 100: %d\n", nota100);
    if (nota50 > 0) printf("Notas de R$ 50: %d\n", nota50);
    if (nota20 > 0) printf("Notas de R$ 20: %d\n", nota20);
    if (nota10 > 0) printf("Notas de R$ 10: %d\n", nota10);
    if (nota5 > 0) printf("Notas de R$ 5: %d\n", nota5);
    if (nota2 > 0) printf("Notas de R$ 2: %d\n", nota2);

    return 0;
}

