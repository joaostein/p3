#ifndef ENCADEADA_H_INCLUDED
#define ENCADEADA_H_INCLUDED

typedef struct ItemPilha {
    int dados;
    struct ItemPilha *prox;
} ItemPilha;

typedef struct Pilha {
    ItemPilha *topo;
} Pilha;

// Create
Pilha *create();

// Push
void push(Pilha *p, int dado);

// Pop
int pop(Pilha *p);

// Peek
int peek(Pilha *p);

// isEmpty

int isEmpty(Pilha *p);




#endif // ENCADEADA_H_INCLUDED
