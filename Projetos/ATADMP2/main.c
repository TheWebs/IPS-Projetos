
/* 
 * Identificacao dos Alunos:
 * 
 *      Numero: 160221003 | Nome: Catarina Castro
 *      Numero: 160221011 | Nome: Francisco Leal
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "map.h"
#include "keyCode.h"
#include "date.h"
#include "cache.h"
#include "mapTypeElement.h"
#include <math.h>
#include "StatesList.h"




/* definicao de prototipos de funcoes, definidas depois do main() */
int equalsStringIgnoreCase(char str1[], char str2[]);
void clearList(PtList list);
Cache getFirstCache(Cache cache1, Cache cache2);
void commandLoad(PtMap ptMap, PtList list);
void commandFounds(PtMap map, PtList list);
void commandTotal(PtMap map, PtList list);
void commandDates(PtMap map, PtList list);
void commandAltitudes(PtMap map, PtList list);
void commandClosest(PtMap map, PtList list);
void commandCenter(PtMap map, PtList list);
void commandMatrix81(PtMap map, PtList list);
void commandSearch(PtMap map, PtList list);
void commandTop10(PtMap map, PtList list);
void commandStates(PtMap map, PtList list);
void printArray(Cache caches[], int size);
void sortArray(Cache array[], int size);
int isEmpty(FILE *file);
Cache* orderByLetters(Cache cache1, Cache cache2);
int goodToGo(PtList list);
void cls();

char** split(char *string, int nFields, const char *delim);

/*
 * Programa que extrai informacao util de um ficheiro de geocaches
 */

int main(int argc, char** argv) {

    /* declaracao de variaveis */
    PtMap map = mapCreate();
    PtList list = listCreate();


    /* interpretador de comandos */
    char command[21];
    int quit = 0;

    while (!quit) {
        //getchar();
        printf("GEOCACHING> ");
        fgets(command, sizeof (command), stdin);
        //scanf("%s", command);
        /* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
         * string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
        command[ strlen(command) - 1 ] = '\0';
        if (equalsStringIgnoreCase(command, "LOAD")) {
            commandLoad(map, list);
        } else if (equalsStringIgnoreCase(command, "QUIT")) {
            printf("	Programa terminado...\n\n");
            quit = 1; /* vai provocar a saída do interpretador */
        } else if (equalsStringIgnoreCase(command, "DATES")) {
            commandDates(map, list);
        } else if (equalsStringIgnoreCase(command, "FOUNDS")) {
            commandFounds(map, list);
        } else if (equalsStringIgnoreCase(command, "CENTER")) {
            commandCenter(map, list);
        } else if (equalsStringIgnoreCase(command, "MATRIX81")) {
            commandMatrix81(map, list);
        } else if (equalsStringIgnoreCase(command, "CLOSEST")) {
            commandClosest(map, list);
        } else if (equalsStringIgnoreCase(command, "SEARCH")) {
            commandSearch(map, list);
        } else if (equalsStringIgnoreCase(command, "ALTITUDES")) {
            commandAltitudes(map, list);
        } else if (equalsStringIgnoreCase(command, "STATES")) {
            commandStates(map, list);
        } else if (equalsStringIgnoreCase(command, "TOTAL")) {
            commandTotal(map, list);
        } else if (equalsStringIgnoreCase(command, "TOP10")) {
            commandTop10(map, list);
        } else if (equalsStringIgnoreCase(command, "clear")) {
            cls();
        } else {
            printf("Comando nao encontrado.\n");
        }

    }

    /* libertar memória e apresentar mensagem de saída. */

    return (EXIT_SUCCESS);
}

void cls() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif  //finish
}

int isEmpty(FILE *file) {
    long savedOffset = ftell(file);
    fseek(file, 0, SEEK_END);

    if (ftell(file) == 0) {
        return 1;
    }

    fseek(file, savedOffset, SEEK_SET);
    return 0;
}

void clearList(PtList list) {
    keyCode key;
    while (listIsEmpty(list) == 0) {
        listRemove(list, 0, &key);
        //printf("%s\n", key.code); ---> linha de debug
    }
}

