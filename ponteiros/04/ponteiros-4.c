#include <stdio.h>

// Escreva a função que apaga em s1 a primeira ocorrência de
// s2. Protótipo: char * strDelStr(char * s1, char * s2).

char imprimir(char *string) {
    int i = 0;

    for(; string[i] != '\0'; i++) {
        printf("%c", string[i]);
    }
}

char *del(char *s1, char *s2) {
    // int i = 0;
    // int j = 0;
    // char temp[2];

    // for(; s2[i] != '\0'; i++) {
    //     for(; s1[j] != '\0'; j++) {
    //         if (s2[i] == s1[j]) {
    //             printf("aew");
    //             // temp[0] = s1[j];
    //         }
    //     }
    // }

    // temp[1] = '\0';

    // imprimir(temp);

}


int main() {
    char s1[] = "abcd";
    char s2[] = "jfga";

    del(s1, s2);
    return 0;
}