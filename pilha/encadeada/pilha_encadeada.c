#include <stdio.h>
#include <stdlib.h>


typedef struct ItemPilha {
    int dado;
    struct ItemPilha *prox;
} ItemPilha;

typedef struct Pilha {
    ItemPilha *topo;
} Pilha;

// Create

Pilha *create () {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

// Push

void push (Pilha *p, int elemento) {
    ItemPilha *itemPilha = malloc(sizeof(ItemPilha));
    itemPilha->dado = elemento;

    if (!isEmpty(p)) {
        itemPilha->prox = p->topo;
    }

    p->topo = itemPilha;
}

// Pop

int pop (Pilha *p) {
    if (!isEmpty(p)) {
        ItemPilha *itemPilha = p->topo;
        int dado = itemPilha->dado;
        p->topo = itemPilha->prox;
        free(itemPilha);
        return dado;
    } else {
        printf("Pilha já está vazia.\n");
    }
}

// Peek

int peek (Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia. Não há elementos no topo\n");
    } else {
        return p->topo->dado;
    }
}

// isEmpty?

int isEmpty (Pilha *p) {
    return p->topo == NULL;
}


int main () {

    Pilha *p = create();

    peek(p);

    push(p, 1);
    printf("Topo da pilha: %d\n", peek(p));
    printf("Removido elemento: %d\n", pop(p));

    push(p, 2);
    printf("Topo da pilha: %d\n", peek(p));
    printf("Removido elemento: %d\n", pop(p));

    return 0;
}