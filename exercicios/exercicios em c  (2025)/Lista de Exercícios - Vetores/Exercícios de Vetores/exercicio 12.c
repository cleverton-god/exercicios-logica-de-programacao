#include <stdio.h>

int eh_primo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int numeros[10] = {2, 3, 4, 5, 6, 7, 8, 9, 11, 13};

    printf("Numeros primos: ");
    for (int i = 0; i < 10; i++) {
        if (eh_primo(numeros[i])) {
            printf("%d ", numeros[i]);
        }
    }

    return 0;
}

