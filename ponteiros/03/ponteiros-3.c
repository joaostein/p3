#include <stdio.h>


// Escreva a função que apaga todos os caracteres maiusculos
// em s, usando unicamente operações entre ponteiros.
// Protótipo: char * strDelUpper(char * s). Sugestão: use a
// função isupper.


char imprimir(char *string) {
    int i = 0;
    for(; string[i] != '\0'; i++) {
        printf("%c", string[i]);
    }
}

char del(char *string) {
    int i = 0;
    int j = 0;
    char newString[50];

    for(; string[i] != '\0'; i++) {
        if(!isupper(string[i])) {
            newString[j] = string[i]; 
            j++;
        }
    }

    i = 0;

    for(; newString[i] != '\0'; i++) {
        string[i] = newString[i];
    }

    string[i] = '\0';
}


int main() {
    char string[] = "TeSte213ASSDssdwWWs";

    del(string);

    imprimir(string);

    return 0;
}