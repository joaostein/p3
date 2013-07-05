#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Lista {
    int quantElementos;
    int dados[N];
} Lista;

Lista *create () {
    Lista *l = malloc(sizeof(Lista));
    l->quantElementos = 0;

    return l;
}

void add (Lista *l, int el) {
    if (l->quantElementos < N - 1) {
        l->dados[l->quantElementos] = el;
        l->quantElementos++;
    } else {
        printf("Lista está cheia.\n");
    }
}

void readAll (Lista *l) {
    int i;
    printf("======== Listando Elementos =========\n");
    for (i = 0; i < l->quantElementos; i++) {
        printf("Dados[%d] = %d\n", i, l->dados[i]);
    }
}


void delete (Lista *l, int el) {
    int i, j;

    for (i = 0; i < l->quantElementos; i++) {
        if (l->dados[i] == el) {
            for (j = i; j < l->quantElementos; j++) {
                l->dados[j] = l->dados[j + 1];
            }
            l->quantElementos--;
        }
    }
}


void update (Lista *l, int key, int el) {
    int i;
    for (i = 0; i < l->quantElementos; i++) {
        if (l->dados[i] == key) {
            l->dados[i] = el;
        }
    }
}


int search (Lista *l, int el) {
    int i;
    printf("======== Buscando Elemento =========\n");
    for (i = 0; i < l->quantElementos; i++) {
        if (l->dados[i] == el) {
            printf("Elemento %d encontrado. Na posicao dados[%d].\n", l->dados[i], i);
            return l->dados[i];
        }
    }
    printf("Elemento não encontrado.\n");
}


void bubblesort (Lista *l) {
    int i, j, aux;

    for (i = l->quantElementos - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (l->dados[j] > l->dados[j + 1]) {
                aux = l->dados[j + 1];
                l->dados[j + 1] = l->dados[j];
                l->dados[j] = aux;
            }
        }
    }
}


int main () {

    Lista *l = create();
    add(l, 7);
    add(l, 8);
    add(l, 2);
    add(l, 9);
    add(l, 3);
    add(l, 5);
    
    readAll(l);
    
    bubblesort(l);

    readAll(l);


    return 0;
}