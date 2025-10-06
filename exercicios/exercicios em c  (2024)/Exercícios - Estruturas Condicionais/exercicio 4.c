#include <stdio.h>

int main() {
    float temperatura;
    printf("Digite a temperatura do paciente: ");
    scanf("%f", &temperatura);
    
    if (temperatura > 37.0) {
        printf("Febre\n");
    } else if (temperatura < 35.0) {
        printf("Hipotermia\n");
    } else {
        printf("Temperatura normal\n");
    }

    return 0;
}

