#include <stdio.h>

void ArrayInput(int a[], int n) {
    for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

int NegativeCount(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            count++;
    return count;
}

int main() {
    int X[50], Y[70];

    printf("Enter 50 elements: \n");
    ArrayInput(X, 50);

    printf("Enter 70 elements: \n");
    ArrayInput(Y, 70);

    printf("Negative | X: %d\n", NegativeCount(X, 50));
    printf("Negative | X: %d\n", NegativeCount(Y, 70));

    return 0;
}