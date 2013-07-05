#include <stdio.h>

// Escreva uma versao da funcao strlen da biblioteca C usando
// ponteiros. A funcao strlen recebe uma string e retorna um
// número inteiro indicando o tamanho da string. OBS: NAO~
// deve usar funcoes definidas na biblioteca C, inclusive a
// própria funcao strlen. Protótipo: int tamanho(char *);

int len(char *string) {
    int i = 0;
    for(; string[i] != '\0'; i++);
    return i;
}


int main() {
    char string[] = "teste 123456";

    printf("Tamanho da string é: %i", len(string));
    return 0;
}