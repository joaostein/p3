#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char nome[40];
    char cpf[12];
    int idade;
    struct lista *prox;
    struct lista *ant;
} Dados;

Dados *criaLista() {
    return NULL;
}

Dados *criar(char *nome, char *cpf, int idade) {
    Dados *novo = (Dados *) malloc(sizeof(Dados));
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->idade = idade;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

Dados *inserir(Dados *lista, Dados *pessoa){
    if(lista != NULL) {
        lista->ant = pessoa;
    }

    pessoa->prox = lista;
    return pessoa;
}

void imprimir(Dados *lista) {
    Dados *aux = lista;

    while(aux != NULL) {
        puts(aux->nome);
        aux = aux->prox;
    }

}

Dados *consultar(Dados *lista, char *cpf) {
    Dados *aux = lista;

    while(aux != NULL && strcmp(cpf, aux->cpf) != 0 ) {
        aux = aux->prox;
    }

    return aux;

}

void imprimirPessoa(Dados *pessoa) {
    puts(pessoa->nome);
    puts(pessoa->cpf);
    printf("%d\n", pessoa->idade);
}

Dados *remover(Dados *lista, Dados *pessoa) {
    if(pessoa->ant == NULL) {
        Dados *aux = pessoa->prox;
        aux->ant = NULL;
        free(pessoa);
        return aux;
    } else {
        pessoa->ant->prox = pessoa->prox;

        if(pessoa->prox != NULL) {
            pessoa->prox->ant = pessoa->ant;
        }

        free(pessoa);
        return lista;
    }

}


int main() {
    Dados *lista = criaLista();

    Dados *pessoa = criar("Fulano", "01231331143", 22);
    lista = inserir(lista, pessoa);

    pessoa = criar("Fulano2", "01231332143", 22);
    lista = inserir(lista, pessoa);

    pessoa = consultar(lista, "01231331143");
    lista = remover(lista, pessoa);

    imprimir(lista);

    return 0;
}