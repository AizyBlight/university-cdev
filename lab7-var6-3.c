#include <stdio.h>
#include <math.h>

double f1(double x) {
    return 1.0 / sqrt(5 - x * x * x);
}

double f2(double x) {
    return cos(5 * x);
}

double Integral(double (*f)(double), double a, double b, int N) {
    double h = (b - a) / N;
    double sum = f(a) + f(b);

    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    return sum * 3 * h / 8;
}

int main() {
    int N = 15;

    printf("Integral 1 = %.5f\n", Integral(f1, -2, 1, N));
    printf("Integral 2 = %.5f\n", Integral(f2, -2, 3, N));

    return 0;
}