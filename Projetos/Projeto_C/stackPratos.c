/*
 * Implementacao em C do TAD Stack.
 * brunomnsilva 2017
 */

#include "stack.h"
#include <string.h>
#include <stdlib.h>

struct node;
typedef struct node *PtNode;

typedef struct node {
    TypeElem elem;
    PtNode next;
} Node;

typedef struct stackImpl {
    PtNode top;
    int size;
} MyStack;

PtStack stackCreate() {
    PtStack newStack = (MyStack*) malloc(sizeof (MyStack));

    if (newStack == NULL) { return NULL; }

    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

int stackDestroy(PtStack *ptStack) {
    PtStack curStack = (*ptStack);
    if (curStack == NULL) { return STACK_NULL; }

    //temos que libertar memoria alocada para os possiveis elementos remanescentes
    //porque fazer manualmente, se pop() já deve libertar a memória dos elementos?
    //Contudo, em pop() são executadas mais algumas instruções desnecessárias!
    TypeElem e;
    while(curStack->size > 0) {
        stackPop(curStack, &e);
    }
    
    free(curStack);
    *ptStack = NULL; //colocar valor de ponteiro a NULL
    return STACK_OK;
}

int stackPush(PtStack stack, TypeElem elem) {
    if (stack == NULL) { return STACK_NULL; }

    //criar novo no para guardar elemento
    PtNode newNode = (PtNode) malloc( sizeof(Node) );
    if (newNode == NULL) { return STACK_NO_MEMORY; }
    
    newNode->elem = elem;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    return STACK_OK;
}

int stackPop(PtStack stack, TypeElem *ptElem) {
    if (stack == NULL) { return STACK_NULL; }
    if (stack->size <= 0) { return STACK_EMPTY; }

    PtNode curTop = stack->top;
    (*ptElem) = curTop->elem;    
    stack->top = curTop->next;
    
    free(curTop);
    stack->size--;
    return STACK_OK;
}

int stackPeek(PtStack stack, TypeElem *ptElem) {
    if (stack == NULL) { return STACK_NULL; }
    if (stack->size <= 0) { return STACK_EMPTY; }

    PtNode curTop = stack->top;
    (*ptElem) = curTop->elem;    
    return STACK_OK;
}

int stackSize(PtStack stack, int *ptSize) {
    if (stack == NULL) { return STACK_NULL; }

    (*ptSize) = stack->size;
    return STACK_OK;
}

int stackIsEmpty(PtStack stack) {
    if(stack == NULL) { return 1; } //consideramos inexistente como vazia
    
    return (stack->size == 0) ? 1 : 0;
}
