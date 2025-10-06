#include <stdio.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int vetor[10] = {29, 10, 14, 37, 14, 18, 35, 15, 26, 31};
    selection_sort(vetor, 10);
    printf("Vetor ordenado: ");
    for (int i = 0; i < 10; i++){
	printf("%d ", vetor[i]);
    printf("\n");
	}
    return 0;
}