int equalsStringIgnoreCase(char str1[], char str2[]) { //podia ser feito usando apenas utilizando apenas srtcasecmp em string.h (era suposto?)
    if (strlen(str1) != strlen(str2)) return 0; //so vale a pena comparar se tiverem o mesmo numero de letras
    char one[strlen(str1)];
    char two[strlen(str2)];
    strcpy(one, str1);
    strcpy(two, str2);
    for (int i = 0; i < strlen(one); i++) {
        //printf("%d\n", i); -->linha de debug
        one[i] = tolower(one[i]);
        two[i] = tolower(two[i]);
    }
    //printf("\n%s - %s\n", one, two); -->linha de debug
    return ( strcmp(one, two) == 0);
}

int relocate(int a) {
    return a * 3;
}

void printArray(Cache caches[], int size) {
    for (int i = 0; i < size; i++) {
        //printf("\n%d\n", caches[i].founds);
        printCache(caches[i]);
    }
}

void sortArray(Cache array[], int size) {
    int noChanges = 0;
    while (noChanges == 0) {
        int somethingChanged = 0;
        for (int i = 0; i < size - 1; i++) {
            if (array[i].founds > array[i + 1].founds) {
                Cache aux = array[i + 1];
                array[i + 1] = array[i];
                array[i] = aux;
                somethingChanged = 1;
            }
        }
        if (somethingChanged == 0) {
            noChanges = 1;
        }
    }
}

void commandStates(PtMap map, PtList list) {
    if(goodToGo(list) == 0)
        return;
    int size = 0;
    listSize(list, &size);
    Cache cache;
    keyCode key;
    StatesList sl = createSL(500);
    for (int i = 0; i < size; i++) {
        listGet(list, i, &key);
        mapGet(map, key, &cache);
        int index = stateExists(sl, cache.state);
        if (index != -1)
            sl.states[index].count++;
        else {
            sl.states[sl.pos] = createState(cache.state);
            sl.states[sl.pos].count++;
            sl.pos++;
        }
    }
    sortSL(sl);
    printSL(sl); //A lista esta ordenada crestente entao esta func printa do fim para o inicio (hack feio :3)

}

void commandTop10(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    int size = 0;
    listSize(list, &size);
    Cache cache;
    keyCode key;
    Cache caches[500];
    for (int i = 0; i < size; i++) {
        listGet(list, i, &key);
        mapGet(map, key, &cache);
        caches[i] = cache;
    }
    sortArray(caches, 500);
    //printArray(caches, 500); //--> debug line
    //Retirar ultimos 10 pois estao ordenados
    Cache cachesTop10[10];
    int aux = 499;
    for (int i = 0; i < 10; i++) {
        cachesTop10[i] = caches[aux];
        aux--;
        if (i > 0)
            //verificar se ha caches iguais no top10 e se houver ver qual e maior por alfabeto
            if (cachesTop10[i - 1].founds == cachesTop10[i].founds) {
                Cache *cachesOr = orderByLetters(cachesTop10[i - 1], cachesTop10[i]);
                cachesTop10[i - 1] = cachesOr[0];
                cachesTop10[i] = cachesOr[1];
            }
    }
    printArray(cachesTop10, 10); //--> debug line
}

void commandSearch(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    printf("Codigo da cache?: ");
    char codigo[11];
    fgets(codigo, sizeof (codigo), stdin);
    strtok(codigo, "\n");
    Cache cache;
    if (mapContains(map, createKC(codigo))) {
        mapGet(map, createKC(codigo), &cache);
        printCache(cache);
    } else {
        printf("Cache nao encontrada!\n");
    }
}

