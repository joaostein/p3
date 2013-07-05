#include "encadeada.h"

Fila *create() {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

void insert(Fila *f, int elemento) {
    No *no = malloc(sizeof(No));
    no->dados = elemento;
    no->prox = NULL;

    if(isEmpty(f)) {
        f->inicio = no;
    } else {
        f->fim->prox = no;
    }

    f->fim = no;
}

int remover(Fila *f) {
    No *no = f->inicio;
    int elemento = no->dados;
    f->inicio = no->prox;
    free(no);

    return elemento;
}


int isEmpty(Fila *f) {
    return f->inicio == NULL;
}