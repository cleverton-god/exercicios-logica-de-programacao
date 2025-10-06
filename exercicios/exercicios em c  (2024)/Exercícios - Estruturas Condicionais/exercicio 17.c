#include <stdio.h>

int main() {
    int saque, notas100, notas50, notas20, notas10, notas5, notas2;
    printf("Digite o valor do saque: ");
    scanf("%d", &saque);
    
    notas100 = saque / 100;
    saque %= 100;
    
    notas50 = saque / 50;
    saque %= 50;
    
    notas20 = saque / 20;
    saque %= 20;
    
    notas10 = saque / 10;
    saque %= 10;
    
    notas5 = saque / 5;
    saque %= 5;
    
    notas2 = saque / 2;
    
    printf("Notas de 100: %d\n", notas100);
    printf("Notas de 50: %d\n", notas50);
    printf("Notas de 20: %d\n", notas20);
    printf("Notas de 10: %d\n", notas10);
    printf("Notas de 5: %d\n", notas5);
    printf("Notas de 2: %d\n", notas2);

    return 0;
}

