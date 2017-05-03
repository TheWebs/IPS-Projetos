/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Operacoes.h"
#include "Biblioteca.h"

ListaOperacoes lerOperacoes()
{
    ListaOperacoes lista;
    char linha[100];
    FILE *f = fopen("operacoes.txt", "r");
    int counter = getNumberLines("operacoes.txt");
    lista.operacoes = (Operacao *) calloc(counter, sizeof(Operacao));
    lista.contagem = counter;
    int i = 0;
    while(fgets(linha, sizeof(linha), f))
    {
        lista.operacoes[i] = criarOperacao(linha);
        i++;
    }
    return lista;
}

Operacao criarOperacao(char *operacao)
{
    Operacao op;
    strcpy(op.instrucao, operacao);
    return op;
}

void imprimeOperacao(Operacao op)
{
    printf("%s", op.instrucao);
}
