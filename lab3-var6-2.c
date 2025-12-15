#include <stdio.h>

int main() {
    int A, K;

    printf("Enter A and K: ");
    scanf("%d %d", &A, &K);

    while (K > 1 && K % A == 0) {
        K /= A;
    }

    if (K == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}