#include "sequencial.h"

Fila *create() {
    
    Fila *f = malloc(sizeof(Fila));
    
    f->inicio = 0;
    f->quantidadeElementos = 0;

    return f;
}

void insert(Fila *f, int elemento) {
    f->dados[(f->inicio + f->quantidadeElementos) % TAM] = elemento;
    f->quantidadeElementos++;
}

int remover(Fila *f) {
    int elemento = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->quantidadeElementos--;

    return elemento;
}

int isEmpty(Fila *f) {
    return f->quantidadeElementos == 0;
}