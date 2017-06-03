/*
 * Implementacao do TAD Map com uma implementacao baseado em tabela de dispersao.
 * Torna necessaria a implementacao da funcao de dispersar para decidir em que 
 * indice da tabela a entrada se encontra ou será colocada.
 * 
 * As "colisoes" sao resolvidas por encadeamento de elementos (separate chaining),
 * utilizando uma lista duplamente ligada com sentinelas.
 *  
 */

#include "map.h"
#include "mapTypeElement.h"
#include <stdlib.h> /* definicao de malloc e NULL */
#include <string.h> /* definicao de memcpy */

/* numero de posicoes da tabela de dispersao */
#define HASHTABLE_SIZE 11

/* definicao de ponteiro para um nó da lista, definida a seguir. */
struct linkedNode;
typedef struct linkedNode *PtLinkedNode;

/* nó de uma lista duplamente ligada, contendo uma chave e uma entrada. */
typedef struct linkedNode {
    MapKey key;
    MapValue value;
    
    PtLinkedNode next;
    PtLinkedNode prev;
} LinkedNode;

/* definicao de uma estrutura de lista duplamente ligada com sentinelas. */
typedef struct linkedList {
    PtLinkedNode header;
    PtLinkedNode trailer;
    int listSize;
} LinkedList;
/* definicao de ponteiro para uma lista duplamente ligada com sentinelas. */
typedef struct linkedList *PtLinkedList;

/* definicao da estrutura de dados de suporte para o TAD Map. */
typedef struct mapImpl {
    PtLinkedList table[HASHTABLE_SIZE];
    int size;
} HashMap;

/* 
 * Prototipos de funcoes internas auxiliares para lista ligada
 */

PtLinkedList createLinkedList();
void destroyLinkedList(PtLinkedList *ptList);
void clearLinkedList(PtLinkedList linkedList);
int addNode(PtLinkedList linkedList, MapKey key, MapValue value);
PtLinkedNode findNodeWithKey(PtLinkedList linkedList, MapKey key);
void removeNode(PtLinkedList list, PtLinkedNode node);

/* 
 * Implementacao de map.h 
 */

PtMap mapCreate() {
    PtMap newMap = (PtMap) malloc( sizeof(HashMap) );
    if( newMap == NULL ) { return NULL; }
    
    int i;
    int error = MAP_OK;
    for(i=0; i < HASHTABLE_SIZE; i++) {
        if( ( newMap->table[i] = createLinkedList() ) == NULL ) {
            error = MAP_NO_MEMORY;
            break;
        }
    }
    newMap->size = 0;
    
    /* se falhou a criacao de alguma lista ligada, libertar memoria alocada
     * às anteriores e ao map atual, retornando NULL. */
    if( error == MAP_NO_MEMORY ) {
        for(int j=0; j < i; j++) {            
            destroyLinkedList(&newMap->table[i]);
        }
        free(newMap);
        return NULL;
    }
    
    return newMap;
}

/* */
int mapDestroy(PtMap *ptMap) {
    PtMap curMap = (*ptMap);
    
    if( curMap == NULL ) { return MAP_NULL; }
    
    /* dealocacao da totalidade da estrutura e subestruturas */
    for(int i=0; i < HASHTABLE_SIZE; i++) {
        destroyLinkedList(&curMap->table[i]);
    }
    
    free(curMap);
        
    (*ptMap) = NULL;
    return MAP_OK;
}

/*  */
int mapPut(PtMap map, MapKey key, MapValue newValue) {
    if(map == NULL) { return MAP_NULL; }
    
    /* se a chave ja existir, o elemento correspondente 
     é substituido. Caso contrario, adicionamos */
    
    /* aplica funcao de dispersao para obter correspondente indice 
     * da tabela de dispersao. */
    int tableIndex = keyHash(key, HASHTABLE_SIZE);
    /* Pesquisar lista ligada correspondente */
    PtLinkedNode node = findNodeWithKey( map->table[ tableIndex ], key );
    
    if( node == NULL ) { 
        addNode(map->table[ tableIndex ], key, newValue);
        map->size++;
    } else {
        node->value = newValue;
    }
    
    return MAP_OK;
}
/* */
int mapGet(PtMap map, MapKey key, MapValue *ptValue) {
    if(map == NULL) { return MAP_NULL; }
    
    /* aplica funcao de dispersao para obter correspondente indice 
     * da tabela de dispersao. */
    int tableIndex = keyHash(key, HASHTABLE_SIZE);
    /* Pesquisar lista ligada correspondente */
    PtLinkedNode node = findNodeWithKey( map->table[ tableIndex ], key );
    
    if( node == NULL ) { return MAP_KEY_NOT_FOUND; }
    
    *(ptValue) = node->value;       
    
    return MAP_OK;   
}
/* */
int mapRemove(PtMap map, MapKey key, MapValue *ptValue) {
    if(map == NULL) { return MAP_NULL; }
    
    /* aplica funcao de dispersao para obter correspondente indice 
     * da tabela de dispersao. */
    int tableIndex = keyHash(key, HASHTABLE_SIZE);
    /* Pesquisar lista ligada correspondente */
    PtLinkedNode node = findNodeWithKey( map->table[ tableIndex ], key );
    
    if( node == NULL ) { return MAP_KEY_NOT_FOUND; }
    
    *(ptValue) = node->value;
    removeNode(map->table[ tableIndex ], node);

    map->size--;

    return MAP_OK;
}

