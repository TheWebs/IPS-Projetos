/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.h
 * Author: franc
 *
 * Created on May 20, 2017, 4:01 PM
 */

#ifndef DATE_H
#define DATE_H



typedef struct Date{
    int ano;
    int mes;
    int dia;
}Date;

Date createDate(int ano, int mes, int dia);
void printDate(Date date);



#endif /* DATE_H */

