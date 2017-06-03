/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cache.h
 * Author: franc
 *
 * Created on May 20, 2017, 4:01 PM
 */

#ifndef CACHE_H
#define CACHE_H
#include "date.h"


typedef struct Cache{
    char code[11];
    char name[101];
    char state[61];
    char owner[101];
    double latitude;
    double longitude;
    char kind[12];
    char size[11];
    double difficulty;
    double terrain;
    char status[11];
    Date hidden_date;
    int founds;
    int not_founds;
    int favourites;
    int altitude;
}Cache;

Cache createCache(char code[11], char name[101], char state[61], char owner[101]
, double latitude, double longitude, char kind[11]
, char size[11], double difficulty, double terrain
, char status[11], Date hidden_date, int founds
, int not_founds, int favourites, int altitude);

void printCache(Cache cache);
int isDateOneNewer(Cache date1, Cache date2);
#endif /* CACHE_H */

