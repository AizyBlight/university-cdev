#include <stdio.h>

void MatrixInput(int a[][9], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void MatrixOutput(int a[][9], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

void MatrixModify(int a[][9], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 1; j < c; j += 2)
            a[i][j] += a[i][0];
}

int main() {
    int A[8][9], B[7][9];

    printf("Enter elements (8x6): \n");
    MatrixInput(A, 8, 6);
    MatrixModify(A, 8, 6);
    MatrixOutput(A, 8, 6);

    printf("Enter elements (7x9): \n");
    MatrixInput(B, 7, 9);
    MatrixModify(B, 7, 9);
    MatrixOutput(B, 7, 9);

    return 0;
}