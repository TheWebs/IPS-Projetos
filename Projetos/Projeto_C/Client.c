#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "Biblioteca.h"
#include "Meal.h"
#include "queue2.h"
#include "Balcao.h"

Client createClient(int id, char *name, char *surname, int age)
{
    Client client;
   
    //client.name = (char*) calloc(strlen(name), sizeof (char));
    //client.surname = (char*) calloc(strlen(surname), sizeof (char));
    
    strcpy(client.name, name);
    strcpy(client.surname, surname);
    client.age = age;
    client.id = id;
    client.pontos = 0;
    client.refeicoes = queueCreate();
    return client;
}

void imprimeCliente(Client cliente)
{
        printf("Numero: %d\nNome: %s\nApelido: %s\nIdade: %d\nPontos: %d\n", cliente.id, cliente.name, cliente.surname, cliente.age, cliente.pontos);
}

void atualizarPontos(Data data, Client cliente)
{
    Meal meal;
    while(queueIsEmpty(cliente.refeicoes) == 0)
    {
        queuePeek(cliente.refeicoes, &meal);
        if(checkData(data, meal.data))
        {
              queueDequeue(cliente.refeicoes, &meal);
              cliente.pontos += meal.valor;
        }
        else
        {
            return;
        }

    }
}


ListaClientes leClientesDeFicheiro()
{
       
    ListaClientes lista;
    char linha[100];
    char** tokens;
    FILE *f = fopen("clientes.txt", "r");
    int counter = getNumberLines("clientes.txt");
    
    lista.clientes = (Client *)malloc(counter*sizeof(Client));
    lista.contagem = counter;

    int i = 0;
    while(fgets(linha, sizeof(linha), f))
    {
        tokens = split(linha, 4, " ");
        lista.clientes[i] = createClient(atoi(tokens[0]), tokens[2], tokens[1], atoi(tokens[3]));
        i++;
    }
    
    fclose(f);
    return lista;
    
}

