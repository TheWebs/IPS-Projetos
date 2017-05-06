#include "Biblioteca.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getNumberLines(char ficheiro[25])
{
    char linha[100];
    FILE *f = fopen(ficheiro, "r");
    if(f == NULL)
    {
        perror("");
    }
    int counter = 0;
    while(fgets(linha, sizeof(linha), f))
    {
        counter++;
    }
    fclose(f);
    printf("%d\n", counter);
    return counter;
}

char** split(char *string, int nFields, const char *delim)
{
    char **tokens = malloc(sizeof(char*) *nFields);
    char index = 0;
    char *p = strtok(string, delim);
    while(p != NULL)
    {
        tokens[index++] = p;
        p = strtok(NULL, delim);
    }
    return tokens;
}
