#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"
#include "date.h"

Cache createCache(char code[11], char name[101], char state[61], char owner[101]
        , double latitude, double longitude, char kind[12]
        , char size[11], double difficulty, double terrain
        , char status[11], Date hidden_date, int founds
        , int not_founds, int favourites, int altitude) {
    Cache cache;
    strcpy(cache.code, code);
    strcpy(cache.name, name);
    strcpy(cache.state, state);
    strcpy(cache.owner, owner);
    cache.latitude = latitude;
    cache.longitude = longitude;
    strcpy(cache.kind, kind);
    strcpy(cache.size, size);
    cache.difficulty = difficulty;
    cache.terrain = terrain;
    strcpy(cache.status, status);
    cache.hidden_date = hidden_date;
    cache.founds = founds;
    cache.not_founds = not_founds;
    cache.favourites = favourites;
    cache.altitude = altitude;
    return cache;
}

void printCache(Cache cache) {
    printf("\nCodigo: %s | Nome: %s\nEstado: %s\nProprietario: %s\n"
            "Localizacao:\nDistrito: %s\nLatitude: %f | Longitude: %f\nDificuldade: %.1f "
            "| Terreno: %.1f\nTipo: %s | Tamanho: %s\nEncontradas: %d | Nao Encontradas: %d | Favoritas: %d\nEstado: %s\n\n"
            , cache.code, cache.name
            , cache.status, cache.owner
            , cache.state, cache.latitude
            , cache.longitude, cache.difficulty
            , cache.terrain, cache.kind
            , cache.size, cache.founds
            , cache.not_founds, cache.favourites
            , cache.status);
}

int isDateOneNewer(Cache date1, Cache date2)
{
    if(date1.hidden_date.ano > date2.hidden_date.ano)return 1;
    else if(date1.hidden_date.ano < date2.hidden_date.ano) return 0;
    else // --> iguais
    {
        if(date1.hidden_date.mes > date2.hidden_date.mes) return 1;
        else if(date1.hidden_date.mes < date2.hidden_date.mes) return 0;
        else // --->iguais
        {
            if(date1.hidden_date.dia > date2.hidden_date.dia)return 1;
            else if(date1.hidden_date.dia < date2.hidden_date.dia) return 0;
            else
            {
                return 2; // ----------->Datas iguais :/
            }
        }
    }
}