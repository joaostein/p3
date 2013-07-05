#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    struct No *esq;
    struct No *dir;
    int dado;
} No;

// Create

No *create () {
    return NULL;
}

// Push

void push (No **raiz, int elemento) {
    // Lista vazia
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(No));
        (*raiz)->dado = elemento;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }

    // Árvore populada. Elemento a ser inserido menor que raiz.
    if (elemento < (*raiz)->dado) {
        push(&((*raiz)->esq), elemento);
    }

    //  Árvore populada. Elemento a ser inserido mairo que raiz.
    if (elemento > (*raiz)->dado) {
        push(&((*raiz)->dir), elemento);
    }
}

// Search

No *search (No *raiz, int elemento) {
    // Lista vazia
    if (raiz == NULL ) {
        printf("Não foi possível encontrar elemento.\n");
        return NULL;
    }

    // Árvore populada. Apenas existe um elemento que é a raiz.
    if (elemento == raiz->dado) {
        return raiz;
    }

    // Árvore populada. Elemento a ser buscado menor que raiz.
    if (elemento < raiz->dado) {
        return search(raiz->esq, elemento);
    }

    // Árvore populada. Elemento a ser buscado menor que raiz.
    if (elemento > raiz->dado) {
        return search(raiz->dir, elemento);
    }
}

// Função que encontra e retorna o menor valor de uma sub-árvore

No *menorValor (No **raiz) {
    
    No *aux = *raiz;

    // Caso não exista árvore a esquerda
    if ((*raiz)->esq == NULL) {
        *raiz = (*raiz)->dir;
        return aux;
    }

    // Caso exista árvore a esquerda com valores menores
    else {
        return menorValor(&((*raiz)->esq));
    }

}


// Função que remove de fato o nó

void removerNo (No **raiz) {
    No *pos = *raiz;

    // O nó a ser removido não tem filhos. Esquerda e direita apontam para NULL.
    if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
        *raiz = NULL;
    }

    // O nó a ser removido não tem filhos apenas a esquerda.
    else if ((*raiz)->esq == NULL) {
        *raiz = (*raiz)->dir;
    }

    // O nó a ser removido não tem filhos apenas a direita.
    else if ((*raiz)->dir == NULL) {
        *raiz = (*raiz)->esq;
    }

    // O nó a ser removido tem os dois filhos
    else {
        No *pos = menorValor(&((*raiz)->dir));
        (*raiz)->dado = pos->dado;
    }

    free(pos);

}



// Função que inicio o processo de remoção de um nó.

int remover (No **raiz, int elemento) {
    // Lista vazia ou não existe o nó
    if (*raiz == NULL) {
        printf("Não foi possível encontrar elemento.\n");
        return 0;
    }

    // Nó a ser removido é a raiz
    if (elemento == (*raiz)->dado) {
        removerNo(raiz);
        return 1;
    }

    // Nó a ser removido é menor que raiz
    if (elemento < (*raiz)->dado) {
        return remover(&((*raiz)->esq), elemento);
    }

    // Nó a ser removido é maior que raiz
    if (elemento > (*raiz)->dado) {
        return remover(&((*raiz)->dir), elemento);
    }
}



int main () {

    No *raiz = create();
    push(&raiz, 8);
    push(&raiz, 6);
    push(&raiz, 7);
    push(&raiz, 20);
    push(&raiz, 15);
    push(&raiz, 30);
    push(&raiz, 26);
    push(&raiz, 22);
    push(&raiz, 21);
    push(&raiz, 35);
    push(&raiz, 31);
    push(&raiz, 40);

    printf("================ Teste de busca ================\n");

    No *elemento = search(raiz, 40);
    if (elemento != NULL) {
        printf("Elemento buscado: %d\n", elemento->dado);
    }

    printf("================ Fim do Teste de busca ================\n");

    printf("================ Teste de remoção de elemento ================\n");
    
    printf("Antes de remover: \n");
    
    // 20
    printf("Elemento buscado: %d\n", raiz->dir->dado);
    // 15
    printf("Elemento buscado: %d\n", raiz->dir->esq->dado);
    // 30
    printf("Elemento buscado: %d\n", raiz->dir->dir->dado);
    // 26
    printf("Elemento buscado: %d\n", raiz->dir->dir->esq->dado);
    // 22
    printf("Elemento buscado: %d\n", raiz->dir->dir->esq->esq->dado);
    // 21
    printf("Elemento buscado: %d\n", raiz->dir->dir->esq->esq->esq->dado);

    remover(&raiz, 20);

    printf("Depois de remover: \n");

    // 20 -> 21
    printf("Elemento buscado: %d\n", raiz->dir->dado);
    // 15
    printf("Elemento buscado: %d\n", raiz->dir->esq->dado);
    // 30
    printf("Elemento buscado: %d\n", raiz->dir->dir->dado);
    // 35
    printf("Elemento buscado: %d\n", raiz->dir->dir->dir->dado);
    // 26
    printf("Elemento buscado: %d\n", raiz->dir->dir->esq->dado);
    // 22
    printf("Elemento buscado: %d\n", raiz->dir->dir->esq->esq->dado);
    // 20 -> Erro
    No *elemento2 = search(raiz, 20);
    if (elemento2 != NULL) {
        printf("Elemento buscado: %d\n", elemento2->dado);
    }

    printf("================ Fim do Teste de remoção ================\n");

    return 0;
}