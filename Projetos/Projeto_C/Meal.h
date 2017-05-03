/* 
 * File:   Meal.h
 * Author: franc
 *
 * Created on 12 de Abril de 2017, 16:40
 */

#ifndef MEAL_H
#define	MEAL_H

#include "Data.h"
#include "stack.h"

typedef struct Meal {
    Data data;
    PtStack pratos;
    double valor;
}Meal;

Meal criarMeal(Data data, PtStack pratos, double valor);
void imprimirMeal(Meal meal);

#endif	/* MEAL_H */

