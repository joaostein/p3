#ifndef SEQUENCIAL_H_INCLUDED
#define SEQUENCIAL_H_INCLUDED
#define N 10

typedef struct Pilha {
    int dados[N];
    int topo;
} Pilha;

// create
Pilha *create();

// push (empilhar)
void push(Pilha *p, int elemento);

// pop (remove e retorna o dado)
int pop(Pilha *p);

// peek (retorna o dado do elemento no topo)
int peek(Pilha *p);

// isempty (verifica se a pilha está vazia)
int isEmpty(Pilha *p);


#endif // SEQUENCIAL_H_INCLUDED
