#include <stdio.h>
#include <locale.h>

void mostrarTabelaOpcoes() {
    printf("Opcoes disponiveis:\n");
    printf("A - Adicionar\n");
    printf("R - Remover\n");
    printf("L - Listar\n");
    printf("S - Sair\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    mostrarTabelaOpcoes();
    return 0;
}
