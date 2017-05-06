
#include <stdio.h>
#include <stdlib.h>

#include "Data.h"

void imprimeData(Data data)
{
    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
}

Data criarData(int dia, int mes, int ano)
{
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int checkData(Data data1, Data data2)
{
    if(data1.ano > data2.ano)
    {
        if(data1.mes > data2.mes)
        {
            if(data1.dia >= data2.dia)
            {
                return 1;
            }
        }
    }
    return 0;
}

