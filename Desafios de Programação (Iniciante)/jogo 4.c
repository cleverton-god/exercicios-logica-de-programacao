#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SALAS 10
#define MAX_ITENS 5
#define MAX_COMANDOS 5

typedef struct {
    char descricao[100];
    int norte, sul, leste, oeste;
    char itens[MAX_ITENS][20];
    int num_itens;
} Sala;

typedef struct {
    char nome[20];
    Sala *sala_atual;
    char itens_coletados[MAX_ITENS][20];
    int num_itens_coletados;
} Jogador;

Sala salas[MAX_SALAS];
Jogador jogador;

void inicializar_jogo() {
    
    strcpy(salas[0].descricao, "Voce esta em uma sala escura e fria.");
    salas[0].norte = 1;
    salas[0].sul = -1;
    salas[0].leste = -1;
    salas[0].oeste = -1;
    salas[0].num_itens = 1;
    strcpy(salas[0].itens[0], "chave");

    strcpy(salas[1].descricao, "Voce esta em uma sala iluminada com uma grande porta.");
    salas[1].norte = -1;
    salas[1].sul = 0;
    salas[1].leste = 2;
    salas[1].oeste = -1;
    salas[1].num_itens = 1;
    strcpy(salas[1].itens[0], "espada");

    strcpy(salas[2].descricao, "Voce esta em uma sala com um tesouro brilhante.");
    salas[2].norte = -1;
    salas[2].sul = -1;
    salas[2].leste = -1;
    salas[2].oeste = 1;
    salas[2].num_itens = 1;
    strcpy(salas[2].itens[0], "tesouro");

 
    strcpy(jogador.nome, "Aventureiro");
    jogador.sala_atual = &salas[0];
    jogador.num_itens_coletados = 0;
}

void imprimir_sala_atual() {
    printf("%s\n", jogador.sala_atual->descricao);
    if (jogador.sala_atual->num_itens > 0) {
        printf("Voce ve os seguintes itens na sala:\n");
        for (int i = 0; i < jogador.sala_atual->num_itens; i++) {
            printf("- %s\n", jogador.sala_atual->itens[i]);
        }
    }
}

void mover_jogador(char direcao) {
    int *destino;
    switch (direcao) {
        case 'n':
            destino = &(jogador.sala_atual->norte);
            break;
        case 's':
            destino = &(jogador.sala_atual->sul);
            break;
        case 'l':
            destino = &(jogador.sala_atual->leste);
            break;
        case 'o':
            destino = &(jogador.sala_atual->oeste);
            break;
        default:
            printf("Direcao invalida.\n");
            return;
    }

    if (*destino == -1) {
        printf("Nao e possivel se mover nessa direcao.\n");
    } else {
        jogador.sala_atual = &salas[*destino];
        printf("Voce se moveu para a proxima sala.\n");
    }
}

void pegar_item() {
    for (int i = 0; i < jogador.sala_atual->num_itens; i++) {
        printf("Voce pegou o item: %s\n", jogador.sala_atual->itens[i]);
        strcpy(jogador.itens_coletados[jogador.num_itens_coletados], jogador.sala_atual->itens[i]);
        jogador.num_itens_coletados++;
    }
    jogador.sala_atual->num_itens = 0;
}

void usar_item() {
    if (jogador.num_itens_coletados == 0) {
        printf("Voce nao tem nenhum item para usar.\n");
        return;
    }

    printf("Seus itens:\n");
    for (int i = 0; i < jogador.num_itens_coletados; i++) {
        printf("%d - %s\n", i+1, jogador.itens_coletados[i]);
    }

    int escolha;
    printf("Escolha um item para usar: ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > jogador.num_itens_coletados) {
        printf("Opcao invalida.\n");
        return;
    }

    if (strcmp(jogador.itens_coletados[escolha-1], "chave") == 0) {
        printf("Voce usou a chave e abriu a porta.\n");
    } else if (strcmp(jogador.itens_coletados[escolha-1], "espada") == 0) {
        printf("Voce usou a espada para se defender.\n");
    } else if (strcmp(jogador.itens_coletados[escolha-1], "tesouro") == 0) {
        printf("Voce encontrou o tesouro e venceu o jogo!\n");
        exit(0);
    } else {
        printf("Voce nao sabe como usar esse item.\n");
    }
}

int main() {
    char comando[20];

    inicializar_jogo();

    while (1) {
        imprimir_sala_atual();

        printf("Digite um comando (mover, pegar, usar, sair): ");
        scanf("%s", comando);

        if (strcmp(comando, "mover") == 0) {
            char direcao;
            printf("Para qual direcao voce quer se mover (n/s/l/o)? ");
            scanf(" %c", &direcao);
            mover_jogador(direcao);
        } else if (strcmp(comando, "pegar") == 0) {
            pegar_item();
        } else if (strcmp(comando, "usar") == 0) {
            usar_item();
        } else if (strcmp(comando, "sair") == 0) {
            printf("Voce saiu do jogo.\n");
            break;
        } else {
            printf("Comando invalido.\n");
        }
    }

    return 0;
}
