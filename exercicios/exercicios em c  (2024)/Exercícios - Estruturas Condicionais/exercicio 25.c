#include <stdio.h>
#include <ctype.h> 

int main() {
    char tipo_sanguineo;

    printf("Digite o tipo sanguineo (A, B, AB, O): ");
    scanf(" %c", &tipo_sanguineo);
    tipo_sanguineo = toupper(tipo_sanguineo); 

    if (tipo_sanguineo == 'A') {
        printf("Pode doar para A e AB.\n");
        printf("Pode receber de A e O.\n");
    } else if (tipo_sanguineo == 'B') {
        printf("Pode doar para B e AB.\n");
        printf("Pode receber de B e O.\n");
    } else if (tipo_sanguineo == 'AB') {
        printf("Pode doar para AB.\n");
        printf("Pode receber de todos.\n");
    } else if (tipo_sanguineo == 'O') {
        printf("Pode doar para todos.\n");
        printf("Pode receber de O.\n");
    } else {
        printf("Tipo sanguineo invalido.\n");
    }
    return 0;
}

