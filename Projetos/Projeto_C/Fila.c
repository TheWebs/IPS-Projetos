#include "Fila.h"
#include "Client.h"

Fila criarFila()
{
    Fila fila;
    
    fila.filas[0] = queueCreate2();
    fila.filas[1] = queueCreate2();
    
    return fila;
}

void adicionarCliente(Client cliente, Fila fila)
{
    if(cliente.age < 60)
    {
        queueEnqueue2(fila.filas[0], cliente);
    }
    else
    {
         queueEnqueue2(fila.filas[1], cliente);
    }
}