void commandMatrix81(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    char quadro[55][11];
    //preencher o quadro com espacos
    for (int linha = 0; linha < 49; linha++) {
        for (int vertical = 0; vertical < 11; vertical++) {
            quadro[linha][vertical] = ' ';
        }
    }
    //desenhar terrain, dificuldades + tracinhos
    //tracinhos
    for (int j = 0; j < 11; j++) {
        if (j > 1) {
            quadro[relocate(1) + 1][j] = '|';
        }
        for (int i = 0; i < 49; i++) {
            if (i >= relocate(2)) {
                quadro[i][1] = '-';
            }
        }
    }
    //terrains e dificuldades
    double numero = 1.0;
    for (int i = 0; i < 11; i++) {
        if (i > 1) {
            char a = (int) numero;
            quadro[0][i] = a + '0';
            quadro[1][i] = '.';
            a = ((numero - ((int) numero))*10) + '0';
            quadro[2][i] = a;
            numero += 0.5;
        }

    }
    numero = 1.0;
    for (int i = relocate(2); i < 49; i++) {
        char a = (int) numero;
        quadro[i][0] = a + '0';
        quadro[i + 1][0] = '.';
        a = ((numero - ((int) numero))*10) + '0';
        quadro[i + 2][0] = a;
        numero += 0.5;
        i += 4;
    }
    //fim tracinhos e dificuldade e terrains
    //preencher a zeros
    for (int j = 2; j < 11; j++) {
        for (int i = 0; i < 49; i++) {
            if (i > 5) {
                quadro[i + 2][j] = '0';
                i += 4;
            }

        }
    }
    //fim zeros
    //inserir dados no quadro     //a = 1.0; b = 1.5; c = 2.0 etc..
    int quadroI[9][9]; // = {{0}};
    //rmadeira: iniciar valores
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            quadroI[i][j] = 0;

    int size = 0;
    listSize(list, &size);
    int a = 0;
    for (int i = 0; i < size; i++) {
        int x = 0, y = 0;
        keyCode k;
        listGet(list, i, &k);
        //printf("\nCHAVE: %s", k.code);
        Cache cache;
        mapGet(map, k, &cache);
        //printCache(cache);
        if (cache.terrain == 1.0)
            x = 0;
        else if (cache.terrain == 1.5)
            x = 1;
        else if (cache.terrain == 2.0)
            x = 2;
        else if (cache.terrain == 2.5)
            x = 3;
        else if (cache.terrain == 3.0)
            x = 4;
        else if (cache.terrain == 3.5)
            x = 5;
        else if (cache.terrain == 4.0)
            x = 6;
        else if (cache.terrain == 4.5)
            x = 7;
        else if (cache.terrain == 5.0) {
            x = 8;
        }

        if (cache.difficulty == 1.0)
            y = 0;
        else if (cache.difficulty == 1.5)
            y = 1;
        else if (cache.difficulty == 2.0)
            y = 2;
        else if (cache.difficulty == 2.5)
            y = 3;
        else if (cache.difficulty == 3.0)
            y = 4;
        else if (cache.difficulty == 3.5)
            y = 5;
        else if (cache.difficulty == 4.0)
            y = 6;
        else if (cache.difficulty == 4.5)
            y = 7;
        else if (cache.difficulty == 5.0) {
            y = 8;
        }

        quadroI[x][y]++;
        //printf("\n[%d][%d] - %d\n", x, y, quadroI[x][y]);
    }
    // printf("\nA: %d\n", a);


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num[3] = {0, 0, 0};
            //rmadeira: estava quadro e nao quadroI
            itoa(quadroI[i][j], num, 10);
            //printf("Numero: %s\n", num);
            quadro[6 + (i * 5)][j + 2] = num[0];
            quadro[6 + (i * 5) + 1][j + 2] = num[1]; //RMADEIRA: estava num[0]
            quadro[6 + (i * 5) + 2][j + 2] = num[2]; //RMADEIRA: estava num[0]

        }
    }




    //fim dos dados
    //imprime quadro

    for (int vertical = 0; vertical < 11; vertical++) {
        for (int linha = 0; linha < 49; linha++) {
            printf("%c", quadro[linha][vertical]);
        }
        printf("\n");
    }

}

void commandCenter(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    double mediaLatitude = 0, mediaLongitude = 0, desvioPadraoLa = 0, desvioPadraoLo = 0;
    int size = 0;
    listSize(list, &size);
    for (int i = 0; i < size; i++) {
        keyCode k;
        listGet(list, i, &k);
        Cache cache;
        mapGet(map, k, &cache);
        mediaLatitude += cache.latitude;
        mediaLongitude += cache.longitude;
    }
    mediaLongitude = mediaLongitude / size;
    mediaLatitude = mediaLatitude / size;
    for (int i = 0; i < size; i++) {
        keyCode k;
        listGet(list, i, &k);
        Cache cache;
        mapGet(map, k, &cache);
        desvioPadraoLa += pow((cache.latitude - mediaLatitude), 2);
        desvioPadraoLo += pow((cache.longitude - mediaLongitude), 2);
    }
    desvioPadraoLa = sqrt((desvioPadraoLa/size));
    desvioPadraoLo = sqrt((desvioPadraoLo/size));

    printf("Latitude media: %.5f +/-  %.5f\nLongitude media: %.5f +/- %.5f\n"
            , mediaLatitude, desvioPadraoLa, mediaLongitude, desvioPadraoLo);
}

