
#ifndef FILA_H
#define FILA_H
#include "queue2.h"

typedef struct Fila{
    PtQueue filas[2];
}Fila;

Fila criarFila();
//void adicionarCliente(Client cliente, Fila fila);

#endif /* FILA_H */

