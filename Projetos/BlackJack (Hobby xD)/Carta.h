/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carta.h
 * Author: franc
 *
 * Created on May 9, 2017, 1:36 AM
 */
#define PAUS 1
#define COPAS 2
#define OUROS 3
#define ESPADAS 4


#ifndef CARTA_H
#define CARTA_H

typedef struct Carta {
    int numero;
    int naipe;
}Carta;

typedef struct baralho {
    Carta cartas[52];
    int indice;
}baralho;

Carta criarCarta(int numero, int naipe);
Carta virarCarta(baralho *br, int n);
int RandRange(int Min, int Max);
void imprimeCarta(Carta carta);
baralho criarBaralho();
#endif /* CARTA_H */

