/* 
 * File:   Client.h
 * Author: franc
 *
 * Created on 12 de Abril de 2017, 15:47
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#ifndef CLIENT_H
#define	CLIENT_H


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


#endif	/* CLIENT_H */

