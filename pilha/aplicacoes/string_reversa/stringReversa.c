#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "sequencial.h"
#include "encadeada.h"

#define STRING_TAM 30

// 2) Implemente um programa que utiliza a estrutura de dados
// pilha para ler uma string do teclado e imprimir a string
// reversa.

void lerString(char *str){
    int i;
    printf("\nInforme a string: ");
    fgets(str, STRING_TAM - 1, stdin);
    for(i = 0; str[i]; i++) {
        if(str[i] == '\n') {
            str[i] = '\0';
        }
    }
}

void inverterString(char *str) {
    Pilha *p = create();
    int i;

    for(i = 0; i <= STRING_TAM - 1; i++) {
        if (str[i] != '\0') {
            push(p, str[i]);
        }
    }

    while(!isEmpty(p)) {
        printf("%c", pop(p));
    }
}

int main() {
    char str[STRING_TAM];
    
    lerString(str);
    inverterString(str);

    return 0;
}
