#ifndef CALCULO_INVESTIMENTO_H
#define CALCULO_INVESTIMENTO_H

#include "investimento.h"

void obterDataAtual(char *dataAtual);
int calcularDiferencaDias(const char *dataInicio, const char *dataFim);
void atualizarInvestimento(Investimento *investimento, const char *dataAtual);

#endif // CALCULO_INVESTIMENTO_H

