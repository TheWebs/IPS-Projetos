/*
 * Implementacao em C do TAD Stack.
 * brunomnsilva 2017
 */


#include <stdlib.h>
#include "queue2.h"
struct qnode2;
typedef struct qnode2 *PtQNode2;

typedef struct qnode2 {
    QTypeElem2 elem;
    PtQNode2 next;
} QNode2;

typedef struct queueImpl2 {
    PtQNode2 head;
    PtQNode2 tail;
    int size;
} MyQueue2;

PtQueue2 queueCreate2() {
    PtQueue2 newQueue = (MyQueue2*) malloc( sizeof(MyQueue2) );
    
    if(newQueue == NULL) { return NULL; }
    
    newQueue->head = NULL; /* inicializar cabeca da lista */
    newQueue->tail = NULL; /* inicializar cauda da lista */
    newQueue->size = 0;
    return newQueue;
}

int queueDestroy2(PtQueue2 *ptQueue) {
    PtQueue2 curQueue = (*ptQueue);
    if(curQueue == NULL) { return QUEUE_NULL; }
    
    QTypeElem2 aux;
    while(curQueue->size > 0) { /* explorar impl. de dequeue */
        queueDequeue2(curQueue, &aux);
    }
    
    free(curQueue); 
    *ptQueue = NULL; /* colocar valor de ponteiro a NULL */
    return QUEUE_OK;
}

int queueEnqueue2(PtQueue2 queue, QTypeElem2 elem) {
    if(queue == NULL) { return QUEUE_NULL; }
            
    PtQNode2 newNode = (PtQNode2) malloc( sizeof(QNode2) );
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

int queueDequeue2(PtQueue2 queue, QTypeElem2 *ptElem) {
    if(queue == NULL) { return QUEUE_NULL; }
    if(queue->size <= 0) { return QUEUE_EMPTY; }
    
    /* removao da head (inicio da fila) */
    PtQNode2 curHead = queue->head;
    (*ptElem) = curHead->elem;
    
    queue->head = curHead->next; /* avancar ponteiro; pode ser NULL no caso abaixo */
        
    if(queue->size == 1) { /* ..se vamos retirar o unico elemento existente */
        queue->tail = NULL; /* cauda deixa de existir */
    }
    
    free(curHead); /* libertar memórica alocada para o nó */
    
    queue->size--;
    return QUEUE_OK;
}

int queuePeek2(PtQueue2 queue, QTypeElem2 *ptElem) {
    if(queue == NULL) { return QUEUE_NULL; }
    if(queue->size <= 0) { return QUEUE_EMPTY; }
    
    /* espreitar na head (inicio da fila) */
    PtQNode2 curHead = queue->head;
    (*ptElem) = curHead->elem;
    return QUEUE_OK;
}

int queueSize2(PtQueue2 queue, int *ptSize) {
    if(queue == NULL) { return QUEUE_NULL; }
    
    (*ptSize) = queue->size;
    return QUEUE_OK;
}

int queueIsEmpty2(PtQueue2 queue) {
    if(queue == NULL) { return 1; } /* consideramos inexistente como vazia */
    
    return (queue->size == 0) ? 1 : 0;
}

