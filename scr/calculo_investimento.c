#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "../include/calculo_investimento.h"

void obterDataAtual(char *dataAtual) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dataAtual, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int calcularDiferencaDias(const char *dataInicio, const char *dataFim) {
    struct tm tm1 = {0}, tm2 = {0};
    int dia1, mes1, ano1, dia2, mes2, ano2;

    sscanf(dataInicio, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(dataFim, "%d/%d/%d", &dia2, &mes2, &ano2);

    tm1.tm_mday = dia1;
    tm1.tm_mon = mes1 - 1;
    tm1.tm_year = ano1 - 1900;

    tm2.tm_mday = dia2;
    tm2.tm_mon = mes2 - 1;
    tm2.tm_year = ano2 - 1900;

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    return (t2 - t1) / (60 * 60 * 24);
}

void atualizarInvestimento(Investimento *investimento, const char *dataAtual) {
    int dias = calcularDiferencaDias(investimento->data, dataAtual);

    int meses = dias / 30;
    investimento->valorBruto = (meses > 0) ? investimento->valor * pow(1 + investimento->taxajuros / 100, meses) : investimento->valor;

    float lucro = investimento->valorBruto - investimento->valor;
    if (strcmp(investimento->imposto, "IR") == 0 && lucro > 0) {
        if (dias <= 180) investimento->valorImposto = lucro * 0.225;
        else if (dias <= 360) investimento->valorImposto = lucro * 0.20;
        else if (dias <= 720) investimento->valorImposto = lucro * 0.175;
        else investimento->valorImposto = lucro * 0.15;
    } else {
        investimento->valorImposto = 0;
    }
}

