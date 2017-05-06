#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "operacoes.h"
#include "Biblioteca.h"
#include "Balcao.h"
#include "fila.h"

void analisarOperacoes(ListaOperacoes op, Data *data, ListaClientes listaClientes,
        ListaPratos listaPratos, Balcao balcao, FilasEspera filas);

int main(int argc, char** argv) {
    Balcao balcao = criarBalcao();
    FilasEspera filas;
    criarFilas(filas);
    Data data = criarData(0, 0, 0);
    ListaClientes lista = leClientesDeFicheiro();

    for (int i = 0; i < lista.contagem; i++) {
        imprimeCliente(lista.clientes[i]);
    }

    ListaPratos listaPratos = lePratosDeFicheiro();

    for (int i = 0; i < listaPratos.contagem; i++) {
        imprimePrato(listaPratos.pratos[i]);
    }

    ListaOperacoes lista2 = lerOperacoes();
    for (int i = 0; i < lista2.contagem; i++) {
        imprimeOperacao(lista2.operacoes[i]);
    }
    analisarOperacoes(lista2, &data, lista, listaPratos, balcao, filas);

    return (EXIT_SUCCESS);
}

void analisarOperacoes(ListaOperacoes op, Data *data, ListaClientes listaClientes,
        ListaPratos listaPratos, Balcao balcao, FilasEspera filas) {
    for (int i = 0; i < op.contagem; i++) {
        char** tokens;
        tokens = split(op.operacoes[i].instrucao, 3, " ");
        //rmadeira: apenas coloquei este print porque necessitava de fazer um despiste
        //ja que esta parte nao funcionava. 
        //Agora esta ok mas atenção às passagens por ref que sao necessarias em certos casos
        //toca a terminar as operacoes e a dar os outputs desejados! FORÇA
        //printf("\n%s; %s; %s; \n", tokens[0], tokens[1], tokens[2]);

        if (strcmp(tokens[0], "AD") == 0) { //////////////////////////////////////////////////////////// AD
            tokens = split(tokens[1], 3, "/");
            Data data2 = criarData(atoi(tokens[0]), atoi(tokens[1]), atoi(tokens[2]));
            (*data) = data2;
            printf("Nova data: ");
            imprimeData((*data));
            FILE *f = fopen("resultado.txt", "a");
            fprintf(f, "\nNova data: %d/%d/%d\n", data->dia, data->mes, data->ano);
            fclose(f);
        }
        if (strcmp(tokens[0], "AC") == 0) { //////////////////////////////////////////////////////////// AC
            int id = atoi(tokens[1]);
            int found = 0;
            for (int i = 0; i < listaClientes.contagem; i++) {
                if (listaClientes.clientes[i].id == id) {
                    printf("\nCliente com o id %d foi encontrado!\n", listaClientes.clientes[i].id);
                    FILE *f = fopen("resultado.txt", "a");
                    fprintf(f, "\nCliente com o id %d foi encontrado!\n", listaClientes.clientes[i].id);
                    fclose(f);
                    adicionarClienteAFila(listaClientes.clientes[i], filas);
                    atualizarBalcao(&balcao, filas);
                    imprimeCliente(listaClientes.clientes[i]);
                    found = 1;
                }
            }
            if (found == 0) {
                printf("\nNao existe nenhum cliente com esse id!\n");
                FILE *f = fopen("resultado.txt", "a");
                fprintf(f, "\nNao existe nenhum cliente com o id %d !\n", id);
                fclose(f);
            }
        }
        if (strcmp(tokens[0], "IR") == 0) //////////////////////////////////////////////////////////// IR
        {
            int found = 0;
            int id = atoi(tokens[1]);
            for (int i = 0; i < listaClientes.contagem; i++) { //BUG POR RESOLVER, CLIENTE 5 NAO EXISTE
                if (listaClientes.clientes[i].id == id) {
                    found = 1;
                }
            }
            if (found == 0) {
                printf("\nNao existe nenhum cliente com esse id!\n");
                FILE *f = fopen("resultado.txt", "a");
                fprintf(f, "\nNao existe nenhum cliente com o id %d !\n", id);
                fclose(f);
            } else {
                found = 0;
                for (int i = 0; i < 4; i++) {
                    if (balcao.clientes[i].id == -123) {
                    } else {
                        if (balcao.clientes[i].id == id) {
                            tokens = split(tokens[2], 3, "/");
                            Data data2 = criarData(atoi(tokens[0]), atoi(tokens[1]), atoi(tokens[2]));
                            Meal meal = criarMeal(data2, stackCreate(), 0);
                            queueEnqueue(balcao.clientes[i].refeicoes, meal);
                            found = 1;
                            printf("\nRefeicao iniciada para o cliente com o id %d\n", id);
                            FILE *f = fopen("resultado.txt", "a");
                            fprintf(f, "\nRefeicao iniciada para o cliente com o id %d\n", id);
                            fclose(f);
                        }
                    }
                }
                if (found == 0) {
                    printf("\nO cliente com o id %d nao se encontra ao balcao\n", id);
                    FILE *f = fopen("resultado.txt", "a");
                    fprintf(f, "\nO cliente com o id %d nao se encontra ao balcao\n", id);
                    fclose(f);
                }
            }

        }
    }
}

