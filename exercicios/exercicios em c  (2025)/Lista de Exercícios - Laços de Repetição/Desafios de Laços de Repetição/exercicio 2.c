#include <stdio.h>

int main() {
    char nome_atleta[100];
    float salto, melhor_salto, pior_salto, soma_saltos, media;
    int i;

    while (1) {
        
        printf("Digite o nome do atleta (ou pressione Enter para sair): ");
        fgets(nome_atleta, sizeof(nome_atleta), stdin);
        
        
        if (nome_atleta[0] == '\n') {
            break;
        }

        
        melhor_salto = -1.0;  
        pior_salto = 1000.0; 
        soma_saltos = 0;

        
        for (i = 1; i <= 5; i++) {
            printf("Digite o %dº salto (em metros): ", i);
            scanf("%f", &salto);
            soma_saltos += salto;

            
            if (salto > melhor_salto) {
                melhor_salto = salto;
            }
            if (salto < pior_salto) {
                pior_salto = salto;
            }
        }

        
        soma_saltos -= melhor_salto;
        soma_saltos -= pior_salto;

        
        media = soma_saltos / 3.0;

        
        printf("\nAtleta: %s", nome_atleta);
        printf("Melhor salto: %.1f m\n", melhor_salto);
        printf("Pior salto: %.1f m\n", pior_salto);
        printf("Media dos demais saltos: %.1f m\n", media);
        printf("Resultado final: %.1f m\n\n", media);
    }

    return 0;
}

