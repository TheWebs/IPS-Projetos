/* 
 * File:   Data.h
 * Author: franc
 *
 * Created on 12 de Abril de 2017, 16:44
 */

#ifndef DATA_H
#define	DATA_H

typedef struct Data {
    int dia;
    int mes;
    int ano;
}Data;

//cria uma data
Data criarData(int dia, int mes, int ano);
void imprimeData(Data data);
//devolve 1 se a primeira data for mais recente 30 dias, 0 se for mais antiga
int checkData(Data data1, Data data2); 

#endif	/* DATA_H */

