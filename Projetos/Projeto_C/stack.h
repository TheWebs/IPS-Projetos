/*
 * Implementacao em C do TAD Stack.
 * brunomnsilva 2017
 */

/* 
 * File:   stackStatic.h
 * Author: brunomnsilva
 *
 * Created on March 24, 2017, 10:04 AM
 */

#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#define STACK_OK            0
#define STACK_NULL          1
#define STACK_NO_MEMORY     2
#define STACK_EMPTY         3
#define STACK_FULL          4
    
#include "typeElement.h"
    
    /* forward declaration da estrutura da stack.
     Será definida em concreto pela implementacao num *.c */
    struct stackImpl;
    
    /* Definicao de ponteiro para a estrutura da stack */
    typedef struct stackImpl *PtStack;     
    
    /* Cria uma pilha. Devolve a referência da pilha criada ou 
     * NULL no caso de inexistência de memória. */
    PtStack stackCreate();
    /* Destroi uma pilha, libertando a memória associada. Devolve: STACK_OK em c
     * aso de sucesso, ou STACK_NULL no caso de ser ponteiro nulo. */
    int stackDestroy(PtStack *ptStack);
    /* Empilha 'elem' na pilha. Devolve: STACK_OK no caso de sucesso; 
     * STACK_NULL em caso de ponteiro nulo; STACK_NO_MEMORY caso nao haja mais memória 
     * disponivel, ou; STACK_FULL caso a pilha esteja cheia. */
    int stackPush(PtStack stack, TypeElem elem);
    /* Desempilha um elemento da pilha, copiando o seu conteúdo para 'ptElem'. 
     Devolve: STACK_OK no caso de sucesso; STACK_NULL em caso de ponteiro nulo, ou; 
     * STACK_EMPTY caso a pilha esteja vazia. */
    int stackPop(PtStack stack, TypeElem *ptElem);
    /* Espreita o topo pilha, copiando o seu conteúdo para 'ptElem'. 
     Devolve: STACK_OK no caso de sucesso; STACK_NULL em caso de ponteiro nulo, ou; 
     * STACK_EMPTY caso a pilha esteja vazia. */
    int stackPeek(PtStack stack, TypeElem *ptElem);
    /* Calcula o tamanho da pilha, copiando esse valor para 'ptSize'. 
     Devolve: STACK_OK no caso de sucesso, ou; STACK_NULL em caso de ponteiro nulo. */
    int stackSize(PtStack stack, int *ptSize);
    /* Verifica se a pilha está vazia. 
     Devolve: 1 caso esteja vazia ou seja NULL; 0 não se encontre vazia. */
    int stackIsEmpty(PtStack stack);

#ifdef __cplusplus
}
#endif

#endif /* STACK_H */

