/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "list.h"
#include <stdlib.h> 

struct dnode; /* double node - no duplo (next e prev) */
typedef struct dnode *PtDNode;

typedef struct dnode {
    LTypeElem elem;
    PtDNode next;
    PtDNode prev;
} DNode;

typedef struct listImpl {
    PtDNode header;
    PtDNode trailer;
    int size;
} MyList;

/* Função auxiliar para encontrar o nó correspondente a um 'rank' em 'list'. Numa
 implementacao baseada em array nao seria necessario, pois existe um
 mapeamento direto entre 'rank' e o indice do array. 
 Portanto, temos de percorrer a lista, mantendo registo do rank atual, devolvendo
 * o ponteiro para o nó no 'rank' solicitado. */
PtDNode nodeAtRank(PtList list, int rank) {
    /* validacoes? Neste caso serao delegadas para as outras funcoes. */
    int rankAtual = 0;
    PtDNode rankNode;
    if( rank < list->size/2 ) { /* inicio -> fim */
        rankNode = list->header->next;
        while( rankAtual < rank ) {
            rankNode = rankNode->next;
            rankAtual++;
        } 
    } else { /* fim -> inicio */
        rankAtual = list->size;
        rankNode = list->trailer;
        while( rankAtual > rank ) {
            rankNode = rankNode->prev;
            rankAtual--;
        } 
    }
    
    /* Notar que se 'list' estiver vazia, rank = 0 corresponderá a 'list->trailer'*/
    /* Tambem, por outro lado, rank = size corresponderá a 'list->trailer' */
    return rankNode;
}

/* Cria uma lista. Devolve a referência da lista criada ou NULL, 
 * no caso de inexistência de memória. */
PtList listCreate() {
    PtList newList = (PtList) malloc( sizeof(MyList) );
    if(newList == NULL) { return NULL; }
    
    /* nao interessa o campo 'elem' === lixo */
    newList->header = (PtDNode) malloc( sizeof(DNode) );
    newList->trailer = (PtDNode) malloc( sizeof(DNode) );
    
    newList->header->prev = NULL;
    newList->header->next = newList->trailer;
    newList->trailer->prev = newList->header;
    newList->trailer->next = NULL;
    
    newList->size = 0;
    
    return newList;
}

/* Destrói a lista e coloca a referência a NULL. 
 * Valores de retorno: LIST_OK ou LIST_NULL. */
int listDestroy(PtList *ptList) {
    PtList curList = (*ptList);
    
    if(curList == NULL) { return LIST_NULL; }
    
    /* libertar memoria de todos os nos */
    PtDNode curNode = curList->header->next;
    PtDNode auxNode = curNode;
    while( curNode != curList->trailer ) {
        auxNode = curNode;
        curNode = curNode->next;
        /* nao interessa nos preocuparmos com 'prev'*/
        free(auxNode);        
    }
    
    free(curList->header);
    free(curList->trailer);
    
    free(curList);
    
    (*ptList) = NULL;
    
    return LIST_OK;
}

/* Insere elem no rank da lista 'list'. 
 * Valores de retorno: LIST_OK, LIST_NULL ou LIST_INVALID_RANK */
int listAdd(PtList list, int rank, LTypeElem elem) {
    if(list == NULL) { return LIST_NULL; };
    if(rank < 0 || rank > list->size) { return LIST_INVALID_RANK; };
    
    PtDNode newNode = (PtDNode) malloc( sizeof(DNode) );
    if(newNode == NULL) { return LIST_NO_MEMORY; };
    /* inserir elemento no novo no */
    newNode->elem = elem;
    
    /* alterar estrutura da lista, inserindo 'newNode' em 'rank' */
    PtDNode nextNode = nodeAtRank(list, rank);
    PtDNode prevNode = nextNode->prev;
            
    newNode->prev = prevNode;
    newNode->next = nextNode;
    
    prevNode->next = newNode;
    nextNode->prev = newNode;
    
    list->size++;
    
    return LIST_OK;
}

/* Substitui o elemento que está no rank 'rank'  da lista 'list' e "devolve" o antigo.
 * Valores de retorno: LIST_OK, LIST_NULL ou LIST_INVALID_RANK */
int listSet(PtList list, int rank, LTypeElem elemIn, LTypeElem *ptElemOut) {
    if(list == NULL) { return LIST_NULL; };
    if(rank < 0 || rank > list->size - 1) { return LIST_INVALID_RANK; };
    if(list->size <= 0) { return LIST_EMPTY; };
    
    PtDNode curNodeAtRank = nodeAtRank(list, rank);
    (*ptElemOut) = curNodeAtRank->elem;
    curNodeAtRank->elem = elemIn;
    
    return LIST_OK;
}

/* Remove o elemento do rank 'rank' da lista 'list'. 
 * Valores de retorno: LIST_OK, LIST_NULL, LIST_INVALID_RANK ou LIST_EMPTY */
int listRemove(PtList list, int rank, LTypeElem *ptElem) {
    if(list == NULL) { return LIST_NULL; };
    if(rank < 0 || rank > list->size - 1) { return LIST_INVALID_RANK; };
    if(list->size <= 0) { return LIST_EMPTY; };
    
    /* obter elemento no 'rank' solicitado */
    PtDNode curNodeAtRank = nodeAtRank(list, rank);
    (*ptElem) = curNodeAtRank->elem;
    
    /* alterar estrutura da lista, removendo o no e atualizando ligacoes */
    PtDNode nextNode = curNodeAtRank->next;
    PtDNode prevNode = curNodeAtRank->prev;
            
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    
    /* libertar memória do nó a remover */
    free(curNodeAtRank);
    
    list->size--;
    
    return LIST_OK;
}

/* Devolve o elemento no rank 'rank' da lista 'list'. 
 * Valores de retorno: LIST_OK, LIST_NULL, LIST_INVALID_RANK ou LIST_EMPTY*/
int listGet(PtList list, int rank, LTypeElem *ptElem) {
    if(list == NULL) { return LIST_NULL; };
    if(rank < 0 || rank > list->size - 1) { return LIST_INVALID_RANK; };
    if(list->size <= 0) { return LIST_EMPTY; };
    
    PtDNode curNodeAtRank = nodeAtRank(list, rank);
    (*ptElem) = curNodeAtRank->elem;
    
    return LIST_OK;
}

/*Devolve o tamanho da lista 'list'. Devolve LIST_NULL se ptList for NULL*/
int listSize(PtList list, int *ptSize) {
    if(list == NULL) { return LIST_NULL; }
    
    (*ptSize) = list->size;
    return LIST_OK;
}

/* Verifica se a lista 'list' está vazia. Valores de retorno: 1 ou 0 */
int listIsEmpty(PtList list) {
    if(list == NULL) { return 1; } /* consideramos inexistente como vazia */
    
    return (list->size == 0) ? 1 : 0;
}