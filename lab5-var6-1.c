#include <stdio.h>

int main() {
    int A[12];
    int i, j;
    int max, t;

    printf("Enter 12 elements: \n");
    for (i = 0; i < 12; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 11; i++) {
        max = i;

        for (j = i + 1; j < 12; j++) {
            if (A[j] > A[max]) {
                max = j;
            }
        }

        t = A[i];
        A[i] = A[max];
        A[max] = t;
    }

    printf("Sorted array:\n");
    for (i = 0; i < 12; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}