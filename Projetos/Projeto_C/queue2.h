#include "TypeElementQueueFila.h"

#define QUEUE_OK            0
#define QUEUE_NULL          1
#define QUEUE_NO_MEMORY     2
#define QUEUE_EMPTY         3
#define QUEUE_FULL          4
    
    /* forward declaration da estrutura da fila.
     Será definida em concreto pela implementacao num *.c */
    struct queueImpl2;
    
    /* Definicao de ponteiro para a estrutura da fila */
    typedef struct queueImpl2 *PtQueue2;     
    
    /* Cria uma fila. Devolve a referência da pilha criada ou 
     * NULL no caso de inexistência de memória. */
    PtQueue2 queueCreate2();
    /* Destroi uma fila, libertando a memória associada. Devolve: QUEUE_OK em
     * caso de sucesso, ou QUEUE_NULL no caso de ser ponteiro nulo. */
    int queueDestroy2(PtQueue2 *ptQueue);
    /* Empilha 'elem' na fila. Devolve: QUEUE_OK no caso de sucesso; 
     * QUEUE_NULL em caso de ponteiro nulo; QUEUE_NO_MEMORY caso nao haja mais memória 
     * disponivel, ou; QUEUE_FULL caso a fila esteja cheia. */
    int queueEnqueue2(PtQueue2 queue, QTypeElem2 elem);
    /* Retira um elemento da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a pilha esteja vazia. */
    int queueDequeue2(PtQueue2 queue, QTypeElem2 *ptElem);
    /* Espreita o inicio da fila, copiando o seu conteúdo para 'ptElem'. 
     Devolve: QUEUE_OK no caso de sucesso; QUEUE_NULL em caso de ponteiro nulo, ou; 
     * QUEUE_EMPTY caso a fila esteja vazia. */
    int queuePeek2(PtQueue2 queue, QTypeElem2 *ptElem);
    /* Calcula o tamanho da fila, copiando esse valor para 'ptSize'. 
     Devolve: QUEUE_OK no caso de sucesso, ou; QUEUE_NULL em caso de ponteiro nulo. */
    int queueSize2(PtQueue2 queue, int *ptSize);
    /* Verifica se a fila está vazia. 
     Devolve: 1 caso esteja vazia ou seja NULL; 0 não se encontre vazia. */
    int queueIsEmpty2(PtQueue2 queue);

