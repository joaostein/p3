#include <stdlib.h>
#include "sequencial.h"

Pilha *create() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

void push(Pilha *p, int dado) {
    p->topo++;
    p->dados[p->topo] = dado;
}

int pop(Pilha *p) {
    int dado = p->dados[p->topo];
    p->topo--;
    return dado;
}

int peek(Pilha *p) {
    int dado = p->dados[p->topo];
    return dado;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}