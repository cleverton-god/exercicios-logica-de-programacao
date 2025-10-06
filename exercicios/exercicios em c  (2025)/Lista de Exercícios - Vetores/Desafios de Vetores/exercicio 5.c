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

int busca_binaria(int arr[], int n, int chave) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (arr[meio] == chave)
            return meio;
        if (arr[meio] < chave)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return -1;
}

int main() {
    int vetor[10] = {29, 10, 14, 37, 14, 18, 35, 15, 26, 31};
    selection_sort(vetor, 10);
    int numero;
    printf("Digite um numero para buscar: ");
    scanf("%d", &numero);
    int pos = busca_binaria(vetor, 10, numero);
    if (pos != -1) {
        printf("Numero encontrado na posicao %d\n", pos);
    } else {
        printf("Numero nao encontrado\n");
    }
    return 0;
}

