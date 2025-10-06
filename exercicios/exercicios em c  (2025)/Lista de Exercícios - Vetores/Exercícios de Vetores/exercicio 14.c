#include <stdio.h>

void bubble_sort_decrescente(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeros[6] = {5, 2, 9, 1, 7, 3};

    bubble_sort_decrescente(numeros, 6);

    printf("Vetor ordenado decrescente: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}

