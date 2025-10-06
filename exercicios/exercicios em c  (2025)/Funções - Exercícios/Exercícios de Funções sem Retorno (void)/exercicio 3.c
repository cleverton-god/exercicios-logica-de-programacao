#include <stdio.h>

void imprimirTraco() {
    for (int i = 0; i < 20; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    imprimirTraco();
    printf("\n");
    imprimirTraco();
    return 0;
}
