/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mapTypeElement.h
 * Author: brunomnsilva
 *
 * Created on May 10, 2017, 9:10 AM
 */

#ifndef MAPTYPEELEMENT_H
#define MAPTYPEELEMENT_H
#include "cache.h"
#include "keyCode.h"
#include "list.h"
#ifdef __cplusplus
extern "C" {
#endif


    
    typedef keyCode MapKey;
    typedef Cache MapValue;
    
    /* Retorna 1 se as duas chaves sao iguais, 0 caso contrário. */
    int keyEquals(MapKey key1, MapKey key2);
    /* Funcao de dispersao para uma dada chave 'key' e modulo a aplicar.
     * Nao utilizada na implementacao estatica. */
    int keyHash(MapKey key, int HASHTABLE_SIZE);
    

#ifdef __cplusplus
}
#endif

#endif /* MAPTYPEELEMENT_H */

