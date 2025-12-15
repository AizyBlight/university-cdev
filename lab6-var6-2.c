#include <stdio.h>
#include <stdlib.h>
#define N 7

int main() {
    int **A;
    int i, j, k;
    int t;

    A = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
    }

    printf("Enter elements (7x7): \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter k (1-7): ");
    scanf("%d", &k);
    k--;

    for (i = 0; i < N; i++) {
        t = A[k][i];
        A[k][i] = A [i][k];
        A[i][k] = t;
    }

    printf("\nResult: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        free(A[i]);
    }
    free (A);
    return 0;
}