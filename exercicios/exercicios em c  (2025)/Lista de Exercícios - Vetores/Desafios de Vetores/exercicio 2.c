#include <stdio.h>
#include <math.h>

void desvio_padrao() {
    double numeros[10], soma = 0, media, variancia = 0;
    printf("Digite 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &numeros[i]);
        soma += numeros[i];
    }
    media = soma / 10;
    for (int i = 0; i < 10; i++) {
        variancia += pow(numeros[i] - media, 2);
    }
    variancia /= 10;
    printf("Desvio Padrao: %.2lf\n", sqrt(variancia));
}

int main() {
    desvio_padrao();
    return 0;
}

