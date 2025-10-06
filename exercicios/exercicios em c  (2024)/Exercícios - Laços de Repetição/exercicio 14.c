#include <stdio.h>

int main() {
    int num, primo = 1; 
    printf("Digite um numero inteiro: ");
    scanf("%d", &num); 
    
    if (num < 2) primo = 0; 
    for (int i = 2; i * i <= num; i++) { 
        if (num % i == 0) { 
            primo = 0; 
            break; 
        }
    }
    
    if (primo) {
        printf("%d e primo\n", num); 
    } else {
        printf("%d nao e primo\n", num); 
    }
    return 0;
}

