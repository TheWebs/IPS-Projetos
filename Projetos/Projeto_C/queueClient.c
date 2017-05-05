/*
 * Implementacao em C do TAD Stack.
 * brunomnsilva 2017
 */

#include "queue2.h"
#include <stdlib.h>

struct qnode;
typedef struct qnode *PtQNode;

typedef struct qnode {
    QTypeElem elem;
    PtQNode next;
} QNode;

typedef struct queueImpl {
    PtQNode head;
    PtQNode tail;
    int size;
} MyQueue;

PtQueue queueCreate() {
    PtQueue newQueue = (MyQueue*) malloc( sizeof(MyQueue) );
    
    if(newQueue == NULL) { return NULL; }
    
    newQueue->head = NULL; /* inicializar cabeca da lista */
    newQueue->tail = NULL; /* inicializar cauda da lista */
    newQueue->size = 0;
    return newQueue;
}

int queueDestroy(PtQueue *ptQueue) {
    PtQueue curQueue = (*ptQueue);
    if(curQueue == NULL) { return QUEUE_NULL; }
    
    QTypeElem aux;
    while(curQueue->size > 0) { /* explorar impl. de dequeue */
        queueDequeue(curQueue, &aux);
    }
    
    free(curQueue); 
    *ptQueue = NULL; /* colocar valor de ponteiro a NULL */
    return QUEUE_OK;
}

int queueEnqueue(PtQueue queue, QTypeElem elem) {
    if(queue == NULL) { return QUEUE_NULL; }
            
    PtQNode newNode = (PtQNode) malloc( sizeof(QNode) );
    if(newNode == NULL) {
        return QUEUE_NO_MEMORY;
    }
    
    newNode->elem = elem;    
    newNode->next = NULL;
    
    /* insercao na tail (cauda da fila) */
    if(queue->size == 0) { /* se for o primeiro elemento a inserir numa fila vazia */
        queue->head = newNode;        
    } else { /* caso contrario */
        queue->tail->next = newNode;
    }
    queue->tail = newNode; /* op. em comum para as duas situacoes */
    
    queue->size++;
    return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QTypeElem *ptElem) {
    if(queue == NULL) { return QUEUE_NULL; }
    if(queue->size <= 0) { return QUEUE_EMPTY; }
    
    /* removao da head (inicio da fila) */
    PtQNode curHead = queue->head;
    (*ptElem) = curHead->elem;
    
    queue->head = curHead->next; /* avancar ponteiro; pode ser NULL no caso abaixo */
        
    if(queue->size == 1) { /* ..se vamos retirar o unico elemento existente */
        queue->tail = NULL; /* cauda deixa de existir */
    }
    
    free(curHead); /* libertar memórica alocada para o nó */
    
    queue->size--;
    return QUEUE_OK;
}

int queuePeek(PtQueue queue, QTypeElem *ptElem) {
    if(queue == NULL) { return QUEUE_NULL; }
    if(queue->size <= 0) { return QUEUE_EMPTY; }
    
    /* espreitar na head (inicio da fila) */
    PtQNode curHead = queue->head;
    (*ptElem) = curHead->elem;
    return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize) {
    if(queue == NULL) { return QUEUE_NULL; }
    
    (*ptSize) = queue->size;
    return QUEUE_OK;
}

int queueIsEmpty(PtQueue queue) {
    if(queue == NULL) { return 1; } /* consideramos inexistente como vazia */
    
    return (queue->size == 0) ? 1 : 0;
}

