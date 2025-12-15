#include <stdio.h>

int main() {
    double k, m, f;

    printf("Enter k and m: ");
    scanf("%lf %lf", &k, &m);

    f = (k > m / 2) ? (k * m - 4) :
        (m > k / 2) ? (k - 4 * m) :
        (m - 4);

    printf("f = %.6lf\n", f);

    return 0;
}