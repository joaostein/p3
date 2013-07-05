#include <stdio.h>
#include <stdlib.h>

typedef struct ItemFila {
    int dado;
    struct ItemFila *prox;
} ItemFila;

typedef struct Fila {
    ItemFila *inicio;
    ItemFila *fim;
} Fila;


// Create

Fila *create () {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

// Push

void push (Fila *f, int elemento) {
    ItemFila *itemFila = malloc(sizeof(ItemFila));
    itemFila->dado = elemento;
    itemFila->prox = NULL;

    if (isEmpty(f)) {
        f->inicio = itemFila;
    } else {
        f->fim->prox = itemFila;
    }

    f->fim = itemFila;
}

// Pop

int pop (Fila *f) {
    if (isEmpty(f)) {
        printf("Impossível remover elementos. A fila está vazia.\n");
    } else {
        ItemFila *itemFila = f->inicio;
        int dado = itemFila->dado;
        f->inicio = itemFila->prox;
        free(itemFila);

        return dado;
    }
}

// Peek

int peek (Fila *f) {
    return f->inicio->dado;
}

// isEmpty?

int isEmpty (Fila *f) {
    return f->inicio == NULL;
}


int main () {

    Fila *f = create();

    push(f, 1);
    printf("Dado consultado (Primeiro da fila): %d\n", peek(f));
    printf("Removido elemento (%d).\n", pop(f));

    pop(f);

    return 0;
}