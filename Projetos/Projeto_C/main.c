
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "operacoes.h"
#include "Biblioteca.h"

void analisarOperacoes(ListaOperacoes op, Data *data, ListaClientes listaClientes, ListaPratos listaPratos);



int main(int argc, char** argv) {
//    Balcao balcao = criarBalcao();
    Data data = criarData(0, 0, 0);
    ListaClientes lista = leClientesDeFicheiro();
    for(int i = 0; i < lista.contagem;i++)
    {
        imprimeCliente(lista.clientes[i]);
    }
    
    ListaPratos listaPratos = lePratosDeFicheiro();
    for(int i = 0; i < listaPratos.contagem; i++)
    {
        imprimePrato(listaPratos.pratos[i]);
    }
    
    ListaOperacoes lista2 = lerOperacoes();
    for(int i = 0; i < lista2.contagem;i++)
    {
        imprimeOperacao(lista2.operacoes[i]);
    }
    analisarOperacoes(lista2, &data, lista, listaPratos);
    
    return (EXIT_SUCCESS);
}

void analisarOperacoes(ListaOperacoes op, Data *data, ListaClientes listaClientes, ListaPratos listaPratos)
{
    for(int i = 0; i < op.contagem; i++)
    {
        char** tokens;
        tokens = split(op.operacoes[i].instrucao, 3, " ");
        if(strcmp(tokens[0], "AD") == 0)
        {
            tokens = split(tokens[1], 3, "/");
            Data data2 = criarData(atoi(tokens[0]), atoi(tokens[1]), atoi(tokens[2]));
                (*data) = data2;
                printf("\nNova data: ");
                imprimeData((*data));
                return;
        }
        if(strcmp(tokens[0], "AC") == 0)
        {
            int id = atoi(tokens[1]);
            for(int i = 0; i < listaClientes.contagem; i++)
            {
                if(listaClientes.clientes[i].id == id)
                {
                    imprimeCliente(listaClientes.clientes[i]);
                    return;
                }
            }
            printf("Nao existe nenhum cliente com esse id!\n");
        }
    }
}

