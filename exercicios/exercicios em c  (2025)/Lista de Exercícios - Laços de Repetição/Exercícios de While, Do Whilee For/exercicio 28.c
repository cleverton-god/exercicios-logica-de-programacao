#include <stdio.h>

int main() {
    int base;
	int expoente;
	int resultado=1;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    printf("%d^%d = %d\n", base, expoente, resultado);
    return 0;
}

