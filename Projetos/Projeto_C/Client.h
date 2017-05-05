/* 
 * File:   Client.h
 * Author: franc
 *
 * Created on 12 de Abril de 2017, 15:47
 */
#ifndef CLIENT_H
#define	CLIENT_H

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "queue.h"

typedef struct Client {
    int id;
    int pontos;
    char name[25];
    char surname[25];
    int age;
    PtQueue refeicoes;
}Client;

typedef struct ListaClientes {
    int contagem;
    Client *clientes;
}ListaClientes;

Client createClient(int id, char *name, char *surname, int age);
ListaClientes leClientesDeFicheiro();

void imprimeCliente(Client cliente);
int getNumberLines();
void atualizarPontos(Data data, Client cliente);


#endif	/* CLIENT_H */

