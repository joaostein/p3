#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "sequencial.h"
#include "encadeada.h"

// 1) Conversão de um número na base decimal para a base
// binária;


int decimalParaBinario(int decimal) {
    Pilha *p = create();

    if (decimal == 0) {
        printf("0");
        return;
    }

    while(decimal != 0) {
        push(p, decimal % 2);
        decimal = decimal / 2;
    }

    while(!isEmpty(p)) {
        printf("%d", pop(p));
    }
}


int main() {
    int decimal;

    printf("\nInforme o numero: ");
    scanf("%d", &decimal);
    decimalParaBinario(decimal);

    return 0;
}
