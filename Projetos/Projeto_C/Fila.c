#include "Fila.h"
#include "Client.h"

Fila criarFila()
{
    Fila fila;
    
    fila.filas[0] = queueCreate();
    fila.filas[1] = queueCreate();
    
    return fila;
}
/*
void adicionarCliente(Client cliente, Fila fila)
{
    if(cliente.age < 60)
    {
        queueEnqueue(fila.filas[0], cliente);
    }
    else
    {
         queueEnqueue(fila.filas[1], cliente);
    }
}*/