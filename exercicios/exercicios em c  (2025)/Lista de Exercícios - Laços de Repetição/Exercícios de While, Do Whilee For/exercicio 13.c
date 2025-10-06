#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Numeros gerados: ");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", rand() % 100 + 1);
    }
    printf("\n");

    return 0;
}

