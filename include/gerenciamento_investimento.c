#include <stdio.h>
#include <stdlib.h>
#include "../include/gerenciamento_investimento.h"

void adicionarInvestimento(Investimento *investimentos, int *quantidade) {
    printf("Digite a data de aplicação (DD/MM/AAAA): ");
    scanf("%s", investimentos[*quantidade].data);

    printf("Digite o valor: ");
    scanf("%f", &investimentos[*quantidade].valor);

    getchar();
    printf("Digite o tipo: ");
    fgets(investimentos[*quantidade].tipo, sizeof(investimentos[*quantidade].tipo), stdin);
    investimentos[*quantidade].tipo[strcspn(investimentos[*quantidade].tipo, "\n")] = '\0';

    printf("Digite o nome: ");
    fgets(investimentos[*quantidade].nome, sizeof(investimentos[*quantidade].nome), stdin);
    investimentos[*quantidade].nome[strcspn(investimentos[*quantidade].nome, "\n")] = '\0';

    printf("Digite a data de vencimento (DD/MM/AAAA): ");
    scanf("%s", investimentos[*quantidade].datavencimento);

    printf("Digite a taxa de juros: ");
    scanf("%f", &investimentos[*quantidade].taxajuros);

    printf("Digite o tipo de imposto (ex: IR): ");
    scanf("%s", investimentos[*quantidade].imposto);

    (*quantidade)++;
}

void listarInvestimentos(Investimento *investimentos, int quantidade) {
    printf("\nLista de Investimentos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s | %.2f | %s | %s\n", investimentos[i].data, investimentos[i].valor, investimentos[i].tipo, investimentos[i].nome);
    }
}
