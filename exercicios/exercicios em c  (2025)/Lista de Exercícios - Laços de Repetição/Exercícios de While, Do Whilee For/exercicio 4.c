#include <stdio.h>

int main() {
    printf("Lojas Quase Dois - Tabela de preços\n");
    for (int i = 1; i <= 50; i++) {
        printf("%d - R$ %.2f\n", i, i * 1.99);
    }
    return 0;
}

