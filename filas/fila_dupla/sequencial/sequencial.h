#ifndef SEQUENCIAL_H_INCLUDED
#define SEQUENCIAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 25


typedef struct Fila {
    int dados[TAM];
    int inicio;
    int quantidadeElementos;
} Fila;

// Criar fila
Fila *create();

// Inserir novo elemento na fila
void insert(Fila *f, int elemento);

// Remover elemento da fila
int remover(Fila *f);

// Verificar se a fila está vazia

int isEmpty(Fila *f);


#endif // SEQUENCIAL_H_INCLUDED
