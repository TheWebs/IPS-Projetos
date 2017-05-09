/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: franc
 *
 * Created on May 9, 2017, 1:33 AM
 */
#include "Carta.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    baralho b = criarBaralho();
    for(int i = 0; i < 52; i++)
    {
        Carta ze = virarCarta(&b, i);
        imprimeCarta(ze);
    }

    return (EXIT_SUCCESS);
}

