#include <stdio.h>
#include <string.h>

int main() {
    char nome[50], sexo;
    int idade;
    float salario;

    do {
        printf("Digite o nome (maior que 3 caracteres): ");
        scanf("%s", nome); 
    } while (strlen(nome) <= 3); 

    do {
        printf("Digite a idade (entre 0 e 150): ");
        scanf("%d", &idade); 
    } while (idade < 0 || idade > 150); 

    do {
        printf("Digite o salario (maior que zero): ");
        scanf("%f", &salario); 
    } while (salario <= 0); 

    do {
        printf("Digite o sexo ('f' ou 'm'): ");
        scanf(" %c", &sexo); 
    } while (sexo != 'f' && sexo != 'm'); 

    char estado_civil;
    do {
        printf("Digite o estado civil ('s', 'c', 'v', 'd'): ");
        scanf(" %c", &estado_civil);
    } while (estado_civil != 's' && estado_civil != 'c' && estado_civil != 'v' && estado_civil != 'd'); 
    return 0;
}

