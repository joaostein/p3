#include <stdio.h>
#include <stdlib.h>

#define N 8

int merge (int p, int q, int r, int v[]) {

    int i, j, k, w[r - p];
    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {

        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }

    while (i < q) {
        w[k++] = v[i++];
    }

    while (j < r) {
        w[k++] = v[j++];
    }

    for (i = p; i < r; i++) {
        v[i] = w[i - p];
    }

    for (i = 0; i < N; i++) {
        printf("V[%d] = %d\n", i, v[i]);
    }
}


int main () {

    // int v1[N] = { 2, 4, 5, 7, 1, 2, 3, 6 };
    int v1[N] = { 15, 45, 55, 225, 6, 44, 90, 200 };

    merge(0, 4, 8, v1);


    return 0;
}