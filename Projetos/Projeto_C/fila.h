/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fila2.h
 * Author: Rui
 *
 * Created on 05 May 2017, 19:38
 */

#ifndef FILA2_H
#define FILA2_H

#ifdef __cplusplus
extern "C" {
#endif
#include "queue2.h"
    typedef PtQueue2 FilasEspera[2];

void criarFilas(FilasEspera filas);
void adicionarClienteAFila(Client cliente, FilasEspera fila);

#ifdef __cplusplus
}
#endif

#endif /* FILA2_H */

