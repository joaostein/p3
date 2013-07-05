#include <stdio.h>
#include <stdlib.h>

#define TAM 3


typedef struct Pilha {
    int dado[TAM];
    int topo;
} Pilha;

// Create

Pilha *create () {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

// Push (Empilha um novo elemento no topo da pilha)

void push (Pilha *p, int dado) {
    if (p->topo >= TAM - 1) {
        printf("Impossível adicionar novo elemento. A Pilha está totalmente cheia\n");
    } else {
        p->topo ++;
        p->dado[p->topo] = dado;
    }
}

// Peek (Verifica se a pilha está vazia, caso não esteja, retorna o valor do elemento que se encontra no topo)

int peek (Pilha *p) {
    if (isEmpty(p)) {
        printf("A lista está vazia, não existe elementos nela.\n");
    } else {
        int dado;
        dado = p->dado[p->topo];
        return dado;
    }
}

// Pop (Remove o elemento que está no topo da pilha)

void pop (Pilha *p) {
    if (isEmpty(p)) {
        printf("A lista está vazia, não existe elementos nela.\n");
    } else {
        p->topo --;
    }
}

// isEmpty? (Verifica se a pilha em questão encontra-se vazia)

int isEmpty (Pilha *p) {
    return p->topo == -1;
}


int main () {

    Pilha *p = create();

    push(p, 182);
    printf("topo[0]: %d\n", peek(p));
    pop(p);

    return 0;
}