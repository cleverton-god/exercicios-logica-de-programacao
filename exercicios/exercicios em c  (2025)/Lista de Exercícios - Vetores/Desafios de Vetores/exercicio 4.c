#include <stdio.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int vetor[10] = {12, 11, 13, 5, 6, 7, 1, 9, 10, 3};
    insertion_sort(vetor, 10);
    printf("Vetor ordenado:\n");
    for (int i = 0; i < 10; i++){
	printf("%d ", vetor[i]);
    printf("\n");
	} 
    return 0;
}

