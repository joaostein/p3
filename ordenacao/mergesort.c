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
}


int mergeSort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        merge(p, q, r, v);
    }
}


int main () {

    int v1[N] = { 15, 45, 55, 225, 6, 44, 90, 200 };

    mergeSort(0, 8, v1);


    return 0;
}