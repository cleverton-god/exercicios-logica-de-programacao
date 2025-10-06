#include <stdio.h>

int main() {
    int anoNascimento, anoAtual;
    
    printf("Digite o ano de nascimento: ");
    scanf("%d", &anoNascimento);
    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);
    
    int idade = anoAtual - anoNascimento;
    printf("A idade e: %d anos\n", idade);
    
    return 0;
}

