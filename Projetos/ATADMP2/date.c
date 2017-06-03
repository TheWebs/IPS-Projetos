#include "date.h"
#include <stdio.h>
#include "date.h"
#include "cache.h"

Date createDate(int ano, int mes, int dia)
{
    Date date;
    date.ano = ano;
    date.mes = mes;
    date.dia = dia;
    return date;
}

void printDate(Date date)
{
    printf("%d/%d/%d\n\n", date.ano, date.mes, date.dia);
}

