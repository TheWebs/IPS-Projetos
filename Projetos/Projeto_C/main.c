
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "operacoes.h"
#include "Biblioteca.h"
#include "Balcao.h"

void analisarOperacoes(ListaOperacoes op, Data *data, ListaClientes listaClientes, ListaPratos listaPratos, Balcao balcao, Fila fila);



int main(int argc, char** argv) {
    Balcao balcao = criarBalcao();
    Fila fila = criarFila();
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

void analisarOperacoes(ListaOperacoes op, Data *data, ListaClientes listaClientes, ListaPratos listaPratos, Balcao balcao, Fila fila)
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
        }
        if(strcmp(tokens[0], "AC") == 0)
        {
            int id = atoi(tokens[1]);
            int found = 0;
            for(int i = 0; i < listaClientes.contagem; i++)
            {
                if(listaClientes.clientes[i].id == id)
                {
                    adicionarCliente(listaClientes.clientes[i], fila);
                    atualizarBalcao();
                    imprimeCliente(listaClientes.clientes[i]);
                    found = 1;
                }
            }
            if(found == 0){printf("Nao existe nenhum cliente com esse id!\n");}
        }
        if(strcmp(tokens[0], "IR") == 0)
        {
            int found = 0;
            int id = atoi(tokens[1]);
            for(int i = 0; i < listaClientes.contagem; i++)
            {
                if(listaClientes.clientes[i].id == id)
                {
                    found = 1;
                }
            }
            if(found == 0){printf("Erro: Cliente nao encontrado!\n");}
            else
            {
                found = 0;
                for(int i = 0; i < 4; i++)
                {
                    if(balcao.clientes[i].id == -123){}
                    else
                    {
                        if(balcao.clientes[i].id == id)
                        {
                            tokens = split(tokens[2], 3, "/");
                            Data data2 = criarData(atoi(tokens[0]), atoi(tokens[1]), atoi(tokens[2]));
                            Meal meal = criarMeal(data2, stackCreate(), 0);
                            queueEnqueue(balcao.clientes[i].refeicoes, &meal);
                            found = 1;
                        }
                    }
                }
                if(found == 0){printf("O cliente nao se encontra ao balcao");}
            }
                
        }
    }
}

