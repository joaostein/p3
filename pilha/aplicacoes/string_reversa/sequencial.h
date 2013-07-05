#ifndef SEQUENCIAL_H_INCLUDED
#define SEQUENCIAL_H_INCLUDED
#define N 10

typedef struct Pilha {
    char dados[N];
    int topo;
} Pilha;

// create
Pilha *create();

// push (empilhar)
void push(Pilha *p, char elemento);

// pop (remove e retorna o dado)
char pop(Pilha *p);

// peek (retorna o dado do elemento no topo)
char peek(Pilha *p);

// isempty (verifica se a pilha está vazia)
int isEmpty(Pilha *p);


#endif // SEQUENCIAL_H_INCLUDED
