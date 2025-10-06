#include <stdio.h>
#include <string.h>

int main() {
    char tipo[3];


    printf("Digite o tipo sanguíneo (A+, A-, B+, B-, AB+, AB-, O+, O-): ");
    scanf("%s", tipo);

   
    printf("\nDoação e recebimento de sangue para %s:\n", tipo);

    if (strcmp(tipo, "A+") == 0) {
        printf("Pode doar para: A+, AB+\n");
        printf("Pode receber de: A+, A-, O+, O-\n");
    } else if (strcmp(tipo, "A-") == 0) {
        printf("Pode doar para: A+, A-, AB+, AB-\n");
        printf("Pode receber de: A-, O-\n");
    } else if (strcmp(tipo, "B+") == 0) {
        printf("Pode doar para: B+, AB+\n");
        printf("Pode receber de: B+, B-, O+, O-\n");
    } else if (strcmp(tipo, "B-") == 0) {
        printf("Pode doar para: B+, B-, AB+, AB-\n");
        printf("Pode receber de: B-, O-\n");
    } else if (strcmp(tipo, "AB+") == 0) {
        printf("Pode doar para: AB+\n");
        printf("Pode receber de: A+, A-, B+, B-, AB+, AB-, O+, O-\n");
    } else if (strcmp(tipo, "AB-") == 0) {
        printf("Pode doar para: AB+, AB-\n");
        printf("Pode receber de: A-, B-, AB-, O-\n");
    } else if (strcmp(tipo, "O+") == 0) {
        printf("Pode doar para: A+, B+, O+, AB+\n");
        printf("Pode receber de: O+, O-\n");
    } else if (strcmp(tipo, "O-") == 0) {
        printf("Pode doar para: A+, B+, O+, AB+, A-, B-, O-, AB-\n");
        printf("Pode receber de: O-\n");
    } else {
        printf("Tipo sanguíneo inválido!\n");
    }

    return 0;
}

