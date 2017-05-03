
#ifndef PRATO_H
#define PRATO_H

typedef struct{
    char    nomePeca[30];
    char    corPrato[25];
    double  preco;
    int     numero;
}Prato;

typedef struct ListaPratos{
        int contagem;
    Prato *pratos;
}ListaPratos;

Prato criaPrato(char *nomePeca, char *corPrato, double preco, int calorias);
void imprimePrato (Prato prato);
ListaPratos lePratosDeFicheiro();


#endif /* PRATO_H */

