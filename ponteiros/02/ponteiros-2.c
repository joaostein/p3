#include <stdio.h>

// Escreva a função que retorna o endereço e a posição que
// ocorre a primeira vogal na string s. Caso não exista, retorna
// NULL. Protótipo: char * firstVogal(char * s).


char firstVogal(char *string) {
    int i = 0;
    char vogal;

    for(; string[i] != '\0'; i++) {
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            vogal = string[i];
            return vogal;
            break;
        }
    }
    
}


int main() {
    char string[] = "123";

    printf("%c", firstVogal(string));

    return 0;
}