/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: brunomnsilva
 *
 * Created on April 18, 2017, 4:31 PM
 */

#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C" {
#endif


#define LIST_OK            0
#define LIST_NULL          1
#define LIST_NO_MEMORY     2
#define LIST_EMPTY         3
#define LIST_FULL          4
#define LIST_INVALID_RANK  5
    
#include "listTypeElement.h"

    struct listImpl;
    typedef struct listImpl *PtList;

    /* Cria uma lista. Devolve a referência da lista criada ou NULL, 
     * no caso de inexistência de memória. */
    PtList listCreate();
    /* Destrói a lista e coloca a referência a NULL. 
     * Valores de retorno: LIST_OK ou LIST_NULL. */
    int listDestroy(PtList *ptList);
    /* Insere elem no rank da lista 'list'. 
     * Valores de retorno: LIST_OK, LIST_NULL ou LIST_INVALID_RANK */
    int listAdd(PtList list, int rank, LTypeElem elem);
    /* Substitui o elemento que está no rank 'rank'  da lista 'list' e "devolve" o antigo.
     * Valores de retorno: LIST_OK, LIST_NULL, LIST_FULL ou LIST_INVALID_RANK */
    int listSet(PtList list, int rank, LTypeElem elemIn, LTypeElem *ptElemOut);
    /* Remove o elemento do rank 'rank' da lista 'list'. 
     * Valores de retorno: LIST_OK, LIST_NULL, LIST_INVALID_RANK ou LIST_EMPTY */
    int listRemove(PtList list, int rank, LTypeElem *ptElem);
    /* Devolve o elemento no rank 'rank' da lista 'list'. 
     * Valores de retorno: LIST_OK, LIST_NULL, LIST_INVALID_RANK ou LIST_EMPTY*/
    int listGet(PtList list, int rank, LTypeElem *ptElem);
    /*Devolve o tamanho da lista 'list'. Devolve LIST_NULL se 'list' for NULL*/
    int listSize(PtList list, int *ptSize);
    /* Verifica se a lista 'list' está vazia. Valores de retorno: 1 ou 0 */
    int listIsEmpty(PtList list);


#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