void commandClosest(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    int size = 0;
    int distance;
    Cache closest;
    char number[16];
    int numberI;
    printf("Altitude pretendida?: ");
    fgets(number, sizeof (number), stdin);
    sscanf(number, "%d", &numberI);
    //printf("\nNUMEROI: %d\n", numberI);  ----> linha de debug
    listSize(list, &size);
    int found = 0;
    for (int i = 0; i < size; i++) {
        keyCode k;
        listGet(list, i, &k);
        Cache cache;
        mapGet(map, k, &cache);
        int changed = 0;
        if (cache.altitude == -9999999) continue;
        else found++;
        if (found == 1) {
            closest = cache;
            distance = abs(cache.altitude - numberI);
        }
        if (cache.altitude != -9999999 && found > 1) {
            int diferenca = abs(cache.altitude - numberI);
            if (diferenca < distance) {
                closest = cache;
                distance = diferenca;
                changed = 1;
                //printf("\n\n%d\n\n", diferenca); --> linhad de debug
            }
            if(changed == 0 && diferenca == distance)
            {
                closest = getFirstCache(cache, closest);
            }
        }
    }
    printf("    Cache com altitude mais proxima:\n");
    printf("    Code: %s | Name: %s | Altitude: %d | Date: ", closest.code, closest.name, closest.altitude);
    printDate(closest.hidden_date);
}

Cache getFirstCache(Cache cache1, Cache cache2) {
    int size = 0;
    if (strlen(cache1.name) > strlen(cache2.name))
        size = strlen(cache2.name);
    else
        size = strlen(cache1.name);
    for (int i = 0; i < size; i++) {
        if (cache1.name[i] < cache2.name[i]) return cache1;
        if (cache1.name[i] > cache2.name[i]) return cache2;
    }
}

Cache *orderByLetters(Cache cache1, Cache cache2) {
    Cache *caches;
    caches = (Cache*) calloc(2, sizeof (Cache));
    caches[0] = getFirstCache(cache1, cache2);
    if (caches[0].name == cache1.name)
        caches[1] = cache2;
    else
        caches[1] = cache1;
    printArray(caches, 2);
    return caches;
}

void commandAltitudes(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    int size = 0;
    Cache highest, lowest;
    listSize(list, &size);
    for (int i = 0; i < size; i++) {
        keyCode k;
        listGet(list, i, &k);
        Cache cache;
        mapGet(map, k, &cache);
        int isHigher = 0, isLower = 0;
        if (i == 0) {
            highest = cache;
            lowest = cache;
        }
        if (cache.altitude != -9999999) {
            if (cache.altitude > highest.altitude) {
                highest = cache;
                isHigher = 1;
            }
            if (cache.altitude < lowest.altitude) {
                lowest = cache;
                isLower = 1;
            }
            if (isLower == 0 && cache.altitude == lowest.altitude)
                lowest = getFirstCache(cache, lowest);
            if (isHigher == 0 && cache.altitude == highest.altitude) {
                highest = getFirstCache(cache, highest);
            }
        }
    }
    printf("    Cache com altitude mais elevada:\n");
    printf("    Code: %s | Name: %s | Altitude: %d | Date: ", highest.code, highest.name, highest.altitude);
    printDate(highest.hidden_date);
    printf("    Cache com altitude mais baixa:\n");
    printf("    Code: %s | Name: %s | Altitude: %d | Date: ", lowest.code, lowest.name, lowest.altitude);
    printDate(lowest.hidden_date);
}

