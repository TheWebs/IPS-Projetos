#include "Meal.h"
#include "Prato.h"
#include "stack.h"
#include <stdio.h>



Meal criarMeal(Data data, PtStack pratos, double valor)
{
    Meal meal;
    meal.data = data;
    meal.pratos = stackCreate();
    while(stackIsEmpty(pratos) == 0)
    {
        Prato prato;
        stackPop(pratos, &prato);
        stackPush(meal.pratos, prato);
        meal.valor += prato.preco;
    }
    meal.estado = ABERTA;
    
}


void adicionarPrato(Meal meal, Prato prato)
{
    stackPush(meal.pratos, &prato);
    meal.valor += prato.preco;
}

void fecharMeal(Meal meal)
{
    meal.estado = FECHADA;
}

void imprimirMeal(Meal meal)
{
    printf("Meal:\n");
    while(stackIsEmpty(meal.pratos) == 0)
    {
        Prato prato;
        stackPop(meal.pratos, &prato);
        imprimePrato(prato);
    }
    printf("Valor: %f", meal.valor);
}