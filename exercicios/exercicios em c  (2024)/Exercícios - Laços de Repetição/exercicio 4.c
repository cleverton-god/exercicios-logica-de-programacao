#include <stdio.h>

int main() {
    printf("Numeros impares entre 1 e 50:\n");
    for (int i = 1; i < 50; i += 2) { 
        printf("%d ", i); 
    }
    printf("\n");
    return 0;
}

