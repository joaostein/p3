#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

typedef struct Fila {
    int elemento[TAMANHO];
    int inicio, quantidadeElementos;
} Fila;

// Create (Cria a fila)

Fila *create () {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = 0;
    f->quantidadeElementos = 0;

    return f;
}

// Push (Adiciona um elemento ao final da fila - FIFO [First in, First Out])

void push (Fila *f, int elemento) {
    if (f->quantidadeElementos == TAMANHO) {
        printf("A fila está cheia. Não suporta novos elementos.\n");
    } else {
        f->elemento[(f->inicio + f->quantidadeElementos) % TAMANHO] = elemento;
        f->quantidadeElementos ++;
    }
}

// Pop (Remove o elemento que se encontra no início da fila)

int pop (Fila *f) {
    if (isEmpty(f)) {
        printf("Impossível remover elementos. A fila está vazia.\n");
    } else {
        int elemento = f->elemento[f->inicio];
        f->inicio = (f->inicio + 1) % TAMANHO;
        f->quantidadeElementos --;

        return elemento;
    }
}

// Peek (Retorna o valor que está no início da fila)

int peek (Fila *f) {
    if (isEmpty(f)) {
        printf("Impossível consultar o dado do primeiro da fila. A fila está vazia.\n");
    } else {
        return f->elemento[f->inicio];
    }
}

// isEmpty? (Verifica se a fila está vazia)

int isEmpty (Fila *f) {
    return f->quantidadeElementos == 0;
}


int main () {

    Fila *f = create();
    
    push(f, 1);
    printf("Dado consultado (Primeiro da fila): %d\n", peek(f));
    printf("Removido elemento (%d).\n", pop(f));

    return 0;
}