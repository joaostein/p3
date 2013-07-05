#include "encadeada.h"

int main() {
    int i = 0;
    int elemento, dado, quantidadeElementos = 0;

    Fila *f = create();

    srand(time(NULL));

    do {
        elemento = rand() % 200;

        printf("\n-------\n");

        if (elemento % 2 == 0 && !isEmpty(f)) {
            printf("\nRemovendo o último elemento da fila (%d)", remover(f));
            quantidadeElementos--;
            printf("\nExistem %d dados na fila.\n", quantidadeElementos);
        } else {
            insert(f, elemento);
            printf("\nInserindo o elemento: %d na fila", elemento);
            quantidadeElementos++;
            printf("\nExistem %d dados na fila.\n", quantidadeElementos);
        }

    } while (i >= 0);

    return 0;
}