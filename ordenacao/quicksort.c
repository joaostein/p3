#include <stdio.h>
#include <stdlib.h>

#define N 8

int particao (int p, int r, int v[]) {
    int i, j, temp, pivo;
    pivo = v[r];
    j = p;

    for (i = p; i < r; i++) {
        if (v[i] < pivo) {
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
            j++;
        }
    }

    v[r] = v[j];
    v[j] = pivo;

    return j;
}


void quickSort (int p, int r, int v[]) {
    int q;

    if (p < r) {
        q = particao(p, r, v);
        quickSort(p, q - 1, v);
        quickSort(q + 1, r, v);
    }
}



int main () {

    int i;
    int v1[N] = { 15, 45, 55, 225, 6, 44, 90, 200 };

    quickSort(0, 8, v1);

    for (i = 0; i < N; i++) {
        printf("V[%d] = %d\n", i, v1[i]);
    }

    return 0;
}