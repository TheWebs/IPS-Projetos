/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Operacoes.h
 * Author: franc
 *
 * Created on April 30, 2017, 1:55 AM
 */

#ifndef OPERACOES_H
#define OPERACOES_H

typedef struct Operacao{
    char instrucao[100];
}Operacao;

typedef struct ListaOperacoes{
    Operacao *operacoes;
    int contagem;
    
}ListaOperacoes;

ListaOperacoes lerOperacoes();
Operacao criarOperacao(char *operacao);
void imprimeOperacao(Operacao op);

#endif /* OPERACOES_H */

