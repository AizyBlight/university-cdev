#include <stdio.h>

int main() {
    int A, B;
    int sum = 0;

    printf("Enter A and B: ");
    scanf("%d %d", &A, &B);

    for (int i = A; i <= B; i++) {
        if (i > 0 && i % 4 == 0){
            sum += i;
        }
    }

    printf("Sum = %d\n", sum);
    return 0;
}