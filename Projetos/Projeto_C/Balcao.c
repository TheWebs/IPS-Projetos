#include "Balcao.h"
#include "Client.h"
#include "Meal.h"
#include "Prato.h"
#include "Fila.h"


Balcao criarBalcao()
{
    Balcao balcao;
    for(int i = 0; i < 4; i++)
    {
        balcao.clientes[i] = createClient( -123, "NULL", "NULL", -1);
    }
    balcao.lugaresVazios = 4;
    return balcao;
}

void adicionarCliente(Client client, Balcao balcao)
{
    for(int i = 0; i < 4; i++)
    {
        if(balcao.clientes[i].id == -123)
        {
            balcao.clientes[i] = client;
            balcao.lugaresVazios--;
            return;
        }
    }
}

void removerCliente(Client client, Balcao balcao)
{
    for(int i = 0; i < 4; i++)
    {
        if(balcao.clientes[i].id == client.id)
        {
            balcao.clientes[i] = createClient( -123, "NULL", "NULL", -1);
            balcao.lugaresVazios++;
            return;
        }
    }
    printf("O cliente nao foi removido do balcao pois nao existe!\n");
}

/*void atualizarBalcao(Balcao balcao, Fila fila)
{
    while(balcao.lugaresVazios != 0)
    {
        
        if(queueIsEmpty(fila.filas[0]) == 0)
        {
            //adicionarCliente(fila.filas[0].head->elem)
        }
    }
    
    
}*/