/* */
int mapClear(PtMap map) {
    if( map == NULL ) { return MAP_NULL; }
    
    /* "limpar" listas ligadas */
    for(int i=0; i < HASHTABLE_SIZE; i++) {
        clearLinkedList( map->table[i] );
    }
    
    map->size = 0;
    
    return MAP_OK;
}

/* */
int mapContains(PtMap map, MapKey key) {
    if(map == NULL) { return MAP_NULL; }
    
    /* aplica funcao de dispersao para obter correspondente indice 
     * da tabela de dispersao. */
    int tableIndex = keyHash(key, HASHTABLE_SIZE);
    /* Pesquisar lista ligada correspondente */
    PtLinkedNode node = findNodeWithKey( map->table[ tableIndex ], key );
    
    return ( node != NULL );
}

/* */
int mapSize(PtMap map, int *ptSize) {
    if(map == NULL) { return MAP_NULL; }
    
    (*ptSize) = map->size;
    return MAP_OK;
}

/* */
int mapIsEmpty(PtMap map) {
    if(map == NULL) { return 1; } /* consideramos inexistente como vazio */
    
    return (map->size == 0) ? 1 : 0;
}

/* 
 * Definicao das funcoes auxiliares. Assumem que as estruturas subjacentes
 * estao criadas corretamente e existem. Daí a ausencia de algumas validacoes. 
 *
 */

/* Inicializa uma lista duplamente ligada com sentinelas, devolvendo o ponteiro
 * para a estrutura, ou NULL. */
PtLinkedList createLinkedList() {
    PtLinkedList linkedList = (PtLinkedList) malloc( sizeof(LinkedList) );
     if(linkedList == NULL ) { return NULL; }
    
    linkedList->header = (PtLinkedNode) malloc( sizeof(LinkedNode) );
    linkedList->trailer = (PtLinkedNode) malloc( sizeof(LinkedNode) );
    
    if(linkedList->header == NULL || linkedList->trailer == NULL) { return NULL; }
    
    linkedList->header->prev = NULL;
    linkedList->header->next = linkedList->trailer;
    linkedList->trailer->prev = linkedList->header;
    linkedList->trailer->next = NULL;
    
    linkedList->listSize = 0;
    
    return linkedList;
}

/* reinicializa uma lista duplamente ligada, libertando memoria dos nos alocados */
void clearLinkedList(PtLinkedList linkedList) {
    if(linkedList == NULL) return;
    
    /* libertar memoria de todos os nos. Codigo adaptado de TAD List */
    PtLinkedNode curNode = linkedList->header->next;
    PtLinkedNode auxNode = curNode;
    while( curNode != linkedList->trailer ) {
        auxNode = curNode;
        curNode = curNode->next;
        
        free(auxNode);    
    }
    
    linkedList->header->next = linkedList->trailer;
    linkedList->trailer->prev = linkedList->header;
    
    linkedList->listSize = 0;
}

void destroyLinkedList(PtLinkedList *ptList) {
    /* garantir que memória de nós é dealocada, explorando a função
     clearLinkedList */
    PtLinkedList curList = (*ptList);
    
    clearLinkedList(curList);
    free(curList->header);
    free(curList->trailer);
    free(curList);
    
    (*ptList) = NULL;
    return;
}

/* Devolve o ponteiro para um no contendo a entrada associada a 'key';
 * NULL caso contrário. */
int addNode(PtLinkedList linkedList, MapKey key, MapValue value) {
    /* vamos adicionar ao inicio da lista para previlegiar o acesso
     a elementos mais "recentes". Nao tem que ser necessariamente assim! */
    PtLinkedNode newNode = (PtLinkedNode) malloc( sizeof(LinkedNode) );
    if( newNode == NULL ) { return MAP_NO_MEMORY; }
    
    newNode->key = key;
    newNode->value = value; 
    
    /* atualizar ligacoes do novo nó. */
    newNode->next = linkedList->header->next;
    newNode->prev = linkedList->header;
    /* atualizar ligacoes dos nós adjacentes ao novo. */
    linkedList->header->next = newNode;
    newNode->next->prev = newNode;
    
    linkedList->listSize++;
    return MAP_OK;
}

/* Devolve o ponteiro para um no contendo a entrada associada a 'key';
 * NULL caso contrário. */
PtLinkedNode findNodeWithKey(PtLinkedList linkedList, MapKey key) {
    if( linkedList->listSize == 0 ) { return NULL; }

    /* Percorrer todos os nós à procuda da chave 'key' */
    PtLinkedNode curNode = linkedList->header->next;
    while (curNode != linkedList->trailer) {
        if( keyEquals(curNode->key, key) ) {
            return curNode;
        }
        curNode = curNode->next;
    }
    
    return NULL;
}


/* Remove um determinado nó de uma lista, dealocando a sua memória. */
void removeNode(PtLinkedList list, PtLinkedNode node) {
    //TODO: validar que 'node' pertence a 'list'?
    //Como é uma funcao interna, vamos assumir que nunca
    //sera invocada incorretamente.
    PtLinkedNode nodeNext = node->next;
    PtLinkedNode nodePrev = node->prev;
    
    nodePrev->next = nodeNext;
    nodeNext->prev = nodePrev;
    
    free(node);
    
    list->listSize--;
}