#include <stdio.h>
#define N 6

int main() {
    int C[N][N];
    int i, j;
    int sum = 0;
    int count = 0;
    float avg;

    printf("Enter elements (6x6): ");
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++) {
            scanf("%d", &C[i][j]);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j || i + j == N - 1){
                sum += C[i][j];
                count++;
            }
        }
    }

    avg = (float)sum / count;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j || i + j == N - 1) {
                C[i][j] = (int)avg;
            }
        }
    }

    printf("\nResult: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}