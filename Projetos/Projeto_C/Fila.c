#include "Client.h"
#include "fila.h"

void criarFilas(FilasEspera filas)
{
   // FilasEspera filas;
    
    filas[0] = queueCreate2();
    filas[1] = queueCreate2();
    
    //return filas;
}

void adicionarClienteAFila(Client cliente, FilasEspera filas)
{
    if(cliente.age < 60)
    {
        queueEnqueue2(filas[0], cliente);
    }
    else
    {
         queueEnqueue2(filas[1], cliente);
    }
}