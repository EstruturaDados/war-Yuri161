#include <stdio.h>
#include <string.h>

#define QTDE_TERRITORIOS 5

// Estrutura do território
struct Territorio {
    char nome[50];
    char corExercito[30];
    int numeroTropas;
};

// Função auxiliar para remover o '\n' das strings
void removerNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Função para ler uma string não vazia
void lerStringValida(char *mensagem, char *entrada, int tamanho) {
    do {
        printf("%s", mensagem);
        fgets(entrada, tamanho, stdin);
        removerNovaLinha(entrada);

        if (strlen(entrada) == 0) {
            printf("⚠️  Campo obrigatório! Digite novamente.\n");
        }
    } while (strlen(entrada) == 0);
}

// Função para cadastrar territórios
void cadastrarTerritorios(struct Territorio territorios[]) {
    for (int i = 0; i < QTDE_TERRITORIOS; i++) {
        printf("\n=== Cadastro do Território %d ===\n", i + 1);

        lerStringValida("Nome do território: ", territorios[i].nome, sizeof(territorios[i].nome));
        lerStringValida("Cor do exército: ", territorios[i].corExercito, sizeof(territorios[i].corExercito));

        do {
            printf("Número de tropas: ");
            if (scanf("%d", &territorios[i].numeroTropas) != 1) {
                printf("⚠️  Valor inválido! Digite um número inteiro.\n");
                while (getchar() != '\n'); // limpa buffer
                continue;
            }

            if (territorios[i].numeroTropas < 0) {
                printf("⚠️  O número de tropas não pode ser negativo.\n");
            }

            while (getchar() != '\n'); // limpa buffer

        } while (territorios[i].numeroTropas < 0);
    }
}

// Função para preencher dados de exemplo
void preencherExemplo(struct Territorio territorios[]) {
    strcpy(territorios[0].nome, "Brasil");
    strcpy(territorios[0].corExercito, "Verde");
    territorios[0].numeroTropas = 12;

    strcpy(territorios[1].nome, "Canada");
    strcpy(territorios[1].corExercito, "Azul");
    territorios[1].numeroTropas = 9;

    strcpy(territorios[2].nome, "Chile");
    strcpy(territorios[2].corExercito, "Vermelho");
    territorios[2].numeroTropas = 7;

    strcpy(territorios[3].nome, "Peru");
    strcpy(territorios[3].corExercito, "Amarelo");
    territorios[3].numeroTropas = 5;

    strcpy(territorios[4].nome, "Colômbia");
    strcpy(territorios[4].corExercito, "Roxo");
    territorios[4].numeroTropas = 10;
}

// Função para exibir o mapa
void exibirMapa(struct Territorio territorios[]) {
    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < QTDE_TERRITORIOS; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].corExercito);
        printf("Número de Tropas: %d\n", territorios[i].numeroTropas);
    }
}

// Menu principal
int main() {
    struct Territorio territorios[QTDE_TERRITORIOS];
    int opcao;

    // inicia com dados de exemplo
    preencherExemplo(territorios);

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Cadastrar territórios manualmente\n");
        printf("2 - Exibir mapa\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o \n

        switch (opcao) {
            case 1:
                cadastrarTerritorios(territorios);
                break;
            case 2:
                exibirMapa(territorios);
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("⚠️  Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
