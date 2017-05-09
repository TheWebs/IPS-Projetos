/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Carta.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Carta criarCarta(int numero, int naipe) {
    Carta nova;
    nova.naipe = naipe;
    nova.numero = numero;
    return nova;
}

baralho criarBaralho() {
    baralho Baralho;
    int a = 0;
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 13; i++) {
            Baralho.cartas[a] = criarCarta(i+1, j+1);
            a++;
        }
    }
    Baralho.indice = 0;
    //Baralhar
    srand(time(NULL));
    for(int i = 0; i < 52; i++)
    {
        int r = RandRange(0, 51);
        Carta aux = Baralho.cartas[i];
        Baralho.cartas[i] = Baralho.cartas[r];
        Baralho.cartas[r] = aux;
    }
    return Baralho;

}

Carta virarCarta(baralho * br, int n) {
    Carta carta = br->cartas[n];
    br->indice++;
    return carta;
}

int RandRange(int Min, int Max) {
    int diff = Max - Min;
    return (int) (((double) (diff + 1) / RAND_MAX) * rand() + Min);
}

void imprimeCarta(Carta carta)
{
    switch(carta.naipe)
    {
        case PAUS:
            printf("%d de paus\n", carta.numero);
            break;
        case COPAS:
            printf("%d de copas\n", carta.numero);
            break;
        case OUROS:
            printf("%d de ouros\n", carta.numero);
            break;
        case ESPADAS:
            printf("%d de espadas\n", carta.numero);
            break;
        default:
            break;
    }
}