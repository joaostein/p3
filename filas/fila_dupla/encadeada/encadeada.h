#ifndef ENCADEADA_H_INCLUDED
#define ENCADEADA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int dados;
    struct No *prox;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

// Create

Fila *create();

// Insert
void insert(Fila *f, int elemento);

// Remove
int remover(Fila *f);

// isEmpty
int isEmpty(Fila *f);




#endif // ENCADEADA_H_INCLUDED
