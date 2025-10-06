/*
===============================================================
            JOGO: EXPLORADOR DE MASMORRAS
            LINGUAGEM: C
            AUTOR: Cleverton Rosa
            DESCRICAO: RPG textual completo com sistema de 
            masmorra, combate, itens, missoes, NPCs, evolucao, 
            classes,loja, magias, eventos aleatorios 
            e muito mais.
===============================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define LIMPAR_TELA "cls"
#define MAX_ITENS 10
#define MAX_NOME 30
#define MAX_INIMIGOS 6
#define MAX_HABILIDADES 3
#define MAX_MISSOES 5
#define MAX_TALENTOS 3
#define MAX_CRIACOES 5
#define MAX_DIARIO 15

#define COR_VERMELHO 12
#define COR_VERDE 10
#define COR_AMARELO 14
#define COR_AZUL 9
#define COR_BRANCO 15
#define COR_ROXO 13
#define COR_CIANO 11

typedef enum { GUERREIRO, MAGO, ARQUEIRO } Classe;
typedef enum { ORDEM, CAOS, NEUTRO } Faccao;

typedef struct {
    char nome[MAX_NOME];
    int dano;
    int custo_mana;
    int combo;
    char descricao[100];
} Habilidade;

typedef struct {
    char nome[MAX_NOME];
    int bonus_forca;
    int bonus_defesa;
    int bonus_agilidade;
    int bonus_inteligencia;
    int nivel_requerido;
    int ativo;
    char descricao[100];
} Talento;

typedef struct {
    char descricao[100];
    int recompensa_ouro;
    int recompensa_xp;
    int objetivo;
    int progresso;
    int ativa;
} Missao;

typedef struct {
    char nome[MAX_NOME];
    int vida;
    int mana; 
    int preco;
    int forca;
    int defesa;
    int agilidade;
    int inteligencia;
    int equipado;
    int tipo;
} Item;


typedef struct {
    char nome[MAX_NOME];
    int vida;
    int dano;
    int defesa;
    int mana;
    Habilidade habilidade;
    int chefe;
} Inimigo;

typedef struct {
    char receita[100];
    Item materiais[2];
    Item resultado;
} Criacao;

typedef struct {
    char nome[MAX_NOME];
    Classe classe;
    Faccao faccao;
    int vida;
    int vida_max;
    int mana;
    int mana_max;
    int forca;
    int defesa;
    int agilidade;
    int inteligencia;
    int ouro;
    int nivel;
    int xp;
    Item inventario[MAX_ITENS];
    int num_itens;
    int posicao;
    int andar;
    Habilidade habilidades[MAX_HABILIDADES];
    Missao missoes[MAX_MISSOES];
    int num_missoes;
    Talento talentos[MAX_TALENTOS];
    int num_talentos;
    int reliquia;
    int veneno;
    int bonus_dano;
    char diario[MAX_DIARIO][100];
    int num_diario;
    char rank;
} Jogador;

// Prototipos de funcoes
void limpar_tela();
void pausar(int ms);
void mostrar_borda(HANDLE console);
void limpar_buffer_entrada();
int ler_opcao();
void adicionar_diario(Jogador *jogador, const char *evento);
void inicializar_jogador(Jogador *jogador, HANDLE console);
void inicializar_inimigos(Inimigo inimigos[]);
void inicializar_criacoes(Criacao criacoes[]);
void mostrar_status(Jogador *jogador, HANDLE console);
void mostrar_menu_principal(Jogador *jogador, HANDLE console);
void mover(Jogador *jogador, Inimigo inimigos[], Criacao criacoes[], HANDLE console);
void encontrar_bau(Jogador *jogador, HANDLE console);
void encontrar_ouro(Jogador *jogador, HANDLE console);
int batalha(Jogador *jogador, Inimigo *inimigo, int clima, HANDLE console);
int usar_habilidade(Jogador *jogador, int *ultimo_ataque, int penalidade_clima, HANDLE console);
void ver_inventario(Jogador *jogador, HANDLE console);
void usar_item(Jogador *jogador, int indice, HANDLE console);
void equipar_item(Jogador *jogador, int indice, HANDLE console);
void resolver_puzzle(Jogador *jogador, HANDLE console);
void evento_narrativo(Jogador *jogador, HANDLE console);
void interagir_npc(Jogador *jogador, HANDLE console);
void loja(Jogador *jogador, HANDLE console);
void criar_item(Jogador *jogador, Criacao criacoes[], HANDLE console);
void gerenciar_missoes(Jogador *jogador, HANDLE console);
void aceitar_missao(Jogador *jogador, HANDLE console);
void verificar_missoes(Jogador *jogador, HANDLE console);
void gerenciar_talentos(Jogador *jogador, HANDLE console);
void ver_diario(Jogador *jogador, HANDLE console);
void salvar_jogo(Jogador *jogador, HANDLE console);
void carregar_jogo(Jogador *jogador, HANDLE console);
void ganhar_xp(Jogador *jogador, int xp, HANDLE console);
void subir_nivel(Jogador *jogador, HANDLE console);
void mostrar_introducao(Jogador *jogador, HANDLE console);
void atualizar_rank(Jogador *jogador);

void limpar_tela() {
    system(LIMPAR_TELA);
}

void pausar(int ms) {
    Sleep(ms);
}

void mostrar_borda(HANDLE console) {
    SetConsoleTextAttribute(console, COR_AZUL);
    printf("====================================\n");
    SetConsoleTextAttribute(console, COR_BRANCO);
}

void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int ler_opcao() {
    int opcao;
    while (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida! Digite um numero: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    return opcao;
}

void adicionar_diario(Jogador *jogador, const char *evento) {
    if (jogador->num_diario < MAX_DIARIO) {
        snprintf(jogador->diario[jogador->num_diario], 100, "%s", evento);
        jogador->num_diario++;
    }
}

void inicializar_jogador(Jogador *jogador, HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("Digite o nome do personagem: ");
    scanf("%29s", jogador->nome);
    limpar_buffer_entrada();

    SetConsoleTextAttribute(console, COR_AMARELO);
    printf("Escolha a classe:\n");
    printf("1. Guerreiro - Forte e resistente, ideal para combate corpo a corpo.\n");
    printf("2. Mago - Mestre em magia, fragil mas poderoso.\n");
    printf("3. Arqueiro - Agil e preciso, ideal para ataques a distancia.\n");
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("Escolha (1-3): ");
    int escolha_classe = ler_opcao();

    SetConsoleTextAttribute(console, COR_AMARELO);
    printf("Escolha a faccao:\n");
    printf("1. Ordem - Honra e disciplina, bonus em defesa.\n");
    printf("2. Caos - Liberdade e astucia, bonus em dano.\n");
    printf("3. Neutro - Equilibrado, bonus em ouro.\n");
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("Escolha (1-3): ");
    int escolha_faccao = ler_opcao();

    jogador->vida_max = 100;
    jogador->mana_max = 50;
    jogador->vida = jogador->vida_max;
    jogador->mana = jogador->mana_max;
    jogador->ouro = 50;
    jogador->nivel = 1;
    jogador->xp = 0;
    jogador->num_itens = 0;
    jogador->posicao = 0;
    jogador->andar = 1;
    jogador->num_missoes = 0;
    jogador->num_talentos = 0;
    jogador->reliquia = 0;
    jogador->veneno = 0;
    jogador->bonus_dano = 0;
    jogador->num_diario = 0;
    jogador->rank = 'D';

    memset(jogador->habilidades, 0, sizeof(jogador->habilidades));
    memset(jogador->talentos, 0, sizeof(jogador->talentos));
    memset(jogador->missoes, 0, sizeof(jogador->missoes));
    memset(jogador->inventario, 0, sizeof(jogador->inventario));
    memset(jogador->diario, 0, sizeof(jogador->diario));

    switch (escolha_classe) {
        case 1: {
            jogador->classe = GUERREIRO;
            jogador->forca = 15;
            jogador->defesa = 10;
            jogador->agilidade = 5;
            jogador->inteligencia = 3;
            strcpy(jogador->habilidades[0].nome, "Golpe Poderoso");
            jogador->habilidades[0].dano = 20;
            jogador->habilidades[0].custo_mana = 10;
            jogador->habilidades[0].combo = 1;
            strcpy(jogador->habilidades[0].descricao, "Causa dano extra");
            strcpy(jogador->talentos[0].nome, "Furia");
            jogador->talentos[0].bonus_forca = 5;
            jogador->talentos[0].nivel_requerido = 2;
            strcpy(jogador->talentos[0].descricao, "Aumenta forca");
            break;
        }
        case 2: {
            jogador->classe = MAGO;
            jogador->forca = 5;
            jogador->defesa = 3;
            jogador->agilidade = 7;
            jogador->inteligencia = 15;
            strcpy(jogador->habilidades[0].nome, "Bola de Fogo");
            jogador->habilidades[0].dano = 25;
            jogador->habilidades[0].custo_mana = 15;
            jogador->habilidades[0].combo = 1;
            strcpy(jogador->habilidades[0].descricao, "Explosao ardente");
            strcpy(jogador->talentos[0].nome, "Foco");
            jogador->talentos[0].bonus_inteligencia = 5;
            jogador->talentos[0].nivel_requerido = 2;
            strcpy(jogador->talentos[0].descricao, "Aumenta inteligencia");
            break;
        }
        case 3: {
            jogador->classe = ARQUEIRO;
            jogador->forca = 8;
            jogador->defesa = 5;
            jogador->agilidade = 12;
            jogador->inteligencia = 8;
            strcpy(jogador->habilidades[0].nome, "Tiro Preciso");
            jogador->habilidades[0].dano = 18;
            jogador->habilidades[0].custo_mana = 12;
            jogador->habilidades[0].combo = 1;
            strcpy(jogador->habilidades[0].descricao, "Ataque preciso");
            strcpy(jogador->talentos[0].nome, "Velocidade");
            jogador->talentos[0].bonus_agilidade = 5;
            jogador->talentos[0].nivel_requerido = 2;
            strcpy(jogador->talentos[0].descricao, "Aumenta agilidade");
            break;
        }
        default: {
            jogador->classe = GUERREIRO;
            jogador->forca = 10;
            jogador->defesa = 5;
            jogador->agilidade = 5;
            jogador->inteligencia = 5;
            break;
        }
    }

    switch (escolha_faccao) {
        case 1: {
            jogador->faccao = ORDEM;
            jogador->defesa += 3;
            break;
        }
        case 2: {
            jogador->faccao = CAOS;
            jogador->forca += 3;
            break;
        }
        case 3: {
            jogador->faccao = NEUTRO;
            jogador->ouro += 20;
            break;
        }
        default: {
            jogador->faccao = NEUTRO;
            break;
        }
    }

    char evento[100];
    snprintf(evento, 100, "Iniciou aventura como %s da faccao %s",
             jogador->classe == GUERREIRO ? "Guerreiro" : jogador->classe == MAGO ? "Mago" : "Arqueiro",
             jogador->faccao == ORDEM ? "Ordem" : jogador->faccao == CAOS ? "Caos" : "Neutro");
    adicionar_diario(jogador, evento);
    mostrar_introducao(jogador, console);
}

void inicializar_inimigos(Inimigo inimigos[]) {
    strcpy(inimigos[0].nome, "Goblin");
    inimigos[0].vida = 50;
    inimigos[0].dano = 10;
    inimigos[0].defesa = 2;
    inimigos[0].mana = 0;
    inimigos[0].chefe = 0;

    strcpy(inimigos[1].nome, "Esqueleto");
    inimigos[1].vida = 70;
    inimigos[1].dano = 15;
    inimigos[1].defesa = 5;
    inimigos[1].mana = 0;
    inimigos[1].chefe = 0;

    strcpy(inimigos[2].nome, "Troll");
    inimigos[2].vida = 100;
    inimigos[2].dano = 20;
    inimigos[2].defesa = 10;
    inimigos[2].mana = 0;
    inimigos[2].chefe = 0;

    strcpy(inimigos[3].nome, "Xama Orc");
    inimigos[3].vida = 80;
    inimigos[3].dano = 12;
    inimigos[3].defesa = 5;
    inimigos[3].mana = 30;
    strcpy(inimigos[3].habilidade.nome, "Cura");
    inimigos[3].habilidade.dano = -20;
    inimigos[3].habilidade.custo_mana = 10;
    inimigos[3].chefe = 0;

    strcpy(inimigos[4].nome, "Necromante");
    inimigos[4].vida = 120;
    inimigos[4].dano = 18;
    inimigos[4].defesa = 8;
    inimigos[4].mana = 40;
    strcpy(inimigos[4].habilidade.nome, "Invocacao");
    inimigos[4].habilidade.dano = 25;
    inimigos[4].habilidade.custo_mana = 15;
    inimigos[4].chefe = 0;

    strcpy(inimigos[5].nome, "Guardiao Sombrio");
    inimigos[5].vida = 200;
    inimigos[5].dano = 30;
    inimigos[5].defesa = 20;
    inimigos[5].mana = 60;
    strcpy(inimigos[5].habilidade.nome, "Raio Negro");
    inimigos[5].habilidade.dano = 40;
    inimigos[5].habilidade.custo_mana = 20;
    inimigos[5].chefe = 1;
}

void inicializar_criacoes(Criacao criacoes[]) {
    strcpy(criacoes[0].receita, "Pocao Forte: 2 Pocoes + 1 Erva");
    strcpy(criacoes[0].materiais[0].nome, "Pocao");
    criacoes[0].materiais[0].tipo = 0;
    strcpy(criacoes[0].materiais[1].nome, "Erva");
    criacoes[0].materiais[1].tipo = 2;
    strcpy(criacoes[0].resultado.nome, "Pocao Forte");
    criacoes[0].resultado.vida = 50;
    criacoes[0].resultado.preco = 40;
    criacoes[0].resultado.tipo = 0;

    strcpy(criacoes[1].receita, "Espada Afiada: 1 Espada + 1 Pedra");
    strcpy(criacoes[1].materiais[0].nome, "Espada");
    criacoes[1].materiais[0].tipo = 1;
    strcpy(criacoes[1].materiais[1].nome, "Pedra");
    criacoes[1].materiais[1].tipo = 2;
    strcpy(criacoes[1].resultado.nome, "Espada Afiada");
    criacoes[1].resultado.forca = 15;
    criacoes[1].resultado.preco = 70;
    criacoes[1].resultado.tipo = 1;

    strcpy(criacoes[2].receita, "Arco Longo: 1 Arco + 1 Corda");
    strcpy(criacoes[2].materiais[0].nome, "Arco");
    criacoes[2].materiais[0].tipo = 1;
    strcpy(criacoes[2].materiais[1].nome, "Corda");
    criacoes[2].materiais[1].tipo = 2;
    strcpy(criacoes[2].resultado.nome, "Arco Longo");
    criacoes[2].resultado.forca = 12;
    criacoes[2].resultado.agilidade = 8;
    criacoes[2].resultado.preco = 60;
    criacoes[2].resultado.tipo = 1;

    strcpy(criacoes[3].receita, "Elixir Mana: 1 Pocao + 1 Cristal");
    strcpy(criacoes[3].materiais[0].nome, "Pocao");
    criacoes[3].materiais[0].tipo = 0;
    strcpy(criacoes[3].materiais[1].nome, "Cristal");
    criacoes[3].materiais[1].tipo = 2;
    strcpy(criacoes[3].resultado.nome, "Elixir Mana");
    criacoes[3].resultado.mana = 30;
    criacoes[3].resultado.preco = 45;
    criacoes[3].resultado.tipo = 0;

    strcpy(criacoes[4].receita, "Armadura Reforcada: 1 Armadura + 1 Metal");
    strcpy(criacoes[4].materiais[0].nome, "Armadura");
    criacoes[4].materiais[0].tipo = 1;
    strcpy(criacoes[4].materiais[1].nome, "Metal");
    criacoes[4].materiais[1].tipo = 2;
    strcpy(criacoes[4].resultado.nome, "Armadura Reforcada");
    criacoes[4].resultado.defesa = 15;
    criacoes[4].resultado.preco = 80;
    criacoes[4].resultado.tipo = 1;
}

void mostrar_status(Jogador *jogador, HANDLE console) {
    SetConsoleTextAttribute(console, COR_VERDE);
    printf("Explorador de Masmorras - %s (Nivel %d, Rank %c)\n", jogador->nome, jogador->nivel, jogador->rank);
    printf("Classe: %s | Faccao: %s\n",
           jogador->classe == GUERREIRO ? "Guerreiro" : jogador->classe == MAGO ? "Mago" : "Arqueiro",
           jogador->faccao == ORDEM ? "Ordem" : jogador->faccao == CAOS ? "Caos" : "Neutro");
    printf("Vida: %d/%d | Mana: %d/%d | Ouro: %d\n", jogador->vida, jogador->vida_max, jogador->mana, jogador->mana_max, jogador->ouro);
    printf("Andar: %d | XP: %d | Reliquia: %s\n", jogador->andar, jogador->xp, jogador->reliquia ? "Sim" : "Nao");
    if (jogador->veneno > 0) {
        SetConsoleTextAttribute(console, COR_ROXO);
        printf("Estado: Envenenado (%d turnos)\n", jogador->veneno);
    }
    if (jogador->bonus_dano > 0) {
        SetConsoleTextAttribute(console, COR_AMARELO);
        printf("Estado: Bonus de Dano (+%d)\n", jogador->bonus_dano);
    }
    SetConsoleTextAttribute(console, COR_BRANCO);
}

void atualizar_rank(Jogador *jogador) {
    int pontuacao = jogador->nivel * 10 + jogador->andar * 5;
    char rank_antigo = jogador->rank;
    if (pontuacao >= 100) jogador->rank = 'S';
    else if (pontuacao >= 70) jogador->rank = 'A';
    else if (pontuacao >= 40) jogador->rank = 'B';
    else if (pontuacao >= 20) jogador->rank = 'C';
    else jogador->rank = 'D';

    if (rank_antigo != jogador->rank) {
        char evento[100];
        snprintf(evento, 100, "Rank aumentado para %c", jogador->rank);
        adicionar_diario(jogador, evento);
    }
}

void mostrar_introducao(Jogador *jogador, HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Bem-vindo a Eryndor, %s!\n", jogador->nome);
    printf("A paz do reino foi destruida pelo Guardiao Sombrio, que corrompeu a Reliquia da Luz.\n");
    printf("Sua missao e explorar as Masmorras Eternas, derrotar o Guardiao e restaurar a reliquia.\n");
    printf("Escolha com sabedoria, pois suas decisoes moldarao seu caminho.\n");
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("\nPressione Enter para continuar...");
    limpar_buffer_entrada();
    pausar(1000);
}

void mostrar_menu_principal(Jogador *jogador, HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    mostrar_status(jogador, console);
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("1. Explorar\n2. Loja\n3. Inventario\n4. Missoes\n5. Talentos\n");
    printf("6. Criacao\n7. Diario\n8. Salvar\n9. Carregar\n10. Sair\n");
    printf("Escolha: ");
}

void mover(Jogador *jogador, Inimigo inimigos[], Criacao criacoes[], HANDLE console) {
    const char *locais[] = {"Floresta", "Caverna", "Ruinas", "Lago", "Templo"};
    const char *climas[] = {"Claro", "Chuva", "Nevoa"};
    int clima = rand() % 3;

    while (1) {
        limpar_tela();
        mostrar_borda(console);
        SetConsoleTextAttribute(console, COR_CIANO);
        printf("Local: %s (Andar %d) | Clima: %s\n", locais[jogador->posicao], jogador->andar, climas[clima]);
        mostrar_status(jogador, console);
        mostrar_borda(console);
        SetConsoleTextAttribute(console, COR_BRANCO);
        printf("1. Norte\n2. Sul\n3. Leste\n4. Oeste\n5. Subir andar\n6. Voltar\n");
        printf("Escolha: ");

        int direcao = ler_opcao();
        if (direcao == 6) break;
        if (direcao == 5) {
            jogador->andar++;
            jogador->posicao = 0;
            clima = rand() % 3;
            atualizar_rank(jogador);
            char evento[100];
            snprintf(evento, 100, "Subiu para o andar %d", jogador->andar);
            adicionar_diario(jogador, evento);
            SetConsoleTextAttribute(console, COR_AMARELO);
            printf("Voce subiu para o andar %d!\n", jogador->andar);
            SetConsoleTextAttribute(console, COR_BRANCO);
            pausar(1000);
            continue;
        }

        if (direcao >= 1 && direcao <= 4) {
            jogador->posicao = (direcao - 1) % 5;
            int evento = rand() % 6;
            limpar_tela();
            mostrar_borda(console);

            switch (evento) {
                case 0: {
                    encontrar_bau(jogador, console);
                    break;
                }
                case 1: {
                    encontrar_ouro(jogador, console);
                    break;
                }
                case 2: {
                    Inimigo inimigo = (jogador->andar % 5 == 0 && !jogador->reliquia) ? inimigos[5] : inimigos[rand() % 5];
                    inimigo.vida += jogador->andar * 10;
                    inimigo.dano += jogador->andar * 2;
                    if (!batalha(jogador, &inimigo, clima, console)) {
                        SetConsoleTextAttribute(console, COR_VERMELHO);
                        printf("Voce foi derrotado! Voltando ao andar 1...\n");
                        SetConsoleTextAttribute(console, COR_BRANCO);
                        jogador->andar = 1;
                        jogador->vida = jogador->vida_max;
                        jogador->mana = jogador->mana_max;
                        jogador->posicao = 0;
                        clima = rand() % 3;
                        atualizar_rank(jogador);
                        adicionar_diario(jogador, "Morreu e voltou ao andar 1");
                        pausar(2000);
                        return;
                    }
                    if (inimigo.chefe && inimigo.vida <= 0) {
                        jogador->reliquia = 1;
                        SetConsoleTextAttribute(console, COR_AMARELO);
                        printf("A Reliquia da Luz brilha em suas maos! Eryndor esta salvo.\n");
                        SetConsoleTextAttribute(console, COR_BRANCO);
                        adicionar_diario(jogador, "Restaurou a Reliquia da Luz");
                    }
                    verificar_missoes(jogador, console);
                    break;
                }
                case 3: {
                    resolver_puzzle(jogador, console);
                    break;
                }
                case 4: {
                    evento_narrativo(jogador, console);
                    break;
                }
                case 5: {
                    interagir_npc(jogador, console);
                    break;
                }
            }
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("\nPressione Enter...");
            limpar_buffer_entrada();
            pausar(500);
        } else {
            SetConsoleTextAttribute(console, COR_VERMELHO);
            printf("Direcao invalida!\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            pausar(1000);
        }
    }
}

void encontrar_bau(Jogador *jogador, HANDLE console) {
    SetConsoleTextAttribute(console, COR_AMARELO);
    printf("Voce encontrou um bau!\n");
    if (jogador->num_itens < MAX_ITENS) {
        Item item = {"Pocao", 30, 20, 0, 0, 0, 0, 0, 0};
        jogador->inventario[jogador->num_itens++] = item;
        printf("Pocao adicionada!\n");
        adicionar_diario(jogador, "Encontrou uma Pocao em um bau");
    } else {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Inventario cheio!\n");
    }
    SetConsoleTextAttribute(console, COR_BRANCO);
}

void encontrar_ouro(Jogador *jogador, HANDLE console) {
    int ouro = rand() % 30 + 10 + jogador->andar * 5;
    ouro = (jogador->faccao == NEUTRO) ? ouro * 1.2 : ouro;
    jogador->ouro += ouro;
    SetConsoleTextAttribute(console, COR_AMARELO);
    printf("Voce encontrou %d ouro!\n", ouro);
    SetConsoleTextAttribute(console, COR_BRANCO);
    char evento[100];
    snprintf(evento, 100, "Encontrou %d ouro", ouro);
    adicionar_diario(jogador, evento);
}

int batalha(Jogador *jogador, Inimigo *inimigo, int clima, HANDLE console) {
    int vida_inimigo = inimigo->vida;
    int mana_inimigo = inimigo->mana;
    int penalidade_clima = (clima == 2) ? 2 : 0;
    int ultimo_ataque = 0;
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_VERMELHO);
    printf("Inimigo: %s%s\n", inimigo->nome, inimigo->chefe ? " (Chefe)" : "");
    SetConsoleTextAttribute(console, COR_BRANCO);

    while (vida_inimigo > 0 && jogador->vida > 0) {
        mostrar_borda(console);
        printf("Vida: %d/%d | Mana: %d/%d\n", jogador->vida, jogador->vida_max, jogador->mana, jogador->mana_max);
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("%s: Vida: %d | Mana: %d\n", inimigo->nome, vida_inimigo, mana_inimigo);
        SetConsoleTextAttribute(console, COR_BRANCO);
        printf("1. Atacar\n2. Habilidade\n3. Item\n4. Fugir\n");
        printf("Escolha: ");

        int acao = ler_opcao();
        limpar_tela();
        mostrar_borda(console);

        int dano = 0;
        if (acao == 1) {
            dano = jogador->forca + (rand() % 10) - penalidade_clima + jogador->bonus_dano;
            if (jogador->faccao == CAOS) dano += 2;
            dano -= inimigo->defesa;
            if (dano < 0) dano = 0;
            vida_inimigo -= dano;
            SetConsoleTextAttribute(console, COR_VERDE);
            printf("Voce causou %d de dano!\n", dano);
            SetConsoleTextAttribute(console, COR_BRANCO);
            ultimo_ataque = 0;
        } else if (acao == 2) {
            dano = usar_habilidade(jogador, &ultimo_ataque, penalidade_clima, console);
            if (dano > 0) {
                vida_inimigo -= dano;
                SetConsoleTextAttribute(console, COR_VERDE);
                printf("Causou %d de dano!\n", dano);
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
        } else if (acao == 3) {
            ver_inventario(jogador, console);
            continue;
        } else if (acao == 4) {
            if (rand() % 100 < jogador->agilidade * 5) {
                SetConsoleTextAttribute(console, COR_VERDE);
                printf("Voce fugiu!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                adicionar_diario(jogador, "Fugiu da batalha");
                return 1;
            } else {
                SetConsoleTextAttribute(console, COR_VERMELHO);
                printf("Falhou ao fugir!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
        } else {
            SetConsoleTextAttribute(console, COR_VERMELHO);
            printf("Acao invalida!\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
        }

        if (vida_inimigo > 0) {
            int dano_inimigo = 0;
            if (inimigo->habilidade.dano != 0 && mana_inimigo >= inimigo->habilidade.custo_mana && rand() % 2 == 0) {
                mana_inimigo -= inimigo->habilidade.custo_mana;
                if (inimigo->habilidade.dano < 0) {
                    vida_inimigo -= inimigo->habilidade.dano;
                    if (vida_inimigo > inimigo->vida) vida_inimigo = inimigo->vida;
                    SetConsoleTextAttribute(console, COR_ROXO);
                    printf("%s usou %s e recuperou %d de vida!\n", inimigo->nome,
                           inimigo->habilidade.nome, -inimigo->habilidade.dano);
                    SetConsoleTextAttribute(console, COR_BRANCO);
                } else {
                    dano_inimigo = inimigo->habilidade.dano - (jogador->defesa / 2);
                    if (dano_inimigo < 0) dano_inimigo = 0;
                    jogador->vida -= dano_inimigo;
                    SetConsoleTextAttribute(console, COR_VERMELHO);
                    printf("%s usou %s e causou %d de dano!\n", inimigo->nome,
                           inimigo->habilidade.nome, dano_inimigo);
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    if (rand() % 3 == 0) jogador->veneno = 3;
                }
            } else {
                dano_inimigo = inimigo->dano - (jogador->defesa / 2) - penalidade_clima;
                if (dano_inimigo < 0) dano_inimigo = 0;
                jogador->vida -= dano_inimigo;
                SetConsoleTextAttribute(console, COR_VERMELHO);
                printf("%s causou %d de dano!\n", inimigo->nome, dano_inimigo);
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
        } else {
            SetConsoleTextAttribute(console, COR_VERDE);
            printf("Derrotou %s!\n", inimigo->nome);
            int xp = (rand() % 20 + 10) + jogador->andar * 5;
            int ouro = (rand() % 20 + 10) + jogador->andar * 5;
            if (inimigo->chefe) {
                xp *= 2;
                ouro *= 2;
            }
            ganhar_xp(jogador, xp, console);
            jogador->ouro += ouro;
            printf("Ganhou %d XP e %d ouro!\n", xp, ouro);
            SetConsoleTextAttribute(console, COR_BRANCO);
            char evento[100];
            snprintf(evento, 100, "Derrotou %s e ganhou %d ouro", inimigo->nome, ouro);
            adicionar_diario(jogador, evento);
            if (rand() % 3 == 0 && jogador->num_itens < MAX_ITENS) {
                Item material = {"Erva", 0, 10, 0, 0, 0, 0, 0, 2};
                jogador->inventario[jogador->num_itens++] = material;
                SetConsoleTextAttribute(console, COR_AMARELO);
                printf("Encontrou uma Erva!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
        }

        if (jogador->veneno > 0) {
            jogador->vida -= 5;
            SetConsoleTextAttribute(console, COR_ROXO);
            printf("Veneno causa 5 de dano!\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            jogador->veneno--;
        }
        if (jogador->bonus_dano > 0) jogador->bonus_dano--;

        if (jogador->vida <= 0) {
            return 0;
        }
        jogador->mana += 5;
        if (jogador->mana > jogador->mana_max) jogador->mana = jogador->mana_max;
        pausar(1000);
    }
    return 1;
}

int usar_habilidade(Jogador *jogador, int *ultimo_ataque, int penalidade_clima, HANDLE console) {
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Habilidades:\n");
    for (int i = 0; i < MAX_HABILIDADES && jogador->habilidades[i].dano > 0; i++) {
        printf("%d. %s (%d mana) - %s\n", i + 1, jogador->habilidades[i].nome,
               jogador->habilidades[i].custo_mana, jogador->habilidades[i].descricao);
    }
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("Escolha (0 para voltar): ");
    int idx_habilidade = ler_opcao();

    if (idx_habilidade >= 1 && idx_habilidade <= MAX_HABILIDADES && jogador->habilidades[idx_habilidade - 1].dano > 0) {
        idx_habilidade--;
        if (jogador->mana >= jogador->habilidades[idx_habilidade].custo_mana) {
            jogador->mana -= jogador->habilidades[idx_habilidade].custo_mana;
            int dano = jogador->habilidades[idx_habilidade].dano + (jogador->inteligencia / 2) - penalidade_clima;
            if (*ultimo_ataque == 1 && jogador->habilidades[idx_habilidade].combo) {
                dano *= 1.5;
                SetConsoleTextAttribute(console, COR_AMARELO);
                printf("Combo! Dano aumentado!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
            *ultimo_ataque = jogador->habilidades[idx_habilidade].combo;
            printf("Voce usou %s! ", jogador->habilidades[idx_habilidade].nome);
            return dano;
        } else {
            SetConsoleTextAttribute(console, COR_VERMELHO);
            printf("Mana insuficiente!\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
        }
    }
    return 0;
}

void ver_inventario(Jogador *jogador, HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Inventario:\n");
    mostrar_borda(console);
    if (jogador->num_itens == 0) {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Vazio\n");
    } else {
        SetConsoleTextAttribute(console, COR_BRANCO);
        for (int i = 0; i < jogador->num_itens; i++) {
            printf("%d. %s (Vida: %d, Forca: %d, Defesa: %d, Agilidade: %d, Inteligencia: %d) [%s]\n",
                   i + 1, jogador->inventario[i].nome, jogador->inventario[i].vida,
                   jogador->inventario[i].forca, jogador->inventario[i].defesa,
                   jogador->inventario[i].agilidade, jogador->inventario[i].inteligencia,
                   jogador->inventario[i].equipado ? "Equipado" : "Nao equipado");
        }
        printf("\n1. Usar\n2. Equipar/Desequipar\n3. Voltar\nEscolha: ");
        int escolha = ler_opcao();
        if (escolha == 1 || escolha == 2) {
            printf("Item (1-%d): ", jogador->num_itens);
            int indice = ler_opcao();
            if (indice >= 1 && indice <= jogador->num_itens) {
                if (escolha == 1) usar_item(jogador, indice - 1, console);
                else equipar_item(jogador, indice - 1, console);
            }
        }
    }
    printf("\nVida: %d/%d | Mana: %d/%d\n", jogador->vida, jogador->vida_max, jogador->mana, jogador->mana_max);
    SetConsoleTextAttribute(console, COR_BRANCO);
    pausar(1000);
}

void usar_item(Jogador *jogador, int indice, HANDLE console) {
    Item *item = &jogador->inventario[indice];
    if (item->tipo != 0) {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Item deve ser equipado!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
        return;
    }
    if (item->vida > 0) {
        jogador->vida += item->vida;
        if (jogador->vida > jogador->vida_max) jogador->vida = jogador->vida_max;
        SetConsoleTextAttribute(console, COR_VERDE);
        printf("Usou %s! Vida: %d\n", item->nome, jogador->vida);
        SetConsoleTextAttribute(console, COR_BRANCO);
        adicionar_diario(jogador, "Usou uma Pocao");
    } else if (item->mana > 0) {
        jogador->mana += item->mana;
        if (jogador->mana > jogador->mana_max) jogador->mana = jogador->mana_max;
        SetConsoleTextAttribute(console, COR_VERDE);
        printf("Usou %s! Mana: %d\n", item->nome, jogador->mana);
        SetConsoleTextAttribute(console, COR_BRANCO);
        adicionar_diario(jogador, "Usou um Elixir Mana");
    }
    for (int i = indice; i < jogador->num_itens - 1; i++) {
        jogador->inventario[i] = jogador->inventario[i + 1];
    }
    jogador->num_itens--;
}

void equipar_item(Jogador *jogador, int indice, HANDLE console) {
    Item *item = &jogador->inventario[indice];
    if (item->tipo != 1) {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Item nao equipavel!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
        return;
    }
    if (item->equipado) {
        item->equipado = 0;
        jogador->forca -= item->forca;
        jogador->defesa -= item->defesa;
        jogador->agilidade -= item->agilidade;
        jogador->inteligencia -= item->inteligencia;
        SetConsoleTextAttribute(console, COR_CIANO);
        printf("%s desequipado!\n", item->nome);
        SetConsoleTextAttribute(console, COR_BRANCO);
    } else {
        for (int i = 0; i < jogador->num_itens; i++) {
            if (jogador->inventario[i].equipado && jogador->inventario[i].tipo == 1) {
                jogador->inventario[i].equipado = 0;
                jogador->forca -= jogador->inventario[i].forca;
                jogador->defesa -= jogador->inventario[i].defesa;
                jogador->agilidade -= jogador->inventario[i].agilidade;
                jogador->inteligencia -= jogador->inventario[i].inteligencia;
            }
        }
        item->equipado = 1;
        jogador->forca += item->forca;
        jogador->defesa += item->defesa;
        jogador->agilidade += item->agilidade;
        jogador->inteligencia += item->inteligencia;
        SetConsoleTextAttribute(console, COR_CIANO);
        printf("%s equipado!\n", item->nome);
        SetConsoleTextAttribute(console, COR_BRANCO);
        char evento[100];
        snprintf(evento, 100, "Equipou %s", item->nome);
        adicionar_diario(jogador, evento);
    }
}

void resolver_puzzle(Jogador *jogador, HANDLE console) {
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Runa na parede: (6 * 4) - 8 = ?\n");
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("Resposta: ");
    int resposta = ler_opcao();

    if (resposta == 16) {
        SetConsoleTextAttribute(console, COR_VERDE);
        printf("Correto! Tesouro liberado.\n");
        if (jogador->num_itens < MAX_ITENS) {
            Item item = {"Pedra Magica", 0, 50, 0, 0, 0, 0, 0, 2};
            jogador->inventario[jogador->num_itens++] = item;
            printf("Pedra Magica adicionada!\n");
            adicionar_diario(jogador, "Resolveu um puzzle e ganhou uma Pedra Magica");
        }
        ganhar_xp(jogador, 10, console);
    } else {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Errado! Armadilha causa 10 de dano!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
        jogador->vida -= 10;
        adicionar_diario(jogador, "Falhou em um puzzle e levou dano");
        if (jogador->vida <= 0) {
            SetConsoleTextAttribute(console, COR_VERMELHO);
            printf("Voce foi derrotado! Voltando ao andar 1...\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            jogador->andar = 1;
            jogador->vida = jogador->vida_max;
            jogador->mana = jogador->mana_max;
            jogador->posicao = 0;
            atualizar_rank(jogador);
            adicionar_diario(jogador, "Morreu em uma armadilha e voltou ao andar 1");
            pausar(2000);
        }
    }
}

void evento_narrativo(Jogador *jogador, HANDLE console) {
    int evento = rand() % 6;
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Evento: ");
    switch (evento) {
        case 0: {
            printf("Visao da Reliquia da Luz\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("1. Meditar\n2. Ignorar\nEscolha: ");
            int escolha = ler_opcao();
            if (escolha == 1) {
                jogador->mana = jogador->mana_max;
                SetConsoleTextAttribute(console, COR_VERDE);
                printf("Mana restaurada!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                adicionar_diario(jogador, "Meditou em uma visao da Reliquia da Luz");
            } else {
                printf("Ignorou a visao\n");
            }
            break;
        }
        case 1: {
            printf("Fonte magica\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("1. Beber\n2. Ignorar\nEscolha: ");
            int escolha = ler_opcao();
            if (escolha == 1) {
                if (rand() % 2 == 0) {
                    jogador->vida = jogador->vida_max;
                    SetConsoleTextAttribute(console, COR_VERDE);
                    printf("Vida restaurada!\n");
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    adicionar_diario(jogador, "Bebeu de uma fonte magica e recuperou vida");
                } else {
                    jogador->vida -= 20;
                    SetConsoleTextAttribute(console, COR_VERMELHO);
                    printf("Fonte envenenada! Perde 20 de vida\n");
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    adicionar_diario(jogador, "Bebeu de uma fonte envenenada");
                    if (jogador->vida <= 0) {
                        SetConsoleTextAttribute(console, COR_VERMELHO);
                        printf("Voce foi derrotado! Voltando ao andar 1...\n");
                        SetConsoleTextAttribute(console, COR_BRANCO);
                        jogador->andar = 1;
                        jogador->vida = jogador->vida_max;
                        jogador->mana = jogador->mana_max;
                        jogador->posicao = 0;
                        atualizar_rank(jogador);
                        adicionar_diario(jogador, "Morreu por uma fonte envenenada e voltou ao andar 1");
                        pausar(2000);
                    }
                }
            } else {
                printf("Ignorou a fonte\n");
            }
            break;
        }
        case 2: {
            printf("Armadilha de dardos\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("1. Desviar (Agilidade)\n2. Resistir (Defesa)\nEscolha: ");
            int escolha = ler_opcao();
            if (escolha == 1) {
                if (rand() % 20 < jogador->agilidade) {
                    SetConsoleTextAttribute(console, COR_VERDE);
                    printf("Desviou!\n");
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    ganhar_xp(jogador, 15, console);
                } else {
                    jogador->vida -= 15;
                    SetConsoleTextAttribute(console, COR_VERMELHO);
                    printf("Atingido! Perde 15 de vida\n");
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    if (jogador->vida <= 0) {
                        SetConsoleTextAttribute(console, COR_VERMELHO);
                        printf("Voce foi derrotado! Voltando ao andar 1...\n");
                        SetConsoleTextAttribute(console, COR_BRANCO);
                        jogador->andar = 1;
                        jogador->vida = jogador->vida_max;
                        jogador->mana = jogador->mana_max;
                        jogador->posicao = 0;
                        atualizar_rank(jogador);
                        adicionar_diario(jogador, "Morreu em uma armadilha de dardos e voltou ao andar 1");
                        pausar(2000);
                    }
                }
            } else {
                if (rand() % 20 < jogador->defesa) {
                    SetConsoleTextAttribute(console, COR_VERDE);
                    printf("Resistiu!\n");
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    ganhar_xp(jogador, 15, console);
                } else {
                    jogador->vida -= 15;
                    SetConsoleTextAttribute(console, COR_VERMELHO);
                    printf("Atingido! Perde 15 de vida\n");
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    if (jogador->vida <= 0) {
                        SetConsoleTextAttribute(console, COR_VERMELHO);
                        printf("Voce foi derrotado! Voltando ao andar 1...\n");
                        SetConsoleTextAttribute(console, COR_BRANCO);
                        jogador->andar = 1;
                        jogador->vida = jogador->vida_max;
                        jogador->mana = jogador->mana_max;
                        jogador->posicao = 0;
                        atualizar_rank(jogador);
                        adicionar_diario(jogador, "Morreu em uma armadilha de dardos e voltou ao andar 1");
                        pausar(2000);
                    }
                }
            }
            adicionar_diario(jogador, "Enfrentou uma armadilha de dardos");
            break;
        }
        case 3: {
            printf("Altar antigo\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("1. Oferecer 50 ouro\n2. Ignorar\nEscolha: ");
            int escolha = ler_opcao();
            if (escolha == 1 && jogador->ouro >= 50) {
                jogador->ouro -= 50;
                jogador->bonus_dano += 5;
                SetConsoleTextAttribute(console, COR_AMARELO);
                printf("Altar brilha! Bonus de dano por 5 turnos\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                adicionar_diario(jogador, "Ofereceu ouro a um altar e ganhou bonus de dano");
            } else {
                printf("Ignorou o altar\n");
            }
            break;
        }
        case 4: {
            printf("Eco de um heroi antigo\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("1. Ouvir\n2. Ignorar\nEscolha: ");
            int escolha = ler_opcao();
            if (escolha == 1) {
                ganhar_xp(jogador, 20, console);
                SetConsoleTextAttribute(console, COR_CIANO);
                printf("O eco conta sobre a luta contra o Guardiao Sombrio. Voce ganha experiencia!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                adicionar_diario(jogador, "Ouviu um eco de um heroi antigo");
            } else {
                printf("Ignorou o eco\n");
            }
            break;
        }
        case 5: {
            printf("Inscricoes antigas\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("1. Decifrar\n2. Ignorar\nEscolha: ");
            int escolha = ler_opcao();
            if (escolha == 1 && jogador->inteligencia >= 10) {
                SetConsoleTextAttribute(console, COR_VERDE);
                printf("Decifrou! Ganhou conhecimento\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                ganhar_xp(jogador, 15, console);
                adicionar_diario(jogador, "Decifrou inscricoes antigas");
            } else {
                SetConsoleTextAttribute(console, COR_VERMELHO);
                printf("Nao conseguiu decifrar\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
            break;
        }
    }
}

void interagir_npc(Jogador *jogador, HANDLE console) {
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Velho sabio:\n");
    SetConsoleTextAttribute(console, COR_BRANCO);
    printf("1. Missao\n2. Reliquia\n3. Trocar\n4. Sair\nEscolha: ");
    int escolha = ler_opcao();

    switch (escolha) {
        case 1: {
            aceitar_missao(jogador, console);
            break;
        }
        case 2: {
            SetConsoleTextAttribute(console, COR_CIANO);
            printf(jogador->reliquia ? "Sabio: Voce restaurou a Reliquia da Luz! Eryndor agradece\n" :
                   "Sabio: A Reliquia da Luz esta guardada pelo Guardiao Sombrio nos andares profundos\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            adicionar_diario(jogador, "Falou com um sabio sobre a Reliquia da Luz");
            break;
        }
        case 3: {
            SetConsoleTextAttribute(console, COR_CIANO);
            printf("Sabio: Erva por 30 ouro?\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
            printf("1. Aceitar\n2. Recusar\nEscolha: ");
            int troca = ler_opcao();
            if (troca == 1 && jogador->ouro >= 30 && jogador->num_itens < MAX_ITENS) {
                jogador->ouro -= 30;
                Item item = {"Erva", 0, 10, 0, 0, 0, 0, 0, 2};
                jogador->inventario[jogador->num_itens++] = item;
                SetConsoleTextAttribute(console, COR_VERDE);
                printf("Erva adicionada!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                adicionar_diario(jogador, "Trocou ouro por uma Erva com um sabio");
            } else {
                SetConsoleTextAttribute(console, COR_VERMELHO);
                printf("Troca recusada\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
            break;
        }
        case 4: {
            printf("Despediu-se do sabio\n");
            break;
        }
    }
}

void loja(Jogador *jogador, HANDLE console) {
    Item itens_loja[] = {
        {"Pocao", 30, 20, 0, 0, 0, 0, 0, 0},
        {"Espada", 0, 50, 10, 0, 0, 0, 0, 1},
        {"Armadura", 0, 50, 0, 10, 0, 0, 0, 1},
        {"Arco", 0, 40, 5, 0, 5, 0, 0, 1},
        {"Botas", 0, 40, 0, 0, 8, 0, 0, 1}
    };
    int num_itens_loja = 5;

    while (1) {
        limpar_tela();
        mostrar_borda(console);
        SetConsoleTextAttribute(console, COR_CIANO);
        printf("Loja - Ouro: %d\n", jogador->ouro);
        mostrar_borda(console);
        SetConsoleTextAttribute(console, COR_BRANCO);
        for (int i = 0; i < num_itens_loja; i++) {
            printf("%d. %s (Preco: %d, Vida: %d, Forca: %d, Defesa: %d, Agilidade: %d, Inteligencia: %d)\n",
                   i + 1, itens_loja[i].nome, itens_loja[i].preco, itens_loja[i].vida,
                   itens_loja[i].forca, itens_loja[i].defesa, itens_loja[i].agilidade, itens_loja[i].inteligencia);
        }
        printf("\n1. Comprar\n2. Vender\n3. Voltar\nEscolha: ");

        int opcao = ler_opcao();
        if (opcao == 1) {
            printf("Item (1-%d): ", num_itens_loja);
            int item = ler_opcao();
            if (item >= 1 && item <= num_itens_loja) {
                item--;
                if (jogador->ouro >= itens_loja[item].preco && jogador->num_itens < MAX_ITENS) {
                    jogador->ouro -= itens_loja[item].preco;
                    jogador->inventario[jogador->num_itens++] = itens_loja[item];
                    SetConsoleTextAttribute(console, COR_VERDE);
                    printf("Comprou %s!\n", itens_loja[item].nome);
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    char evento[100];
                    snprintf(evento, 100, "Comprou %s na loja", itens_loja[item].nome);
                    adicionar_diario(jogador, evento);
                } else {
                    SetConsoleTextAttribute(console, COR_VERMELHO);
                    printf("Ouro ou espaco insuficiente!\n");
                    SetConsoleTextAttribute(console, COR_BRANCO);
                }
            }
        } else if (opcao == 2) {
            if (jogador->num_itens > 0) {
                printf("Itens:\n");
                for (int i = 0; i < jogador->num_itens; i++) {
                    printf("%d. %s\n", i + 1, jogador->inventario[i].nome);
                }
                printf("Vender (1-%d): ", jogador->num_itens);
                int item = ler_opcao();
                if (item >= 1 && item <= jogador->num_itens) {
                    item--;
                    jogador->ouro += jogador->inventario[item].preco / 2;
                    SetConsoleTextAttribute(console, COR_VERDE);
                    printf("Vendeu %s por %d ouro!\n", jogador->inventario[item].nome, jogador->inventario[item].preco / 2);
                    SetConsoleTextAttribute(console, COR_BRANCO);
                    for (int i = item; i < jogador->num_itens - 1; i++) {
                        jogador->inventario[i] = jogador->inventario[i + 1];
                    }
                    jogador->num_itens--;
                    adicionar_diario(jogador, "Vendeu um item na loja");
                }
            } else {
                SetConsoleTextAttribute(console, COR_VERMELHO);
                printf("Inventario vazio!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
            }
        } else if (opcao == 3) {
            break;
        }
        pausar(1000);
    }
}

void criar_item(Jogador *jogador, Criacao criacoes[], HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Criacao:\n");
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_BRANCO);
    for (int i = 0; i < MAX_CRIACOES; i++) {
        printf("%d. %s\n", i + 1, criacoes[i].receita);
    }
    printf("\nEscolha (0 para voltar): ");
    int escolha = ler_opcao();

    if (escolha >= 1 && escolha <= MAX_CRIACOES) {
        escolha--;
        int tem_materiais[2] = {0, 0};
        int indices_materiais[2] = {-1, -1};

        for (int i = 0; i < jogador->num_itens; i++) {
            if (strcmp(jogador->inventario[i].nome, criacoes[escolha].materiais[0].nome) == 0 &&
                jogador->inventario[i].tipo == criacoes[escolha].materiais[0].tipo) {
                tem_materiais[0]++;
                indices_materiais[0] = i;
            }
            if (strcmp(jogador->inventario[i].nome, criacoes[escolha].materiais[1].nome) == 0 &&
                jogador->inventario[i].tipo == criacoes[escolha].materiais[1].tipo) {
                tem_materiais[1]++;
                indices_materiais[1] = i;
            }
        }

        if (tem_materiais[0] >= 1 && tem_materiais[1] >= 1 && jogador->num_itens < MAX_ITENS) {
            for (int i = indices_materiais[0]; i < jogador->num_itens - 1; i++) {
                jogador->inventario[i] = jogador->inventario[i + 1];
            }
            jogador->num_itens--;
            for (int i = indices_materiais[1] - (indices_materiais[1] > indices_materiais[0]); i < jogador->num_itens - 1; i++) {
                jogador->inventario[i] = jogador->inventario[i + 1];
            }
            jogador->num_itens--;
            jogador->inventario[jogador->num_itens++] = criacoes[escolha].resultado;
            SetConsoleTextAttribute(console, COR_VERDE);
            printf("Criou %s!\n", criacoes[escolha].resultado.nome);
            SetConsoleTextAttribute(console, COR_BRANCO);
            char evento[100];
            snprintf(evento, 100, "Criou %s", criacoes[escolha].resultado.nome);
            adicionar_diario(jogador, evento);
        } else {
            SetConsoleTextAttribute(console, COR_VERMELHO);
            printf("Materiais insuficientes ou inventario cheio!\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
        }
    }
    pausar(1000);
}

void gerenciar_missoes(Jogador *jogador, HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Missoes:\n");
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_BRANCO);
    if (jogador->num_missoes == 0) {
        printf("Nenhuma missao ativa\n");
    } else {
        for (int i = 0; i < jogador->num_missoes; i++) {
            printf("%d. %s (Progresso: %d/%d)\n", i + 1, jogador->missoes[i].descricao,
                   jogador->missoes[i].progresso, jogador->missoes[i].objetivo);
        }
    }
    printf("\n1. Aceitar nova missao\n2. Voltar\nEscolha: ");
    int escolha = ler_opcao();
    if (escolha == 1) {
        aceitar_missao(jogador, console);
    }
    pausar(1000);
}

void aceitar_missao(Jogador *jogador, HANDLE console) {
    if (jogador->num_missoes < MAX_MISSOES) {
        Missao nova_missao;
        snprintf(nova_missao.descricao, 100, "Derrote %d inimigos no andar %d", 3 + jogador->andar, jogador->andar);
        nova_missao.recompensa_ouro = 30 + jogador->andar * 10;
        nova_missao.recompensa_xp = 20 + jogador->andar * 5;
        nova_missao.objetivo = 3 + jogador->andar;
        nova_missao.progresso = 0;
        nova_missao.ativa = 1;
        jogador->missoes[jogador->num_missoes++] = nova_missao;
        SetConsoleTextAttribute(console, COR_VERDE);
        printf("Missao aceita: %s\n", nova_missao.descricao);
        SetConsoleTextAttribute(console, COR_BRANCO);
        adicionar_diario(jogador, "Aceitou uma nova missao");
    } else {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Limite de missoes atingido!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
    }
}

void verificar_missoes(Jogador *jogador, HANDLE console) {
    for (int i = 0; i < jogador->num_missoes; i++) {
        if (jogador->missoes[i].ativa) {
            jogador->missoes[i].progresso++;
            if (jogador->missoes[i].progresso >= jogador->missoes[i].objetivo) {
                jogador->ouro += jogador->missoes[i].recompensa_ouro;
                ganhar_xp(jogador, jogador->missoes[i].recompensa_xp, console);
                SetConsoleTextAttribute(console, COR_VERDE);
                printf("Missao completa: %s! Ganhou %d ouro e %d XP\n",
                       jogador->missoes[i].descricao, jogador->missoes[i].recompensa_ouro, jogador->missoes[i].recompensa_xp);
                SetConsoleTextAttribute(console, COR_BRANCO);
                char evento[100];
                snprintf(evento, 100, "Completou missao: %s", jogador->missoes[i].descricao);
                adicionar_diario(jogador, evento);
                for (int j = i; j < jogador->num_missoes - 1; j++) {
                    jogador->missoes[j] = jogador->missoes[j + 1];
                }
                jogador->num_missoes--;
                i--;
            }
        }
    }
}

void gerenciar_talentos(Jogador *jogador, HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Talentos:\n");
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_BRANCO);
    for (int i = 0; i < MAX_TALENTOS && jogador->talentos[i].nivel_requerido > 0; i++) {
        printf("%d. %s (Nivel %d) - %s [%s]\n", i + 1, jogador->talentos[i].nome,
               jogador->talentos[i].nivel_requerido, jogador->talentos[i].descricao,
               jogador->talentos[i].ativo ? "Ativo" : "Inativo");
    }
    printf("\nEscolha (0 para voltar): ");
    int escolha = ler_opcao();

    if (escolha >= 1 && escolha <= MAX_TALENTOS && jogador->talentos[escolha - 1].nivel_requerido > 0) {
        escolha--;
        if (jogador->nivel >= jogador->talentos[escolha].nivel_requerido) {
            jogador->talentos[escolha].ativo = !jogador->talentos[escolha].ativo;
            if (jogador->talentos[escolha].ativo) {
                jogador->forca += jogador->talentos[escolha].bonus_forca;
                jogador->defesa += jogador->talentos[escolha].bonus_defesa;
                jogador->agilidade += jogador->talentos[escolha].bonus_agilidade;
                jogador->inteligencia += jogador->talentos[escolha].bonus_inteligencia;
                SetConsoleTextAttribute(console, COR_VERDE);
                printf("Talento %s ativado!\n", jogador->talentos[escolha].nome);
                SetConsoleTextAttribute(console, COR_BRANCO);
                char evento[100];
                snprintf(evento, 100, "Ativou talento %s", jogador->talentos[escolha].nome);
                adicionar_diario(jogador, evento);
            } else {
                jogador->forca -= jogador->talentos[escolha].bonus_forca;
                jogador->defesa -= jogador->talentos[escolha].bonus_defesa;
                jogador->agilidade -= jogador->talentos[escolha].bonus_agilidade;
                jogador->inteligencia -= jogador->talentos[escolha].bonus_inteligencia;
                SetConsoleTextAttribute(console, COR_CIANO);
                printf("Talento %s desativado!\n", jogador->talentos[escolha].nome);
                SetConsoleTextAttribute(console, COR_BRANCO);
                char evento[100];
                snprintf(evento, 100, "Desativou talento %s", jogador->talentos[escolha].nome);
                adicionar_diario(jogador, evento);
            }
        } else {
            SetConsoleTextAttribute(console, COR_VERMELHO);
            printf("Nivel insuficiente!\n");
            SetConsoleTextAttribute(console, COR_BRANCO);
        }
    }
    pausar(1000);
}

void ver_diario(Jogador *jogador, HANDLE console) {
    limpar_tela();
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_CIANO);
    printf("Diario:\n");
    mostrar_borda(console);
    SetConsoleTextAttribute(console, COR_BRANCO);
    if (jogador->num_diario == 0) {
        printf("Nenhum registro\n");
    } else {
        for (int i = 0; i < jogador->num_diario; i++) {
            printf("- %s\n", jogador->diario[i]);
        }
    }
    printf("\nPressione Enter para voltar...");
    limpar_buffer_entrada();
    pausar(1000);
}

void salvar_jogo(Jogador *jogador, HANDLE console) {
    FILE *arquivo = fopen("save.dat", "wb");
    if (arquivo) {
        fwrite(jogador, sizeof(Jogador), 1, arquivo);
        fclose(arquivo);
        SetConsoleTextAttribute(console, COR_VERDE);
        printf("Jogo salvo!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
        adicionar_diario(jogador, "Salvou o jogo");
    } else {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Erro ao salvar!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
    }
    pausar(1000);
}

void carregar_jogo(Jogador *jogador, HANDLE console) {
    FILE *arquivo = fopen("save.dat", "rb");
    if (arquivo) {
        fread(jogador, sizeof(Jogador), 1, arquivo);
        fclose(arquivo);
        SetConsoleTextAttribute(console, COR_VERDE);
        printf("Jogo carregado!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
        adicionar_diario(jogador, "Carregou o jogo");
    } else {
        SetConsoleTextAttribute(console, COR_VERMELHO);
        printf("Erro ao carregar!\n");
        SetConsoleTextAttribute(console, COR_BRANCO);
    }
    pausar(1000);
}

void ganhar_xp(Jogador *jogador, int xp, HANDLE console) {
    jogador->xp += xp;
    SetConsoleTextAttribute(console, COR_AMARELO);
    printf("Ganhou %d XP!\n", xp);
    SetConsoleTextAttribute(console, COR_BRANCO);
    while (jogador->xp >= jogador->nivel * 50) {
        jogador->xp -= jogador->nivel * 50;
        subir_nivel(jogador, console);
    }
    atualizar_rank(jogador);
}

void subir_nivel(Jogador *jogador, HANDLE console) {
    jogador->nivel++;
    jogador->vida_max += 10;
    jogador->mana_max += 5;
    jogador->vida = jogador->vida_max;
    jogador->mana = jogador->mana_max;
    jogador->forca += 2;
    jogador->defesa += 2;
    jogador->agilidade += 2;
    jogador->inteligencia += 2;
    SetConsoleTextAttribute(console, COR_AMARELO);
    printf("Subiu para o nivel %d!\n", jogador->nivel);
    printf("Vida maxima: %d | Mana maxima: %d\n", jogador->vida_max, jogador->mana_max);
    printf("Forca: %d | Defesa: %d | Agilidade: %d | Inteligencia: %d\n",
           jogador->forca, jogador->defesa, jogador->agilidade, jogador->inteligencia);
    SetConsoleTextAttribute(console, COR_BRANCO);
    char evento[100];
    snprintf(evento, 100, "Subiu para o nivel %d", jogador->nivel);
    adicionar_diario(jogador, evento);

    // Adiciona novos talentos em niveis especificos
    if (jogador->nivel == 3 && jogador->num_talentos < MAX_TALENTOS) {
        Talento novo_talento;
        if (jogador->classe == GUERREIRO) {
            strcpy(novo_talento.nome, "Resistencia");
            novo_talento.bonus_defesa = 5;
            novo_talento.nivel_requerido = 3;
            strcpy(novo_talento.descricao, "Aumenta defesa");
        } else if (jogador->classe == MAGO) {
            strcpy(novo_talento.nome, "Concentracao");
            novo_talento.bonus_inteligencia = 5;
            novo_talento.nivel_requerido = 3;
            strcpy(novo_talento.descricao, "Aumenta inteligencia");
        } else {
            strcpy(novo_talento.nome, "Precisao");
            novo_talento.bonus_agilidade = 5;
            novo_talento.nivel_requerido = 3;
            strcpy(novo_talento.descricao, "Aumenta agilidade");
        }
        novo_talento.ativo = 0;
        jogador->talentos[jogador->num_talentos++] = novo_talento;
        SetConsoleTextAttribute(console, COR_CIANO);
        printf("Novo talento desbloqueado: %s!\n", novo_talento.nome);
        SetConsoleTextAttribute(console, COR_BRANCO);
        snprintf(evento, 100, "Desbloqueou talento %s", novo_talento.nome);
        adicionar_diario(jogador, evento);
    }

    // Adiciona novas habilidades em niveis especificos
    if (jogador->nivel == 5) {
        Habilidade nova_habilidade;
        if (jogador->classe == GUERREIRO) {
            strcpy(nova_habilidade.nome, "Investida");
            nova_habilidade.dano = 30;
            nova_habilidade.custo_mana = 15;
            nova_habilidade.combo = 1;
            strcpy(nova_habilidade.descricao, "Causa dano massivo");
        } else if (jogador->classe == MAGO) {
            strcpy(nova_habilidade.nome, "Raio Arcano");
            nova_habilidade.dano = 35;
            nova_habilidade.custo_mana = 20;
            nova_habilidade.combo = 1;
            strcpy(nova_habilidade.descricao, "Raio eletrico");
        } else {
            strcpy(nova_habilidade.nome, "Flecha Dupla");
            nova_habilidade.dano = 25;
            nova_habilidade.custo_mana = 15;
            nova_habilidade.combo = 1;
            strcpy(nova_habilidade.descricao, "Atira duas flechas");
        }
        for (int i = 0; i < MAX_HABILIDADES; i++) {
            if (jogador->habilidades[i].dano == 0) {
                jogador->habilidades[i] = nova_habilidade;
                break;
            }
        }
        SetConsoleTextAttribute(console, COR_CIANO);
        printf("Nova habilidade desbloqueada: %s!\n", nova_habilidade.nome);
        SetConsoleTextAttribute(console, COR_BRANCO);
        snprintf(evento, 100, "Desbloqueou habilidade %s", nova_habilidade.nome);
        adicionar_diario(jogador, evento);
    }

    atualizar_rank(jogador);
    pausar(2000);
}

int main() {
    srand(time(NULL));
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    Jogador jogador;
    Inimigo inimigos[MAX_INIMIGOS];
    Criacao criacoes[MAX_CRIACOES];

    inicializar_inimigos(inimigos);
    inicializar_criacoes(criacoes);
    inicializar_jogador(&jogador, console);

    while (1) {
        mostrar_menu_principal(&jogador, console);
        int opcao = ler_opcao();

        switch (opcao) {
            case 1: {
                mover(&jogador, inimigos, criacoes, console);
                break;
            }
            case 2: {
                loja(&jogador, console);
                break;
            }
            case 3: {
                ver_inventario(&jogador, console);
                break;
            }
            case 4: {
                gerenciar_missoes(&jogador, console);
                break;
            }
            case 5: {
                gerenciar_talentos(&jogador, console);
                break;
            }
            case 6: {
                criar_item(&jogador, criacoes, console);
                break;
            }
            case 7: {
                ver_diario(&jogador, console);
                break;
            }
            case 8: {
                salvar_jogo(&jogador, console);
                break;
            }
            case 9: {
                carregar_jogo(&jogador, console);
                break;
            }
            case 10: {
                limpar_tela();
                mostrar_borda(console);
                SetConsoleTextAttribute(console, COR_AMARELO);
                printf("Obrigado por jogar Explorador de Masmorras!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                pausar(2000);
                return 0;
            }
            default: {
                SetConsoleTextAttribute(console, COR_VERMELHO);
                printf("Opcao invalida!\n");
                SetConsoleTextAttribute(console, COR_BRANCO);
                pausar(1000);
                break;
            }
        }
    }
    return 0;
}