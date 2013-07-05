#include <stdio.h>
#include <stdlib.h>


void countingSort (int *vetor, int tamanho, int k) {
    int *aux, *saida;
    int i;

    aux = malloc((k + 1) * sizeof(int));
    saida = malloc(tamanho * sizeof(int));

    for (i = 0; i <= k; i++) {
        aux[i] = 0;
    }

    for (i = 0; i < tamanho; i++) {
        aux[vetor[i]]++;
    }

    for (i = 1; i <= k; i++) {
        aux[i] = aux[i] + aux[i - 1];
    }

    for (i = tamanho - 1; i >= 0; i--) {
        saida[aux[vetor[i]] - 1] = vetor[i];
        aux[vetor[i]]--;
    }

    for (i = 0; i < tamanho; i++) {
        vetor[i] = saida[i];
    }

    free(aux);
    free(saida);
}



int main () {

    int v1[8] = { 15, 45, 55, 225, 6, 44, 90, 200 };

    countingSort(v1, 8, 225);


    return 0;
}