/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Balcao.h
 * Author: franc
 *
 * Created on 3 de Maio de 2017, 16:54
 */

#ifndef BALCAO_H
#define BALCAO_H
#include "Client.h"

typedef struct Balcao {
    Client clientes[4];
    int lugaresVazios;
}Balcao;

void adicionarCliente(Client client, Balcao balcao);
void removerCliente(Client client, Balcao balcao);
//oid atualizarBalcao(Balcao balcao);

#endif /* BALCAO_H */

