#include <stdio.h>

int main() {
    int dias;
    
    printf("Digite a quantidade de dias: ");
    scanf("%d", &dias);
    
    int semanas = dias / 7;
    int diasRestantes = dias % 7;
    
    printf("Equivale a %d semanas e %d dias\n", semanas, diasRestantes);
    
    return 0;
}

