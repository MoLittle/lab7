#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

typedef struct {
    char data[11];
    float valor;
    char tipo[25];
    char nome[25];
    char datavencimento[11];
    float taxajuros;
    char imposto[25];
    float valorBruto;
    float valorImposto;
} Investimento;

#endif // INVESTIMENTO_H
