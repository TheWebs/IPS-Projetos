/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "mapTypeElement.h"
#include "keyCode.h"
#include <stdio.h>
#include <string.h>


int keyEquals(MapKey key1, MapKey key2) {
    /* chaves sao iguais sse os textos sao iguais. */
    return (strcmp(key1.code, key2.code) == 0);
}



int keyHash(MapKey key, int HASHTABLE_SIZE) {
    int length = strlen(key.code), A = 31415, B = 27183, total = 0;
    for(int i=0; i < length; i++) {
        total = (total * A + key.code[i]) % HASHTABLE_SIZE;
        
        A = A * B % (HASHTABLE_SIZE - 1);
    }
    return total;
}

