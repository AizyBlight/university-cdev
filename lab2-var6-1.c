#include <stdio.h>
#include <math.h>

int main() {
    double x, Q;

    printf("Enter x: ");
    scanf("%lf", &x);

    Q = sqrt((sin(x) + cos(x)) / log(x * x + exp(-x)));

    printf("Q = %.6lf\n", Q);
}