void commandDates(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    int size = 0;
    Cache newer, older;
    listSize(list, &size);
    for (int i = 0; i < size; i++) { //Obter caches uma a uma
        keyCode k;
        listGet(list, i, &k);
        Cache cache;
        mapGet(map, k, &cache);
        int isNewer = 0, isOlder = 0;
        //cache obtida, que fazer?
        if (i == 0) {
            newer = cache;
            older = cache;
        } else {
            if (isDateOneNewer(cache, newer) == 1) {
                newer = cache;
                isNewer = 1;
            }
            if (isDateOneNewer(cache, older) == 0) {
                if (cache.hidden_date.ano != 0) // -----> correcao temporaria de bug, ha pelo menos uma data por ficheiro que fica 0/0/0
                    older = cache;
                isOlder = 1;
            }
            if (isNewer == 0 && isDateOneNewer(cache, newer) == 2) {
                newer = getFirstCache(cache, newer);
            }
            if (isOlder == 0 && isDateOneNewer(cache, older) == 2) {
                newer = getFirstCache(cache, older);
            }
        }
    }
    printf("    Cache mais recente:\n");
    printf("    Code: %s | Name: %s | Altitude: %d | Date: ", newer.code, newer.name, newer.altitude);
    printDate(newer.hidden_date);
    printf("    Cache mais antiga:\n");
    printf("    Code: %s | Name: %s | Altitude: %d | Date: ", older.code, older.name, older.altitude);
    printDate(older.hidden_date);
}

void commandTotal(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    int size = 0;
    int available = 0;
    int disabled = 0;
    listSize(list, &size);
    for (int i = 0; i < size; i++) {
        keyCode k;
        listGet(list, i, &k);
        Cache cache;
        mapGet(map, k, &cache);
        if (equalsStringIgnoreCase(cache.status, "AVAILABLE")) {
            available++;
        } else {
            disabled++;
        }
    }
    printf("    Total de caches   = %d\n    Total 'Enabled'   = %d\n    Total 'Disabled'  = %d\n\n", size, available, disabled);
}

void commandFounds(PtMap map, PtList list) {
        if(goodToGo(list) == 0)
        return;
    int size = 0;
    int totalFounds = 0;
    int totalNotFounds = 0;
    listSize(list, &size);
    for (int i = 0; i < size; i++) {
        keyCode k;
        listGet(list, i, &k);
        Cache cache;
        mapGet(map, k, &cache);
        totalFounds += cache.founds;
        totalNotFounds += cache.not_founds;
    }
    printf("    Total 'Founds'     = %d\n    Total 'Not Founds' = %d\n\n", totalFounds, totalNotFounds);
}

void commandLoad(PtMap ptMap, PtList list) {
    if (mapIsEmpty(ptMap) == 0 && listIsEmpty(list) == 0) {
        mapClear(ptMap);
        clearList(list);
        printf("\n[Limpou caches]\n\n");
    }

    char file[16];
    printf("    Nome do ficheiro?: ");
    fgets(file, sizeof (file), stdin);
    fflush(stdin);
    FILE *f = fopen(file, "r");
    //verificacoes de ficheiro
    if (f == NULL) {
        printf("    Ficheiro nao existe...\n\n");
        return;
    }
    if (isEmpty(f)) {
        printf("    Ficheiro vazio!\n");
        return;
    }
    //fim
    char **tokens;
    char **data;
    char linha[500];
    int i = 0;
    while (fgets(linha, sizeof (linha), f)) {
        if (strlen(linha) <= 1) continue;
        tokens = split(linha, 16, ";");
        data = split(tokens[11], 3, "/");
        Date date = createDate(atoi(data[0]), atoi(data[1]), atoi(data[2]));
        //printDate(date);      ----->linha de debug
        Cache temp = createCache(tokens[0], tokens[1], tokens[2], tokens[3]
                , atof(tokens[4]), atof(tokens[5]), tokens[6], tokens[7]
                , atof(tokens[8]), atof(tokens[9]), tokens[10], date
                , atoi(tokens[12]), atoi(tokens[13]), atoi(tokens[14])
                , atoi(tokens[15]));
        keyCode k = createKC(temp.code);
        mapPut(ptMap, k, temp);
        //printf("\n%s\n", tokens[6]); //--->linha de debug
        listAdd(list, i, k);
        i++;
    }
    printf("    Foram importadas %d caches...\n\n", i);
    fclose(f);
}

int goodToGo(PtList list)
{
    if(listIsEmpty(list))
    {
        printf("    Nao existem caches!\n\n");
        return 0;
    }
    return 1;
}

char** split(char *string, int nFields, const char *delim) {
    char **tokens = malloc(sizeof (char*) *nFields);
    char index = 0;
    char *p = strtok(string, delim);
    while (p != NULL) {
        tokens[index++] = p;
        p = strtok(NULL, delim);
    }
    return tokens;
}

