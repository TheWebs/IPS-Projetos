#include <stdio.h>
#include <stdlib.h>
#include "StatesList.h"
#include <string.h>

StatesList createSL(int size) {
    StatesList sl;
    sl.states = (State*) calloc(size, sizeof (State));
    sl.pos = 0;
    return sl;
}

State createState(char nome[61]) {
    State state;
    strcpy(state.state, nome);
    state.count = 0;
    return state;
}

int stateExists(StatesList sl, char nome[61]) {
    for(int i = 0; i < sl.pos; i++)
    {
        if(strcmp(sl.states[i].state, nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

void sortSL(StatesList sl) {
    int noChanges = 0;
    while (noChanges == 0) {
        int somethingChanged = 0;
        for (int i = 0; i < sl.pos - 1; i++) {
            if (sl.states[i].count > sl.states[i + 1].count) {
                State aux = sl.states[i + 1];
                sl.states[i + 1] = sl.states[i];
                sl.states[i] = aux;
                somethingChanged = 1;
            }
        }
        if (somethingChanged == 0) {
            noChanges = 1;
        }
    }
}

void printState(State state)
{
    printf("	State: %s", state.state);
    for(int i = 0; i < 30-strlen(state.state); i++)
    {
        printf(" ");
    }
    printf("| Caches: %d\n", state.count);
}

void printSL(StatesList sl)
{
    for(int i = sl.pos-1; i > -1; i--)
    {
        printState(sl.states[i]);
    }
}