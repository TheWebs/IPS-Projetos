/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   keyCode.h
 * Author: franc
 *
 * Created on May 20, 2017, 7:26 PM
 */

#ifndef KEYCODE_H
#define KEYCODE_H
#include <string.h>

typedef struct keyCode{
    char code[11];
}keyCode;

keyCode createKC(char code[11]);
#endif /* KEYCODE_H */

