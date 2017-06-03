/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatesList.h
 * Author: franc
 *
 * Created on June 3, 2017, 1:58 PM
 */

#ifndef STATESLIST_H
#define STATESLIST_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct State{
        char state[61];
        int count;
    }State;
    
    typedef struct StatesList {
        State *states;
        int pos;
    }StatesList;

    State createState(char nome[61]);
    StatesList createSL(int size);
    int stateExists(StatesList sl, char nome[61]);
    void sortSL(StatesList sl);
    void printSL(StatesList sl);
    void printState(State state);

#ifdef __cplusplus
}
#endif

#endif /* STATESLIST_H */

