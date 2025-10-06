#include <stdio.h>
#include <math.h>  

int main() {
    float raio, volume;
    const float pi = 3.14159;

    printf("Digite o raio da esfera (em metros): ");
    scanf("%f", &raio);

    volume = (4.0 / 3.0) * pi * pow(raio, 3);

    printf("O volume da esfera e: %.2f metros cubicos.\n", volume);

    return 0;
}

