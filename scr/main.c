#include <stdio.h>
#include "../include/investimento.h"
#include "../include/calculo_investimento.h"
#include "../include/gerenciamento_investimento.h"

#define MAX_INVESTIMENTOS 100

int main() {
    Investimento investimentos[MAX_INVESTIMENTOS];
    int quantidade = 0;
    char dataAtual[11];
    int opcao;

    obterDataAtual(dataAtual);

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Investimento\n");
        printf("2. Listar Investimentos\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarInvestimento(investimentos, &quantidade);
                break;
            case 2:
                listarInvestimentos(investimentos, quantidade);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
