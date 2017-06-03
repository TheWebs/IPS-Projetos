/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   map.h
 * Author: brunomnsilva
 *
 * Created on May 10, 2017, 9:22 AM
 */

#ifndef MAP_H
#define MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAP_OK              0
#define MAP_NULL            1
#define MAP_NO_MEMORY       2
#define MAP_EMPTY           3
#define MAP_FULL            4
#define MAP_KEY_NOT_FOUND   5
    
#include "mapTypeElement.h"
    
    struct mapImpl;
    typedef struct mapImpl *PtMap;

     /* Cria um novo Map e devolve o ponteiro para a estrutura. NULL caso nao
     seja possivel criar o Map. */
    PtMap   mapCreate();
    /* Dealoca a memoria do Map e coloca ponteiro a null. 
     Retorna MAP_NULL ou MAP_OK */
    int     mapDestroy(PtMap *ptMap);    
    /* Coloca um valor 'newValue' no Map associado à chave 'key'. 
     * Se já existir um mapeamento, é substituído.
     * Retorna MAP_OK, MAP_NULL, MAP_NO_MEMORY ou MAP_FULL. */
    int     mapPut(PtMap map, MapKey key, MapValue newValue);
    /* Obtem o valor associado à chave 'key'. 
     * Retorna: MAP_OK, MAP_NULL ou MAP_KEY_NOT_FOUND */
    int     mapGet(PtMap map, MapKey key, MapValue *ptValue);
    /* Remove o valor associado à chave 'key'. 
     * Retorna: MAP_OK, MAP_NULL ou MAP_KEY_NOT_FOUND */
    int     mapRemove(PtMap map, MapKey key, MapValue *ptValue);        
    /* Verifica se existe um mapeamento definido para 'key'. 
     * Retorna: 1 se existir, 0 caso contario. */
    int     mapContains(PtMap map, MapKey key); 
    /* Limpa todos os valores do Map. Retorna MAP_OK ou MAP_NULL. */
    int     mapClear(PtMap map);
    /* Obtem o tamanho do Map. Retorna MAP_OK ou MAP_NULL. */
    int     mapSize(PtMap map, int *ptSize);
    /* Verifica se o Map está vazio. 
     * Retorna: 1 se sim, 0 caso contario. */
    int     mapIsEmpty(PtMap map);
        

#ifdef __cplusplus
}
#endif

#endif /* MAP_H */

