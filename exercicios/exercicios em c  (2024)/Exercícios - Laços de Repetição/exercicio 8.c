#include <stdio.h>

int main() {
    int nota; 
    do {
        printf("Digite uma nota entre 0 e 10: ");
        scanf("%d", &nota);
        if (nota < 0 || nota > 10) {
            printf("Nota invalida!\n");
        }
    } while (nota < 0 || nota > 10); 
    return 0;
}

