

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

#ifndef QUEUE_H
#define QUEUE_H

#include "queueTypeElement.h"

#define QUEUE_OK            0
#define QUEUE_NULL          1
#define QUEUE_NO_MEMORY     2
#define QUEUE_EMPTY         3
#define QUEUE_FULL          4
    

    
    /* forward declaration da estrutura da fila.
     Será definida em concreto pela implementacao num *.c */
    struct queueImpl;
    
    /* Definicao de ponteiro para a estrutura da fila */
    typedef struct queueImpl *PtQueue;     
    
    /* Cria uma fila. Devolve a referência da pilha criada ou 
     * NULL no caso de inexistência de memória. */
    PtQueue queueCreate();
    /* Destroi uma fila, libertando a memória associada. Devolve: QUEUE_OK em
     * caso de sucesso, ou QUEUE_NULL no caso de ser ponteiro nulo. */
    int queueDestroy(PtQueue *ptQueue);
    /* Empilha 'elem' na fila. Devolve: QUEUE_OK no caso de sucesso; 
     * QUEUE_NULL em caso de ponteiro nulo; QUEUE_NO_MEMORY caso nao haja mais memória 
     * disponivel, ou; QUEUE_FULL caso a fila esteja cheia. */
    int queueEnqueue(PtQueue queue, QTypeElem elem);
    /* Retira um elemento da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a pilha esteja vazia. */
    int queueDequeue(PtQueue queue, QTypeElem *ptElem);
    /* Espreita o inicio da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a fila esteja vazia. */
    int queuePeek(PtQueue queue, QTypeElem *ptElem);
    /* Calcula o tamanho da fila, copiando esse valor para 'ptSize'. 
     Devolve: QUEUE_OK no caso de sucesso, ou; QUEUE_NULL em caso de ponteiro nulo. */
    int queueSize(PtQueue queue, int *ptSize);
    /* Verifica se a fila está vazia. 
     Devolve: 1 caso esteja vazia ou seja NULL; 0 não se encontre vazia. */
    int queueIsEmpty(PtQueue queue);


#endif /* QUEUE_H */

