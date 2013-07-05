#include <stdlib.h>
#include "encadeada.h"


Pilha *create() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha *p, int dado) {
    ItemPilha *elemento = malloc(sizeof(ItemPilha));
    elemento->dados = dado;
    elemento->prox = p->topo;
    p->topo = elemento;
}

int pop(Pilha *p) {
    ItemPilha *elemento = p->topo;
    int dado = elemento->dados;
    p->topo = elemento->prox;
    free(elemento);
    return dado;
}

int peek(Pilha *p) {
    ItemPilha *elemento = p->topo;
    int dado = elemento->dados;
    return dado;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}