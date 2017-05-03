#include "Biblioteca.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "prato.h"

Prato criaPrato(char *nomePeca, char *corPrato, double preco, int numero){
    Prato prato;
    //prato.nomePeca = (char*)calloc(strlen(nomePeca), sizeof(char));
    //prato.corPrato = (char*)calloc(strlen(corPrato), sizeof(char));
    strcpy(prato.nomePeca, nomePeca); // copia o conteúdo do 2º p/ o 1º
    strcpy(prato.corPrato, corPrato); // copia o conteúdo do 2º p/ o 1º
    
    prato.preco = preco;
    prato.numero = numero;
    
    return prato;
}

void imprimePrato (Prato prato){
        printf("%s [%d] - prato %s (%.2f€) \n",
           prato.nomePeca, 
           prato.numero, 
           prato.corPrato, 
           prato.preco);
}

ListaPratos lePratosDeFicheiro() {
    ListaPratos lePratosDeFicheiro() {
    ListaPratos listaPratos;
    char linha[100];
    //char** tokens;
    int numeroPrato;
    double preco;
    char nomePeca[25];
    char corPrato[20];
 
    FILE *f = fopen("pratos.txt", "r");
    int contagem = getNumberLines("pratos.txt");
 
    listaPratos.pratos = (Prato*)malloc(contagem*sizeof(Prato));
    listaPratos.contagem = contagem;
    int i = 0;
    do {
        fscanf(f, "%d", &numeroPrato);
        fscanf(f, "%s", nomePeca);
        fscanf(f, "%lf", &preco);
        fscanf(f, "%s\n", corPrato);       
        listaPratos.pratos[i] = criaPrato(nomePeca, corPrato, preco, numeroPrato);
        i++;
    } while (feof(f) == 0);
   
    fclose(f);
    return listaPratos;
}
}

